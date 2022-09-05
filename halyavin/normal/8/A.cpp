#include <iostream>
#include <string>
#include <algorithm>

void run(std::istream& in, std::ostream& out) {
    std::string atob;
    std::string a;
    std::string b;
    in >> atob >> a >> b;
    size_t pos = atob.find(a, 0);
    if (pos != atob.npos) {
        pos = atob.find(b, pos + a.length());
    }
    bool forward = pos != atob.npos;
    std::reverse(atob.begin(), atob.end());
    pos = atob.find(a, 0);
    if (pos != atob.npos) {
        pos = atob.find(b, pos + a.length());
    }
    bool backward = pos != atob.npos;
    if (forward && backward) {
        out << "both" << std::endl;
        return;
    }
    if (forward) {
        out << "forward" << std::endl;
        return;
    }
    if (backward) {
        out << "backward" << std::endl;
        return;
    }
    out << "fantasy" << std::endl;
}

int main() {
    run(std::cin, std::cout);
    return 0;
}