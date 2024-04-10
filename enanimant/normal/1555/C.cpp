/*
 * author:  ADMathNoob
 * created: 07/30/21 14:56:41
 * problem: https://codeforces.com/contest/1555/problem/C
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 2e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int m;
    cin >> m;
    vector<vector<int>> a(2, vector<int>(m));
    vector<vector<int>> pref(2, vector<int>(m + 1));
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
        pref[i][j + 1] = pref[i][j] + a[i][j];
      }
    }
    int ans = INF;
    for (int d = 0; d < m; d++) {
      ans = min(ans, max(pref[0][m] - pref[0][d + 1], pref[1][d]));
    }
    cout << ans << '\n';
  }
  return 0;
}