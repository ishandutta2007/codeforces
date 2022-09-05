#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

void run(std::istream &in, std::ostream &out) {
    size_t t, m;
    in >> t >> m;
    std::vector<int> memory(m);
    int id = 0;
    for (size_t i = 0; i < t; i++) {
        std::string command;
        in >> command;
        if (command == "alloc") {
            size_t size;
            in >> size;
            auto it = std::search_n(memory.begin(), memory.end(), size, 0);
            if (it == memory.end()) {
                out << "NULL" << std::endl;
                continue;
            }
            id++;
            std::fill_n(it, size, id);
            out << id << std::endl;
        } else if (command == "erase") {
            int id;
            in >> id;
            if (id == 0 || std::count(memory.begin(), memory.end(), id) == 0) {
                out << "ILLEGAL_ERASE_ARGUMENT" << std::endl;
            } else {
                std::replace(memory.begin(), memory.end(), id, 0);
            }
        } else {
            std::stable_partition(memory.begin(), memory.end(), [](int value) {
                return value != 0;
            });
        }
    }
}

int main() {
    run(std::cin, std::cout);
    return 0;
}