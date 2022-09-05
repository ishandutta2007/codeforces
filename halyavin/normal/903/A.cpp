#ifdef __GNUC__
#pragma GCC target("sse4,avx")
#endif
#include <immintrin.h>
#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <cstdint>
#include <numeric>

void run(std::istream& in, std::ostream& out) {
    int n;
    in >> n;
    for (int i = 0; i < n; i++) {
        int x;
        in >> x;

        bool good = false;
        for (int i = 0; i <= x; i += 3) {
            if ((x - i) % 7 == 0) {
                good = true;
                break;
            }
        }
        if (good) {
            out << "YES\n";
        } else {
            out << "NO\n";
        }
    }
}

int main() {
    std::cin.sync_with_stdio(false);
    std::cin.tie(nullptr);
    run(std::cin, std::cout);
    return 0;
}