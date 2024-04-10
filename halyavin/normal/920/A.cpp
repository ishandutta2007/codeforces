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
    int t;
    in >> t;
    for (int test = 0; test < t; test++) {
        int n, k;
        in >> n >> k;
        std::vector<int> xs(k);
        for (int i = 0; i < k; i++) {
            in >> xs[i];
        }
        int ans = std::max(xs[0], n + 1 - xs.back());
        for (size_t i = 0; i + 1 < xs.size(); i++) {
            ans = std::max(ans, (xs[i + 1] - xs[i]) / 2 + 1);
        }
        out << ans << std::endl;
    }
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}