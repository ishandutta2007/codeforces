/*
 * author:  ADMathNoob
 * created: 12/12/21 10:15:53
 * problem: https://codeforces.com/contest/1591/problem/A
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
    int last = -1;
    bool ok = true;
    int ans = 1;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (i == 0) {
        ans += a;
      } else if (last == 0) {
        if (a == 0) {
          ok = false;
        } else {
          ans += a;
        }
      } else {
        ans += 5 * a;
      }
      last = a;
    }
    cout << (ok ? ans : -1) << '\n';
  }
  return 0;
}