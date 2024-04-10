/*
 * author:  ADMathNoob
 * created: 10/17/21 07:05:21
 * problem: https://codeforces.com/contest/1586/problem/B
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
    vector<bool> used(n, false);
    for (int i = 0; i < m; i++) {
      int x, y, z;
      cin >> x >> y >> z;
      --x; --y; --z;
      used[y] = true;
    }
    int mid = -1;
    for (int i = 0; i < n; i++) {
      if (!used[i]) {
        mid = i;
      }
    }
    for (int i = 0; i < n; i++) {
      if (i != mid) {
        cout << i + 1 << ' ' << mid + 1 << '\n';
      }
    }
  }
  return 0;
}