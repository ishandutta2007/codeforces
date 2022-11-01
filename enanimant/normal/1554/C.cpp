/*
 * author:  ADMathNoob
 * created: 07/30/21 10:29:11
 * problem: https://codeforces.com/contest/1554/problem/C
 */

/*
Comments about problem:

Given n and m, what's the smallest x such that (x xor n) > m?
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
    int x = 0;
    for (int b = 30; b >= 0; b--) {
      int y = x + (1 << b) - 1;
      if ((n | y) <= m) {
        x += (1 << b);
      }
    }
    cout << x << '\n';
  }
  return 0;
}