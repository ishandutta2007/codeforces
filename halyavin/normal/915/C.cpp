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
#include <array>

void run(std::istream &in, std::ostream &out) {
    int64_t a, b;
    in >> a >> b;
    std::array<int, 10> stats = {};
    int digits = 0;
    while (a != 0) {
        stats[a % 10]++;
        digits++;
        a /= 10;
    }
    int64_t ans = 0;
    std::vector<int> digitsB;
    while (b != 0) {
        digitsB.push_back(b % 10);
        b /= 10;
    }
    if (digitsB.size() > digits) {
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < stats[i]; j++) {
                ans = ans * 10 + i;
            }
        }
        out << ans << "\n";
        return;
    }
    int64_t cur = 0;
    for (int i = digitsB.size() - 1; i >= 0; i--) {
        int best;
        for (best = digitsB[i] - 1; best >= 0; best--) {
            if (stats[best] != 0) break;
        }
        if (best > 0 || (best == 0 && cur != 0)) {
            int64_t cur2 = cur * 10 + best;
            stats[best]--;
            for (int d = 9; d >= 0; d--) {
                for (int j = 0; j < stats[d]; j++) {
                    cur2 = cur2 * 10 + d;
                }
            }
            ans = std::max(ans, cur2);
            stats[best]++;
        }
        if (stats[digitsB[i]] == 0) {
            break;
        }
        stats[digitsB[i]]--;
        cur = cur * 10 + digitsB[i];
    }
    ans = std::max(ans, cur);
    out << ans << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}