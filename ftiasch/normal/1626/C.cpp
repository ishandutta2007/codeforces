#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 101;

int n, t[N], h[N];
long long dp[N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", t + i);
    }
    for (int i = 1; i <= n; ++i) {
      scanf("%d", h + i);
    }
    for (int i = 1; i <= n; ++i) {
      dp[i] = 1e18;
      int s = INT_MAX;
      for (int j = i; j >= 1; --j) {
        s = std::min(s, t[j] - h[j]);
        if (t[j - 1] <= s) {
          int l = t[i] - s;
          dp[i] = std::min(dp[i], dp[j - 1] + l * (l + 1LL) / 2);
        }
      }
    }
    printf("%lld\n", dp[n]);
  }
}