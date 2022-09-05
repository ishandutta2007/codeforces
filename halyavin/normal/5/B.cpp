#include <iostream>
#include <vector>
#include <string>

void run(std::istream &in, std::ostream &out) {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(in, line)) {
        lines.push_back(line);
    }
    size_t max_length = 0;
    for (auto& line : lines) max_length = std::max(max_length, line.length());
    bool toLeft = true;
    out << std::string(max_length + 2, '*') << std::endl;
    for (auto& line : lines) {
        size_t rest = max_length - line.length();
        size_t before = rest / 2;
        if (rest % 2 != 0 && !line.empty()) {
            if (!toLeft) before++;
            toLeft = !toLeft;
        }
        out << "*" << std::string(before, ' ') << line;
        out << std::string(rest - before, ' ') << "*" << std::endl;
    }
    out << std::string(max_length + 2, '*') << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}