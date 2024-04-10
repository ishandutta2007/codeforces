/*
 * author:  ADMathNoob
 * created: 08/29/21 10:35:09
 * problem: https://codeforces.com/contest/1556/problem/A
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
    int c, d;
    cin >> c >> d;
    if ((c + d) % 2 == 1) {
      cout << -1 << '\n';
      continue;
    }
    if (c == 0 && d == 0) {
      cout << 0 << '\n';
    } else {
      cout << (c == d ? 1 : 2) << '\n';
    }
  }
  return 0;
}