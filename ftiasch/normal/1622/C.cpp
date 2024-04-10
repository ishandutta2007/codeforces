#include <bits/stdc++.h>

const int N = 200'000;

int n, a[N];
long long lim;

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%lld", &n, &lim);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    std::sort(a, a + n);
    long long result = std::max(std::accumulate(a, a + n, 0LL) - lim, 0LL),
              sum = 0;
    for (int i = 1; i < n; ++i) {
      sum += a[i - 1];
      // (n - i) sets
      // sum - x + (n - i) * (a[0] - x) <= lim
      // sum + (n - i) * a[0] - lim <= (n - i + 1) * x
      int k = n - i + 1;
      long long b = sum + 1LL * (n - i) * a[0] - lim;
      if (b < 0) {
        result = std::min(result, static_cast<long long>(n - i));
      } else {
        result = std::min(result, (b + k - 1) / k + (n - i));
      }
    }
    printf("%lld\n", result);
  }
}