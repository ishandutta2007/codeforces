#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, pct;
    scanf("%d%d", &n, &pct);
    long long sum = 0, min_x = 0;
    for (int i = 0, a; i < n; ++i) {
      scanf("%d", &a);
      if (sum > 0) {
        // a / (sum + x) <= pct / 100
        // a * 100 <= pct * (sum + x)
        min_x = std::max(min_x, (a * 100LL + pct - 1) / pct - sum);
      }
      sum += a;
    }
    printf("%lld\n", min_x);
  }
}