/*
 * author:  ADMathNoob
 * created: 07/25/21 10:34:24
 * problem: https://codeforces.com/contest/1552/problem/B
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
    vector<vector<int>> a(n, vector<int>(5));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    auto Max = [&](int i, int j) {
      int b = 0;
      for (int k = 0; k < 5; k++) {
        b += (a[i][k] < a[j][k]);
      }
      return (b >= 3 ? i : j);
    };
    int ans = 0;
    for (int i = 1; i < n; i++) {
      ans = Max(ans, i);
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (ans != Max(ans, i)) {
        ok = false;
      }
    }
    cout << (ok ? ans + 1 : -1) << '\n';
  }
  return 0;
}