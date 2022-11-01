/*
 * author:  ADMathNoob
 * created: 02/12/22 09:35:05
 * problem: https://codeforces.com/contest/1637/problem/B
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ans = 0;
    for (int L = 0; L < n; L++) {
      for (int R = L; R < n; R++) {
        int sz = R - L + 1;
        ans += sz;
        for (int i = L; i <= R; i++) {
          ans += (a[i] == 0);
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}