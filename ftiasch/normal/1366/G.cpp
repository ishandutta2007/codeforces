#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 10'000;

void update(int &x, int a) { x = ~x ? std::min(x, a) : a; }

char s[N + 1], t[N + 1];
int nxt[N], dp[N + 1][N + 1];

int main() {
  scanf("%s%s", s, t);
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    nxt[i] = -1;
    int sum = 0;
    for (int j = i; j < n; ++j) {
      sum += s[j] == '.' ? -1 : 1;
      if (sum < 0) {
        break;
      }
      if (sum == 0) {
        nxt[i] = j + 1;
        break;
      }
    }
  }
  int m = strlen(t);
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (~dp[i][j]) {
        update(dp[i + 1][j], dp[i][j] + 1);
        if (s[i] == t[j]) {
          update(dp[i + 1][j + 1], dp[i][j]);
        }
        if (~nxt[i]) {
          update(dp[nxt[i]][j], dp[i][j]);
        }
      }
    }
  }
  printf("%d\n", dp[n][m]);
}