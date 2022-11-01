/*
 * author:  ADMathNoob
 * created: 12/24/21 09:35:12
 * problem: https://codeforces.com/contest/1615/problem/A
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
    int s = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      s += a;
    }
    cout << (s % n == 0 ? 0 : 1) << '\n';
  }
  return 0;
}