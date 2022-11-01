/*
 * author:  ADMathNoob
 * created: 12/29/21 10:35:16
 * problem: https://codeforces.com/contest/1616/problem/D
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int x;
    cin >> x;
    vector<vector<int>> dp(n + 1, vector<int>(3, -1));
    dp[0][0] = 0;
    vector<int> mx(n + 1); // max(dp[i][0], dp[i][1], dp[i][2])
    // dp[i][suffix length taken]
    for (int i = 0; i < n; i++) {
      dp[i + 1][0] = mx[i];
      dp[i + 1][1] = dp[i][0] + 1;
      {
        for (int p = 0; p <= 2; p++) {
          if (i + 1 >= p + 2) {
            bool ok = true;
            for (int L = 2; L <= p + 2; L++) {
              for (int s = i + 1 - (p + 2); s + L - 1 <= i; s++) {
                int sum = 0;
                for (int k = s; k <= s + L - 1; k++) {
                  sum += a[k];
                }
                if (sum < L * x) {
                  ok = false;
                }
              }
            }
            if (ok) {
              dp[i + 1][2] = max(dp[i + 1][2], dp[i - 1][p] + 2);
            }
          }
        }
      }
      mx[i + 1] = max({dp[i + 1][0], dp[i + 1][1], dp[i + 1][2]});
    }
    cout << mx[n] << '\n';
  }
  return 0;
}