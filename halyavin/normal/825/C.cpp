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
    int n; uint32_t k;
    in >> n >> k;
    std::vector<uint32_t> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    std::sort(as.begin(), as.end());
    uint32_t cur = 2 * k;
    int res = 0;
    for (uint32_t v : as) {
        while (v > cur) {
            res++;
            cur = cur * 2;
        }
        cur = std::max(cur, 2 * v);
    }
    out << res << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}