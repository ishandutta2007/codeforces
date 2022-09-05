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
    std::string s;
    in >> s;
    int ans = 6;
    for (int i = 0; i < 64; i++) {
        int count = 0;
        int l1 = 0;
        int r1 = 0;
        for (int j = 0; j < 3; j++) {
            if (((i >> j) & 1) != 0) {
                r1 += 9;
                count++;
            } else {
                l1 += s[j] - '0';
                r1 += s[j] - '0';
            }
        }
        int l2 = 0;
        int r2 = 0;
        for (int j = 3; j < 6; j++) {
            if (((i >> j) & 1) != 0) {
                r2 += 9;
                count++;
            } else {
                l2 += s[j] - '0';
                r2 += s[j] - '0';
            }
        }
        if (std::max(l1, l2) <= std::min(r1, r2)) {
            ans = std::min(ans, count);
        }
    }
    out << ans << std::endl;
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}