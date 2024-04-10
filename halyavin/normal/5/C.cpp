#include <iostream>
#include <vector>

void run(std::istream &in, std::ostream &out) {
    std::string str;
    in >> str;
    std::vector<size_t> pos(2 * str.length() + 1);
    std::fill(pos.begin(), pos.end(), str.npos);
    int level = str.length();
    pos[level] = 0;
    size_t max_length = 0;
    size_t max_count = 1;
    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            level++;
        } else {
            pos[level] = str.npos;
            level--;
        }
        if (pos[level] != str.npos) {
            size_t len = (i + 1) - pos[level];
            if (len > max_length) {
                max_length = len;
                max_count = 1;
            } else if (len == max_length) {
                max_count++;
            }
        } else {
            pos[level] = i + 1;
        }
    }
    out << max_length << " " << max_count << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}