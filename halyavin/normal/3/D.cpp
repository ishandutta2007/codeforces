#include <iostream>
#include <queue>
#include <cstdint>

void run(std::istream &in, std::ostream &out) {
    std::string str;
    in >> str;
    int64_t total = 0;
    using queue = std::priority_queue<
            std::pair<int, size_t>,
            std::vector<std::pair<int, size_t>>,
            std::greater<std::pair<int, size_t>>>;
    queue pos_places;
    std::priority_queue<std::pair<int, size_t>> neg_places;
    if (str.length() % 2 != 0) {
        out << "-1" << std::endl;
        return;
    }
    int level = 0;
    for (size_t i = 0; i < str.length(); i++) {
        switch (str[i]) {
            case '(':
                level++;
                break;
            case ')':
                level--;
                break;
            case '?': {
                int open_br, closed_br;
                in >> open_br >> closed_br;
                if (open_br < closed_br) {
                    total += open_br;
                    str[i] = '(';
                    level++;
                    neg_places.emplace(closed_br - open_br, i);
                } else {
                    total += closed_br;
                    str[i] = ')';
                    level--;
                    pos_places.emplace(open_br - closed_br, i);
                }
            }
        }
        while (level < 0 && !pos_places.empty()) {
            auto place = pos_places.top();
            str[place.second] = '(';
            level += 2;
            total += place.first;
            pos_places.pop();
        }
        if (level < 0) {
            out << "-1" << std::endl;
            return;
        }
        while (2 * neg_places.size() > level) {
            neg_places.pop();
        }
    }
    while (level > 0 && !neg_places.empty()) {
        auto place = neg_places.top();
        str[place.second] = ')';
        level -= 2;
        total += place.first;
        neg_places.pop();
    }
    if (level != 0) {
        out << "-1" << std::endl;
        return;
    }
    out << total << std::endl;
    out << str << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}