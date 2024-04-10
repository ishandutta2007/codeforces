#line 1 "sol.cpp"
#include <bits/stdc++.h>

void update(int &x, int a) { x = std::max(x, a); }

char s[500'001];

int main() {
  scanf("%s", s);
  std::vector<int> dp(5, -1);
  dp[0] = 0;
  for (int i = 0; s[i]; ++i) {
    if (~dp[3] && s[i] == ']') {
      update(dp[4], dp[3] + 1);
    }
    if (~dp[2]) {
      if (s[i] == ':') {
        update(dp[3], dp[2] + 1);
      }
      if (s[i] == '|') {
        update(dp[2], dp[2] + 1);
      }
    }
    if (~dp[1] && s[i] == ':') {
      update(dp[2], dp[1] + 1);
    }
    if (s[i] == '[') {
      update(dp[1], dp[0] + 1);
    }
  }
  printf("%d\n", dp[4]);
}