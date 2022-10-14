#include <bits/stdc++.h>

namespace {
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int power_of_two(int n) {
  int k = 0;
  while (~n & 1) {
    k++, n >>= 1;
  }
  return k;
}
} // namespace

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    std::sort(a.begin(), a.end(),
              [&](int x, int y) { return power_of_two(x) > power_of_two(y); });
    int result = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        result += gcd(a[i], 2 * a[j]) > 1;
      }
    }
    printf("%d\n", result);
  }
}