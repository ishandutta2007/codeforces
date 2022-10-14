#line 1 "sol.cpp"
#include <bits/stdc++.h>

const int N = 1000;
const int M = N + N + 1;

int n, k;
char s[N + 1], dp[N + 1][M];

int main() {
  scanf("%d%d%s", &n, &k, s);
  memset(dp, 0, sizeof(dp));
  dp[0][k] = 'O';
  for (int i = 0; i < n; ++i) {
    for (int j = -k + 1; j < k; ++j) {
      if (dp[i][k + j]) {
        if (s[i] == 'L' || s[i] == '?') {
          dp[i + 1][k + j - 1] = 'L';
        }
        if (s[i] == 'D' || s[i] == '?') {
          dp[i + 1][k + j] = 'D';
        }
        if (s[i] == 'W' || s[i] == '?') {
          dp[i + 1][k + j + 1] = 'W';
        }
      }
    }
  }
  if (dp[n][k + k] || dp[n][0]) {
    for (int i = n, j = dp[n][0] ? -k : k; i--;) {
      s[i] = dp[i + 1][k + j];
      if (s[i] == 'W') {
        j--;
      } else if (s[i] == 'L') {
        j++;
      }
    }
    puts(s);
  } else {
    puts("NO");
  }
}