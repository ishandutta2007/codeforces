#include <iostream>
#include <array>
#include <algorithm>

void run(std::istream &in, std::ostream &out) {
    std::array<std::string, 8> field{};
    for (auto &row : field) in >> row;
    auto answer = std::count(field.begin(), field.end(), std::string(8, 'B'));
    if (answer == 8) {
        out << 8 << std::endl;
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (std::all_of(field.begin(), field.end(), [=](std::string &row) {
            return row[i] == 'B';
        })) {
            answer++;
        }
    }
    out << answer << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}