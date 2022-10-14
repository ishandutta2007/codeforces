#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 500;

int n, dp[N][N];
char s[N + 1];

int main() {
  scanf("%d%s", &n, s);
  for (int i = n; i--;) {
    dp[i][i] = 1;
    for (int j = i + 1; j < n; ++j) {
      int &result = dp[i][j] = 1 + dp[i + 1][j];
      for (int k = i + 1; k <= j; ++k) {
        result = std::min(result, dp[i][k - 1] + dp[k][j]);
        if (s[i] == s[k]) {
          result = std::min(result,
                            (i + 1 <= k - 1 ? dp[i + 1][k - 1] : 0) + dp[k][j]);
        }
      }
    }
  }
  printf("%d\n", dp[0][n - 1]);
}