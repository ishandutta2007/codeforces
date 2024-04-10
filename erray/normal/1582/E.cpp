// author: erray
#include <bits/stdc++.h>
#ifdef DEBUG
#include "debug.h"
#else
#define debug(...) void(37)
#define here void(37)
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    int ANS = 0;
    while (ANS * (ANS - 1) / 2 <= n) {
      ++ANS;
    }
    ANS += 1;
    debug(ANS);
    vector<vector<long long>> dp(n + 1, vector<long long>(ANS));
    dp[n][0] = int(1e9) + 5;
    for (int i = n - 1; i >= 0; --i) {
      long long sum = 0;
      dp[i] = dp[i + 1];
      for (int j = 1; i + j <= n && j < ANS; ++j) {
        sum += a[i + j - 1];
        if (dp[i + j][j - 1] > sum) {
          dp[i][j] = max(dp[i][j], sum);
        } 
      }
    }
    debug(dp);
    int ans = 1;
    while (ans + 1 < ANS && dp[0][ans + 1]) {
      ++ans;
    }
    cout << ans << '\n';
  }
}