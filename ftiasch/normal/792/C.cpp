#line 1 "sol.cpp"
#include <bits/stdc++.h>

void update(int &x, int a) { x = std::max(x, a); }

const int N = 100'000;

char s[N + 1];
int dp[N + 1][2][3];

int main() {
  scanf("%s", s);
  memset(dp, -1, sizeof(dp));
  int n = strlen(s);
  dp[n][0][0] = 0;
  bool has_zero = false;
  for (int i = n; i--;) {
    int d = s[i] - '0';
    has_zero |= !d;
    for (int ld = 0; ld < 2; ++ld) {
      for (int r = 0; r < 3; ++r) {
        if (~dp[i + 1][ld][r]) {
          update(dp[i][ld][r], dp[i + 1][ld][r]);
          update(dp[i][!!d][(r + d) % 3], 1 + dp[i + 1][ld][r]);
        }
      }
    }
  }
  if (has_zero && 1 >= dp[0][1][0]) {
    puts("0");
  } else if (~dp[0][1][0]) {
    for (int i = 0, ld = 1, r = 0; i < n; ++i) {
      if (dp[i][ld][r] != dp[i + 1][ld][r]) {
        putchar(s[i]);
        int nr = (r + 9 - (s[i] - '0')) % 3;
        ld = dp[i][ld][r] == dp[i + 1][1][nr] + 1;
        r = nr;
      }
    }
    puts("");
  } else {
    puts("-1");
  }
}