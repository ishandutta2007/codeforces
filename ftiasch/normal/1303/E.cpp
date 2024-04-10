#include <bits/stdc++.h>

const int N = 400;

void update(int &x, int a) { x = std::max(x, a); }

char s[N + 1], t[N + 1];
int dp[2][N];

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    bool ok = false;
    for (int m0 = 1; m0 <= m && !ok; ++m0) {
      int m1 = m - m0;
      for (int j = 1; j <= m1; ++j) {
        dp[0][j] = -1;
      }
      dp[0][0] = 0;
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= m1; ++j) {
          dp[i + 1 & 1][j] = -1;
        }
        for (int j = 0; j <= m1; ++j) {
          if (~dp[i & 1][j]) {
            int k = dp[i & 1][j];
            update(dp[i + 1 & 1][j], k);
            if (k < m0 && s[i] == t[k]) {
              update(dp[i + 1 & 1][j], k + 1);
            }
            if (j < m1 && s[i] == t[m0 + j]) {
              update(dp[i + 1 & 1][j + 1], k);
            }
          }
        }
      }
      ok |= dp[n & 1][m1] == m0;
    }
    puts(ok ? "YES" : "NO");
  }
}