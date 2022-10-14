#include <bits/stdc++.h>

const int N = 1'000'001;

int n, a[N][2], plan[N];
std::pair<int, int> dp[N][2];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    const int inf = n + 1;
    a[0][0] = a[0][1] = -inf;
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i][0]);
      a[i][1] = -a[i][0];
    }
    dp[0][0] = dp[0][1] = {-inf, -1};
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < 2; ++j) {
        dp[i][j] = {inf, -1};
        for (int k = 0; k < 2; ++k) {
          if (a[i - 1][k] < a[i][j]) {
            dp[i][j] = std::min(dp[i][j], {dp[i - 1][k].first, k});
          }
          if (dp[i - 1][k].first < a[i][j]) {
            dp[i][j] = std::min(dp[i][j], {a[i - 1][k], k});
          }
        }
      }
    }
    if (dp[n][0].first < inf || dp[n][1].first < inf) {
      puts("YES");
      int j = dp[n][1].first < inf;
      for (int i = n; i >= 1; --i) {
        plan[i] = a[i][j];
        j = dp[i][j].second;
      }
      for (int i = 1; i <= n; ++i) {
        printf("%d%c", plan[i], " \n"[i == n]);
      }
    } else {
      puts("NO");
    }
  }
}