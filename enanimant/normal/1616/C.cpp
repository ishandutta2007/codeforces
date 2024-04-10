/*
 * author:  ADMathNoob
 * created: 12/29/21 10:35:15
 * problem: https://codeforces.com/contest/1616/problem/C
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (n == 1) {
      cout << 0 << '\n';
      continue;
    }
    int ans = n;
    for (int f = 0; f < n; f++) {
      for (int g = f + 1; g < n; g++) {
        int d = g - f;
        int moves = 0;
        for (int i = 0; i < n; i++) {
          if (d * a[f] + (a[g] - a[f]) * (i - f) != a[i] * d) {
            moves += 1;
          }
        }
        ans = min(ans, moves);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}