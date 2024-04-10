#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    std::vector<int> a(n), dp(n + 1);
    for (int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    for (int i = n; i--;) {
      dp[i] = INT_MAX;
      int sum = 0;
      for (int x = 1; x <= 2; ++x) {
        sum += a[i + x - 1];
        for (int y = 0; y <= 2 && i + x + y <= n; ++y) {
          if (y || i + x == n) {
            dp[i] = std::min(dp[i], dp[i + x + y] + sum);
          }
        }
      }
    }
    printf("%d\n", dp[0]);
  }
}