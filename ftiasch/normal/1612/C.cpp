#include <bits/stdc++.h>

using Long = long long;

Long count(int n, int x) {
  if (x <= n) {
    return x * (x + 1LL) / 2;
  }
  x -= n;
  return n * (n + 1LL) / 2 + (n - 1LL + (n - x)) * x / 2;
}

int main() {
  std::ios::sync_with_stdio(false);
  int T;
  std::cin >> T;
  while (T--) {
    int n;
    Long limit;
    std::cin >> n >> limit;
    int low = 1;
    int high = 2 * n - 1;
    while (low < high) {
      int middle = low + ((high - low) >> 1);
      if (count(n, middle) >= limit) {
        high = middle;
      } else {
        low = middle + 1;
      }
    }
    std::cout << high << std::endl;
  }
}