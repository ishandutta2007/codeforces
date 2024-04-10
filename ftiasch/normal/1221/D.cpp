#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    long long dp[2][3];
    for (int x = 0; x < 3; ++x) {
      dp[0][x] = 0;
    }
    for (int i = 0, prea = 0, a, b; i < n; ++i) {
      scanf("%d%d", &a, &b);
      for (int x = 0; x < 3; ++x) {
        dp[(i + 1) & 1][x] = 1e18;
        for (int y = 0; y < 3; ++y) {
          if (prea + y != a + x) {
            dp[(i + 1) & 1][x] =
                std::min(dp[(i + 1) & 1][x], dp[i & 1][y] + x * b);
          }
        }
      }
      prea = a;
    }
    printf("%lld\n", *std::min_element(dp[n & 1], dp[n & 1] + 3));
  }
}