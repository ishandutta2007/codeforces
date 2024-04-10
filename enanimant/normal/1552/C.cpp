/*
 * author:  ADMathNoob
 * created: 07/25/21 10:34:24
 * problem: https://codeforces.com/contest/1552/problem/C
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
    vector<int> x(k), y(k);
    vector<bool> used(2 * n, false);
    for (int i = 0; i < k; i++) {
      cin >> x[i] >> y[i];
      --x[i]; --y[i];
      used[x[i]] = used[y[i]] = true;
    }
    vector<int> unused;
    for (int i = 0; i < 2 * n; i++) {
      if (!used[i]) {
        unused.push_back(i);
      }
    }
    for (int i = 0; i < n - k; i++) {
      x.push_back(unused[i]);
      y.push_back(unused[i + (n - k)]);
    }
    vector<pair<int, int>> segs;
    for (int i = 0; i < n; i++) {
      segs.push_back(minmax(x[i], y[i]));
    }
    sort(segs.begin(), segs.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
      auto [x1, y1] = segs[i];
      for (int j = i + 1; j < n; j++) {
        auto [x2, y2] = segs[j];
        if (x2 <= y1 && y1 <= y2) {
          ans += 1;
        }
      }
    }
    cout << ans << '\n';
  }
  return 0;
}