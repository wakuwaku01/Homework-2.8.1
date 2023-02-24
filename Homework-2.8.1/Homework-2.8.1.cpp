#include <exception>
#include <iostream>
#include <string>

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw std::runtime_error("Вы ввели слово запретной длины! До свидания");
    }
    return str.length();
}

int main() {
    setlocale(LC_ALL, "Russian");
    int forbidden_length;
    std::string str;
    std::cout << "Введите запретную длину: ";
    std::cin >> forbidden_length;

    while (true) {
        try {
            std::cout << "Введите слово: ";
            std::cin >> str;
            function(str, forbidden_length);
            std::cout << "Длина слова " << str << " равна "
                << str.length() << std::endl;
        }
        catch (const std::exception& err) {
            std::cout << err.what() << std::endl;
            break;
        }
    }
}