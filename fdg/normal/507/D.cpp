#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int dp[1001][101][2];

int main() {
  int n, k, mod;
  cin >> n >> k >> mod;
  dp[0][0][0] = 1;
  int pw = 1;
  for (int i = 0; i < n; ++i) {
    for (int rem = 0; rem < k; ++rem) {
      for (int was = 0; was < 2; ++was) {
        if (dp[i][rem][was]) {
          for (int d = (i == n - 1); d < 10; ++d) {
            int nrem = (rem + d * pw) % k;
            dp[i + 1][nrem][was || (nrem == 0 && d > 0)] += dp[i][rem][was];
            if (dp[i + 1][nrem][was || (nrem == 0 && d > 0)] >= mod)
              dp[i + 1][nrem][was || (nrem == 0 && d > 0)] -= mod;
          }
        }
      }
    }
    pw = (pw * 10) % k;
  }
  int ans = 0;
  for (int r = 0; r < k; ++r) {
    ans += dp[n][r][1];
    if (ans >= mod)
      ans -= mod;
  }
  cout << ans << endl;
  return 0;
}