#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 501;

long long dp[N][N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = n - 1; i >= 1; --i) {
    dp[i][i + 1] = 0;
    for (int j = i + 2; j <= n; ++j) {
      dp[i][j] = std::numeric_limits<long long>::max();
      for (int k = i + 1; k < j; ++k) {
        dp[i][j] = std::min(dp[i][j], dp[i][k] + dp[k][j] + i * j * k);
      }
    }
  }
  long long result = std::numeric_limits<long long>::max();
  // n - 1
  for (int k = 2; k < n; ++k) {
    result = std::min(result, dp[1][k] + dp[k][n] + 1 * n * k);
  }
  printf("%lld\n", result);
}