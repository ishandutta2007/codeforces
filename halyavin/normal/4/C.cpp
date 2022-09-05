#include <iostream>
#include <unordered_map>

void run(std::istream &in, std::ostream &out) {
    std::unordered_map<std::string, int> map;
    int requests;
    in >> requests;
    while (--requests >= 0) {
        std::string request;
        in >> request;
        auto it = map.find(request);
        if (it == map.end()) {
            map[request] = 0;
            out << "OK" << std::endl;
        } else {
            out << request << ++(it->second) << std::endl;
        }
    }
}

int main() {
    run(std::cin, std::cout);
    return 0;
}