#include <bits/stdc++.h>

const int N = 100'000;

int n, c[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", c + i);
    }
    int cnt[2] = {0, 0}, min[2] = {INT_MAX, INT_MAX};
    long long sum[2] = {0, 0}, result = 1e18;
    for (int i = 0; i < n; ++i) {
      cnt[i & 1]++;
      min[i & 1] = std::min(min[i & 1], c[i]);
      sum[i & 1] += c[i];
      if (i >= 1) {
        result =
            std::min(result, sum[0] + sum[1] + 1LL * (n - cnt[0]) * min[0] +
                                 1LL * (n - cnt[1]) * min[1]);
      }
    }
    printf("%lld\n", result);
  }
}