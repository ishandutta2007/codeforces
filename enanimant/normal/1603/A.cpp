/*
 * author:  ADMathNoob
 * created: 10/30/21 10:35:20
 * problem: https://codeforces.com/contest/1603/problem/A
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
    bool all_gone = true;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      bool ok = false;
      for (int j = 2; j <= min(i + 2, 100); j++) {
        if (a % j != 0) {
          ok = true;
          break;
        }
      }
      if (!ok) {
        all_gone = false;
      }
    }
    cout << (all_gone ? "YES" : "NO") << '\n';
  }
  return 0;
}