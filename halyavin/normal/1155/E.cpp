#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

const int p = 1'000'003;

int add32(int x, int y) {
    int res = x + y;
    if (res >= p) res -= p;
    return res;
}

int sub32(int x, int y) {
    int res = x - y;
    if (res < 0) res += p;
    return res;
}

void run(std::istream& in, std::ostream& out) {
    std::vector<int> original(11);
    for (int i = 0; i < original.size(); i++) {
        out << "? " << i << "\n";
        out.flush();
        in >> original[i];
        if (original[i] == 0) {
            out << "! " << i << "\n";
            out.flush();
            return;
        }
    }
    for (int i = original.size() - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            original[j] = sub32(original[j + 1], original[j]);
        }
    }
    for (int it = 0; it < p; it++) {
        for (int i = 1; i < original.size(); i++) {
            original[i] = add32(original[i], original[i - 1]);
        }
        if (original.back() == 0) {
            out << "! " << (it + original.size()) << "\n";
            out.flush();
            return;
        }
    }
    out << "! " << -1 << "\n";
    out.flush();
    return;
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}