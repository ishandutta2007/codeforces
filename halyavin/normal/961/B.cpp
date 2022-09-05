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
    int n, k;
    in >> n >> k;
    int ans = 0;
    std::vector<int> as(n);
    for (int i = 0; i < n; i++) {
        in >> as[i];
    }
    for (int i = 0; i < n; i++) {
        int t;
        in >> t;
        if (t == 1) {
            ans += as[i];
            as[i] = 0;
        }
    }
    int sum = std::accumulate(as.begin(), as.begin() + k, 0);
    int maxSum = sum;
    for (int i = 1; i + k <= n; i++) {
        sum += as[i + k - 1] - as[i - 1];
        maxSum = std::max(maxSum, sum);
    }
    out << ans + maxSum << "\n";
}

int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}