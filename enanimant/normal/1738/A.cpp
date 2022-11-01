/*
 * author:  ADMathNoob
 * created: 09/30/22 10:35:07
 * problem: https://codeforces.com/contest/1738/problem/A
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
    vector<int> t(n);
    for (int i = 0; i < n; i++) {
      cin >> t[i];
    }
    vector<int> x, y;
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
      int b;
      cin >> b;
      mn = min(mn, b);
      if (t[i] == 0) {
        x.push_back(b);
      } else {
        y.push_back(b);
      }
    }
    sort(x.rbegin(), x.rend());
    sort(y.rbegin(), y.rend());
    long long ans = 0;
    int nx = x.size();
    int ny = y.size();
    if (nx == ny) {
      ans += accumulate(x.begin(), x.end(), 0LL);
      ans += accumulate(y.begin(), y.end(), 0LL);
      ans *= 2;
      ans -= mn;
    } else {
      if (nx > ny) {
        swap(nx, ny);
        swap(x, y);
      }
      for (int i = 0; i < nx; i++) {
        ans += 2 * x[i];
        ans += 2 * y[i];
      }
      for (int i = nx; i < ny; i++) {
        ans += y[i];
      }
    }
    cout << ans << '\n';
  }
  return 0;
}