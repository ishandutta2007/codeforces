/*
 * author:  ADMathNoob
 * created: 09/06/22 10:35:04
 * problem: https://codeforces.com/contest/1726/problem/A
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

#ifdef _DEBUG
#include "../.cp/algorithms/debug/debug.h"
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, a[i] - a[(i + 1) % n]);
      if (i > 0) {
        ans = max(ans, a[i] - a[0]);
      }
      if (i < n - 1) {
        ans = max(ans, a[n - 1] - a[i]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}