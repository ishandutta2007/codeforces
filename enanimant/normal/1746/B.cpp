/*
 * author:  ADMathNoob
 * created: 10/15/22 10:35:11
 * problem: https://codeforces.com/contest/1746/problem/B
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
    vector<int> pref(n + 1);
    for (int i = 0; i < n; i++) {
      pref[i + 1] = pref[i] + a[i];
    }
    int ans = count(a.begin(), a.end(), 0); // delete all 0s
    for (int last0 = 0; last0 < n; last0++) {
      if (a[last0] != 0) continue;
      // keep the 0 at a[last0]
      int ones_before = pref[last0];
      int zeros_after = n - 1 - last0 - (pref[n] - pref[last0]);
      ans = min(ans, max(ones_before, zeros_after));
    }
    cout << ans << '\n';
  }
  return 0;
}