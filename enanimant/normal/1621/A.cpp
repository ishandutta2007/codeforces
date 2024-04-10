/*
 * author:  ADMathNoob
 * created: 01/03/22 09:35:39
 * problem: https://codeforces.com/contest/1621/problem/A
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
    int n, k;
    cin >> n >> k;
    if (k <= (n + 1) / 2) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (k > 0 && i == j && i % 2 == 0) {
            cout << 'R';
            --k;
          } else {
            cout << '.';
          }
        }
        cout << '\n';
      }
    } else {
      cout << -1 << '\n';
    }
  }
  return 0;
}