#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 30;
const int M = 50;

int dp[N + 1][N + 1][M + 1];

int main() {
  for (int a = 1; a <= N; ++a) {
    for (int b = 1; b <= N; ++b) {
      dp[a][b][0] = 0;
      for (int k = 1; k <= M && k <= a * b; ++k) {
        dp[a][b][k] = INT_MAX;
        if (a * b == k) {
          dp[a][b][k] = 0;
        }
        for (int x = 1; x < a; ++x) {
          for (int y = 0; y <= k && y <= x * b; ++y) {
            if (k - y <= (a - x) * b) {
              dp[a][b][k] = std::min(dp[a][b][k],
                                     dp[x][b][y] + dp[a - x][b][k - y] + b * b);
            }
          }
        }
        for (int x = 1; x < b; ++x) {
          for (int y = 0; y <= k && y <= a * x; ++y) {
            if (k - y <= a * (b - x)) {
              dp[a][b][k] = std::min(dp[a][b][k],
                                     dp[a][x][y] + dp[a][b - x][k - y] + a * a);
            }
          }
        }
      }
    }
  }
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    printf("%d\n", dp[a][b][k]);
  }
}