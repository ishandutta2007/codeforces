/*
 * author:  ADMathNoob
 * created: 01/23/22 14:21:19
 * problem: https://codeforces.com/contest/1625/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../algorithms/debug/debug.h"
#else
#define debug(...) 42
#endif

const int INF = 2e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, L, k;
  cin >> n >> L >> k;
  vector<int> x(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  x[n] = L;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, INF));
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (dp[i][j] == INF) {
        continue;
      }
      for (int r = i + 1; r <= n; r++) {
        dp[r][j + 1] = min(dp[r][j + 1], dp[i][j] + a[i] * (x[r] - x[i]));
      }
    }
  }
  int ans = INF;
  for (int take = n - k; take <= n; take++) {
    ans = min(ans, dp[n][take]);
  }
  cout << ans << '\n';
  return 0;
}