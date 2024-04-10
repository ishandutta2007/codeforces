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

void run(std::istream &in, std::ostream &out) {
    int tests;
    in >> tests;
    for (int t = 0; t < tests; t++) {
        int x;
        in >> x;
        if (x == 0) {
            out << 1 << " " << 1 << "\n";
            continue;
        }
        bool ans = false;
        for (int i = 1; i * i < x; i++) {
            if (x % i != 0) continue;
            int j = x / i;
            if ((i + j) % 2 != 0) continue;
            int u = (i + j) / 2;
            int v = (j - i) / 2;
            int m = u / v;
            if (u / m == v) {
                ans = true;
                out << u << " " << m << "\n";
                break;
            }
        }
        if (!ans) {
            out << -1 << "\n";
        }
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}