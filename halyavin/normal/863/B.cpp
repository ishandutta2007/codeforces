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
    int n;
    in >> n;
    std::vector<int> weights(2*n);
    for (int i = 0; i < 2* n; i++) {
        in >> weights[i];
    }
    std::sort(weights.begin(), weights.end());
    int best = 10000;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = i + 1; j < 2 * n; j++) {
            int cur = 0;
            int sign = -1;
            for (int k = 0; k < 2 * n; k++) {
                if (k == i || k == j) continue;
                cur += weights[k] * sign;
                sign = -sign;
            }
            best = std::min(best, cur);
        }
    }
    out << best << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}