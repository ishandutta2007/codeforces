/*
 * author:  ADMathNoob
 * created: 01/03/22 09:35:41
 * problem: https://codeforces.com/contest/1621/problem/D
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

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<vector<int>> a(2 * n, vector<int>(2 * n));
    long long ans = 0;
    for (int i = 0; i < 2 * n; i++) {
      for (int j = 0; j < 2 * n; j++) {
        cin >> a[i][j];
        if (i >= n && j >= n) {
          ans += a[i][j];
        }
      }
    }
    int mn = 2e9;
    for (int i : {2 * n - 1, n}) {
      for (int j : {0, n - 1}) {
        mn = min(mn, a[i][j]);
        mn = min(mn, a[j][i]);
      }
    }
    ans += mn;
    debug(ans, mn);
    cout << ans << '\n';
  }
  return 0;
}