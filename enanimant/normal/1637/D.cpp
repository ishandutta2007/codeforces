/*
 * author:  ADMathNoob
 * created: 02/12/22 09:35:07
 * problem: https://codeforces.com/contest/1637/problem/D
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

const long long INF = 9e18;
const int A = 100;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> prefA(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      prefA[i + 1] = prefA[i] + a[i];
    }
    vector<long long> b(n);
    vector<long long> prefB(n + 1);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      prefB[i + 1] = prefB[i] + b[i];
    }
    long long base = 0;
    for (int i = 0; i < n; i++) {
      base += (n - 1) * a[i] * a[i];
      base += (n - 1) * b[i] * b[i];
    }
    vector<long long> dp(n * A + 1, INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
      vector<long long> new_dp(n * A + 1, INF);
      long long sum = prefA[i] + prefB[i];
      for (int j = 0; j + a[i] <= n * A; j++) {
        if (dp[j] == INF) continue;
        new_dp[j + a[i]] = min(new_dp[j + a[i]], dp[j] + a[i] * j + b[i] * (sum - j));
        // debug(new_dp[j + a[i]]);
      }
      for (int j = 0; j + b[i] <= n * A; j++) {
        if (dp[j] == INF) continue;
        new_dp[j + b[i]] = min(new_dp[j + b[i]], dp[j] + b[i] * j + a[i] * (sum - j));
      }
      dp = move(new_dp);
      // debug(i, dp);
    }
    long long best = *min_element(dp.begin(), dp.end());
    long long ans = base + 2LL * best;
    cout << ans << '\n';
  }
  return 0;
}