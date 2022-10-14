#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 100'000;
const int C = 26;

void update(int &x, int a) { x = std::max(x, a); }

int n, m, fail[N + 1], go[N + 1][C], dp[2][N + 1];
char s[N + 1], t[N + 1];

int main() {
  scanf("%s%s", s, t);
  n = strlen(s);
  m = strlen(t);
  go[0][t[0] - 'a'] = 1;
  fail[1] = 0;
  for (int i = 1; i < m; ++i) {
    int c = t[i] - 'a';
    fail[i + 1] = go[fail[i]][c];
    for (int d = 0; d < C; ++d) {
      go[i][d] = d == c ? i + 1 : go[fail[i]][d];
    }
  }
  for (int c = 0; c < C; ++ c) {
      go[m][c] = go[fail[m]][c];
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0] = 0;
  for (int i = 0; i < n; ++i) {
    memset(dp[(i + 1) & 1], -1, sizeof(int) * (m + 1));
    if (s[i] == '?') {
      for (int s = 0; s <= m; ++s) {
        if (~dp[i & 1][s]) {
          for (int c = 0; c < C; ++c) {
            int ns = go[s][c];
            update(dp[(i + 1) & 1][ns], dp[i & 1][s] + (ns == m));
          }
        }
      }
    } else {
      int c = s[i] - 'a';
      for (int s = 0; s <= m; ++s) {
        if (~dp[i & 1][s]) {
          int ns = go[s][c];
          update(dp[(i + 1) & 1][ns], dp[i & 1][s] + (ns == m));
        }
      }
    }
  }
  printf("%d\n", *std::max_element(dp[n & 1], dp[n & 1] + (m + 1)));
}