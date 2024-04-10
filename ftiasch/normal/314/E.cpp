#include <bits/stdc++.h>

using u32 = uint32_t;

const int N = 100000;

int n;
char s[N + 1];
u32 dp[(N >> 1) + 1];

u32 solve() {
  if (n & 1) {
    return 0;
  }
  int knowns = 0;
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '?') {
      // dp[j] = dp[i][i - 2j]
      int j = (i + 1) >> 1;
      for (; j > 1; j -= 2) {
        dp[j] += dp[j - 1];
        dp[j - 1] += dp[j - 2];
      }
      if (j) {
        dp[j] += dp[j - 1];
      }
    } else {
      knowns++;
    }
    // for (int j = (i + 1) >> 1; j >= 0; -- j) {
    //     printf("%u%c", dp[j], " \n"[j == 0]);
    // }
  }
  if (knowns > (n >> 1)) {
    return 0;
  }
  int result = dp[n >> 1];
  for (int i = knowns; i < (n >> 1); ++i) {
    result *= 25U;
  }
  return result;
}

int main() {
  while (scanf("%d", &n) == 1) {
    scanf("%s", s);
    std::cout << solve() << std::endl;
  }
}