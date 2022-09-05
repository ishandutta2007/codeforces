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
    int q;
    in >> q;
    for (int i = 0; i < q; i++) {
        uint32_t n;
        in >> n;
        uint32_t left = 0;
        uint32_t right = 65000;
        while (right - left > 1) {
            uint32_t middle = (left + right) / 2;
            if (middle * (middle + 1) / 2 <= n) {
                left = middle;
            } else {
                right = middle;
            }
        }
        out << std::max(n - left + (left * (left - 1)) / 2, 2 * (n - std::min(n, right))) << std::endl;;
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}