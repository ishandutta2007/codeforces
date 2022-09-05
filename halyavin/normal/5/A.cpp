#include <iostream>
#include <cassert>

void run(std::istream& in, std::ostream& out) {
    int64_t answer = 0;
    int users = 0;
    while (true) {
        std::string line;
        std::getline(in, line);
        if (in.fail()) break;
        assert(line.length() > 0);
        if (line[0] == '+') {
            users++;
        } else if (line[0] == '-') {
            users--;
        } else {
            size_t index = line.find(':');
            assert(index != line.npos);
            answer += users * (line.length() - index - 1);
        }
    }
    out << answer << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}