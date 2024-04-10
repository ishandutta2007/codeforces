#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 400;

int n, m, a[N], dp[N][N + 1][N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int s = 0; s < n; ++s) {
    dp[s][0][s] = 0;
    for (int t = s + 1; t < n; ++t) {
      dp[s][0][t] = INT_MAX;
    }
    for (int p = 1; p <= n - s; ++p) {
      dp[s][p][s] = 0;
      for (int t = s + 1, k = s; t < n; ++t) {
        dp[s][p][t] = dp[s][p - 1][t];
        while (k + 1 < t && a[t] - a[k + 1] > dp[s][p - 1][k + 1]) {
          k++;
        }
        dp[s][p][t] = std::min(a[t] - a[k], dp[s][p - 1][k + 1]);
      }
    }
  }
  long long result = 0;
  while (m--) {
    int s, t, c, r;
    scanf("%d%d%d%d", &s, &t, &c, &r);
    s--;
    t--;
    int p = std::min(r + 1, t - s);
    result = std::max(result, 1LL * dp[s][p][t] * c);
  }
  printf("%lld\n", result);
}