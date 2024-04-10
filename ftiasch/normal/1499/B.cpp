#include <bits/stdc++.h>

const int N = 100;

char s[N + 1];
bool dp[2][2][2];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s", s);
    memset(dp, 0, sizeof(dp));
    dp[0][0][0] = true;
    int n = strlen(s);
    for (int i = 0; i < n; ++i) {
      memset(dp[(i + 1) & 1], 0, sizeof(bool) * 4);
      int nv = s[i] - '0';
      for (int v = 0; v < 2; ++v) {
        for (int r = 0; r < 2; ++r) {
          dp[(i + 1) & 1][nv][0] |= dp[i & 1][v][r] && v <= nv;
          dp[(i + 1) & 1][v][1] |= dp[i & 1][v][r] && !r;
        }
      }
    }
    puts(dp[n & 1][0][0] || dp[n & 1][0][1] || dp[n & 1][1][0] || dp[n & 1][1][1] ? "YES" : "NO");
  }
}