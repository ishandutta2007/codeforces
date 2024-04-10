/*
 * author:  ADMathNoob
 * created: 09/12/21 10:35:16
 * problem: https://codeforces.com/contest/1566/problem/C
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
    string a, b;
    cin >> a >> b;
    int beg = 0;
    int ans = 0;
    while (beg < n) {
      if (a[beg] != b[beg]) {
        ans += 2;
        ++beg;
        continue;
      }
      int end = beg;
      while (end < n && a[end] == b[end]) {
        ++end;
      }
      bool has0 = false, has1 = false;
      for (int i = beg; i < end; i++) {
        if (a[i] == '1') {
          if (has0) {
            ans += 2;
            has0 = false;
          } else {
            has1 = true;
          }
        } else {
          if (has1) {
            ans += 2;
            has1 = false;
          } else {
            if (has0) {
              ans += 1;
            }
            has0 = true;
          }
        }
      }
      if (has0) {
        ans += 1;
      }
      beg = end;
    }
    cout << ans << '\n';
  }
  return 0;
}