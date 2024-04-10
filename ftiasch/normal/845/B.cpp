#line 1 "sol.cpp"
#include <bits/stdc++.h>

void update(int &x, int a) { x = ~x ? std::min(x, a) : a; }

char s[7];
int dp[7][6 * 9 + 1];

int main() {
  scanf("%s", s);
  int zero = 3 * 9;
  memset(dp, -1, sizeof(dp));
  dp[0][zero] = 0;
  for (int i = 0; i < 6; ++i) {
    int sign = i < 3 ? 1 : -1;
    for (int j = 0; j <= 6 * 9; ++j) {
      if (~dp[i][j]) {
        update(dp[i + 1][j + sign * (s[i] - '0')], dp[i][j]);
        for (int d = 0; d < 10; ++ d) {
            update(dp[i + 1][j + sign * d], dp[i][j] + 1);
        }
      }
    }
  }
  printf("%d\n", dp[6][zero]);
}