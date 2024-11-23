// ConsoleApplication6.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

union Items {
    struct {
        char material[25];
        double ves;
    } A;
    struct {
        char material[25];
        double visota;
        double shirina;
        double depth;
    } B;
};

struct Item {
    int number;
    char group;
    Items items;
};

void vivod_ot_group(const Item& items) {
    std::cout << "Инвентарный номер: " << items.number << " Группа: " << items.group;
    if (items.group == 'A') {
        std::cout << " Материал: " << items.items.A.material << " Вес: " << items.items.A.ves << std::endl;
    }
    else if (items.group == 'B') {
        std::cout << " Материал: " << items.items.B.material << " Высота: " << items.items.B.visota << " Ширина: " << items.items.B.shirina << " Глубина: " << items.items.B.depth << std::endl;
    }
}

int filter(const Item* items, int kolvo_items, Item* filter_items, double max_ves) {
    int kolvo_filter_items = 0;
    for (int i = 0; i < kolvo_items; i++) {
        if (items[i].group == 'A' && std::strncmp(items[i].items.A.material, "Дерево", 6) == 0 && items[i].items.A.ves <= max_ves) {
            filter_items[kolvo_filter_items++] = items[i];
        }
    }
    return kolvo_filter_items;
}

int main() {
    setlocale(0, "RU");

    const int kolvo_max_items = 100;
    Item items[kolvo_max_items];
    int kolvo_items = 0;

    char vvod[20];
    while (true) {
        std::cout << "Введите инвентарный номер (no - конец): ";
        std::cin >> vvod;
        if (std::strcmp(vvod, "no") == 0) {
            break;
        }
        items[kolvo_items].number = std::atoi(vvod);

        std::cout << "Введите группу (A или B): ";
        std::cin >> items[kolvo_items].group;

        if (items[kolvo_items].group == 'A') {
            std::cout << "Введите материал: ";
            std::cin >> items[kolvo_items].items.A.material;
            std::cout << "Введите вес материала: ";
            std::cin >> items[kolvo_items].items.A.ves;
        }
        else if (items[kolvo_items].group == 'B') {
            std::cout << "Введите материал: ";
            std::cin >> items[kolvo_items].items.B.material;
            std::cout << "Введите высоту изделия: ";
            std::cin >> items[kolvo_items].items.B.visota;
            std::cout << "Введите ширину изделия: ";
            std::cin >> items[kolvo_items].items.B.shirina;
            std::cout << "Введите глубину изделия: ";
            std::cin >> items[kolvo_items].items.B.depth;
        }

        kolvo_items++;
    }

    double max_ves;
    std::cout << "Введите максимальный вес группы А: ";
    std::cin >> max_ves;

    Item filter_items[kolvo_max_items];
    int dlya_vivoda = filter(items, kolvo_items, filter_items, max_ves);

    std::cout << "Отфильтрованные изделия:" << std::endl;
    for (int i = 0; i < dlya_vivoda; ++i) {
        vivod_ot_group(filter_items[i]);
    }

    return 0;
}

