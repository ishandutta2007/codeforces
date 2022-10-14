#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    long long n, k, result = 0;
    std::cin >> n >> k;
    while (n) {
      if (n % k == 0) {
        n /= k;
        result++;
      } else {
        long long r = n % k;
        n -= r;
        result += r;
      }
    }
    std::cout << result << "\n";
  }
}