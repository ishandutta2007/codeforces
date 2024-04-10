/*
 * author:  ADMathNoob
 * created: 07/16/22 07:35:12
 * problem: https://codeforces.com/contest/1707/problem/A
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    auto Works = [&](int suf) {
      int iq = q;
      for (int i = suf; i < n; i++) {
        if (iq == 0) return false;
        if (a[i] > iq) {
          iq -= 1;
        }
      }
      return true;
    };
    int low = 0;
    int high = n;
    while (low < high) {
      int mid = (low + high) / 2;
      if (Works(mid)) {
        high = mid;
      } else {
        low = mid + 1;
      }
    }
    string ans(n, '0');
    for (int i = low; i < n; i++) {
      ans[i] = '1';
    }
    for (int i = 0; i < low; i++) {
      if (a[i] <= q) {
        ans[i] = '1';
      }
    }
    cout << ans << '\n';
  }
  return 0;
}