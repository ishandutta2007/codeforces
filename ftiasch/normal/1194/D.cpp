#line 1 "sol.cpp"
// #include "debug.h"

#include <bits/stdc++.h>

bool solve(int k, int n) {
  if (k % 3 != 0) {
    return n % 3 == 0;
  }
  if (n % (k + 1) == k) {
    return 0;
  }
  return n % (k + 1) % 3 == 0;
}

int main() {
  //   const int N = 100;
  //   for (int k = 3; k <= 20; ++k) {
  //     std::vector<int> dp(N);
  //     dp[0] = true;
  //     for (int n = 1; n < N; ++n) {
  //       dp[n] = dp[n - 1] || n >= 2 && dp[n - 2] || n >= k && dp[n - k] ?
  //       false
  //                                                                       :
  //                                                                       true;
  //       assert(dp[n] == solve(k, n));
  //     }
  //   }
  int T;
  scanf("%d", &T);
  while (T--) {
    int n, k;
    scanf("%d%d", &n, &k);
    puts(solve(k, n) ? "Bob" : "Alice");
  }
}