#include <bits/stdc++.h>

const int N = 100000;

char s[N + 1];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    int n = strlen(s);
    int dp[2][4];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; ++i) {
      for (int mask = 0; mask < 4; ++mask) {
        dp[i + 1 & 1][mask] = n;
      }
      for (int mask = 0; mask < 8; ++mask) {
        bool ok = true;
        if (i >= 1 && (mask & 6) == 0) {
          ok &= s[i - 1] != s[i];
        }
        if (i >= 2 && (mask & 5) == 0) {
          ok &= s[i - 2] != s[i];
        }
        if (ok) {
          dp[i + 1 & 1][mask >> 1] = std::min(
              dp[i + 1 & 1][mask >> 1], dp[i & 1][mask & 3] + (mask >> 2));
        }
      }
    }
    printf("%d\n", *std::min_element(dp[n & 1], dp[n & 1] + 4));
  }
}