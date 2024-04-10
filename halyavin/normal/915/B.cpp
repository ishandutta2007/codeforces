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
#include <cstdlib>

void run(std::istream &in, std::ostream &out) {
    int n, pos, l, r;
    in >> n >> pos >> l >> r;
    int val1 = 0;
    int cur = pos;
    if (r != n) {
        val1 += std::abs(cur - r) + 1;
        cur = r;
    }
    if (l != 1) {
        val1 += std::abs(cur - l) + 1;
    }
    int val2 = 0;
    cur = pos;
    if (l != 1) {
        val2 += std::abs(cur - l) + 1;
        cur = l;
    }
    if (r != n) {
        val2 += std::abs(cur - r) + 1;
    }
    out << std::min(val1, val2) << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}