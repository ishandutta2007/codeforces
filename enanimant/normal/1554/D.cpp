/*
 * author:  ADMathNoob
 * created: 07/30/21 08:52:25
 * problem: https://codeforces.com/contest/1554/problem/D
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
    if (n == 1) {
      for (int d = 0; d < n; d++) {
        cout << (char) ('a' + d);
      }
      cout << '\n';
      continue;
    }
    int half = n / 2;
    string res = string(half - 1, 'a') + 'b' + string(half, 'a');
    if (n % 2 == 1) {
      res += 'c';
    }
    cout << res << '\n';
  }
  return 0;
}