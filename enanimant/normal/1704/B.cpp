/*
 * author:  ADMathNoob
 * created: 07/31/22 07:05:05
 * problem: https://codeforces.com/contest/1704/problem/B
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
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int beg = 0;
    int ans = 0;
    while (beg < n) {
      ans += 1;
      int end = beg;
      int mn = a[beg], mx = a[beg];
      while (end < n && max(mx, a[end]) - min(mn, a[end]) <= 2 * x) {
        mn = min(mn, a[end]);
        mx = max(mx, a[end]);
        ++end;
      }
      beg = end;
    }
    cout << ans - 1 << '\n';
  }
  return 0;
}