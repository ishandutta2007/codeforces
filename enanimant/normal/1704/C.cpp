/*
 * author:  ADMathNoob
 * created: 07/31/22 07:05:06
 * problem: https://codeforces.com/contest/1704/problem/C
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
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; i++) {
      cin >> a[i];
      --a[i];
    }
    sort(a.begin(), a.end());
    vector<int> d(m);
    for (int i = 0; i < m - 1; i++) {
      d[i] = a[i + 1] - a[i] - 1;
    }
    d[m - 1] = a[0] - a[m - 1] + n - 1;
    sort(d.rbegin(), d.rend());
    // debug(d);
    int ans = 0;
    int t = 0;
    for (int i = 0; i < m; i++) {
      int k = d[i] - 2 * t;
      if (k <= 0) {
        break;
      }
      if (k <= 2) {
        ans += 1;
        t += 1;
      } else {
        ans += k - 1;
        t += 2;
      }
    }
    cout << n - ans << '\n';
  }
  return 0;
}