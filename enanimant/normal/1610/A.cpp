/*
 * author:  ADMathNoob
 * created: 11/23/21 09:35:08
 * problem: https://codeforces.com/contest/1610/problem/A
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
    int n, m;
    cin >> n >> m;
    if (n < m) {
      swap(n, m);
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    if (m == 1) {
      cout << 1 << '\n';
      continue;
    }
    cout << 2 << '\n';
  }
  return 0;
}