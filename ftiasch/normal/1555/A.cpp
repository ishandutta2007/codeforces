#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    long long n;
    std::cin >> n;
    long long result = std::numeric_limits<long long>::max();
    for (int x = 0; x < 20; ++x) {
      for (int y = 0; y < 15; ++y) {
        long long z = (std::max(n - 6 * x - 8 * y, 0LL) + 9) / 10;
        assert(6 * x + 8 * y + 10 * z >= n);
        result = std::min(result, 15 * x + 20 * y + 25 * z);
      }
    }
    std::cout << result << "\n";
  }
}