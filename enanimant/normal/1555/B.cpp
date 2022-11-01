/*
 * author:  ADMathNoob
 * created: 07/30/21 14:56:40
 * problem: https://codeforces.com/contest/1555/problem/B
 */

/*
Comments about problem:


*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tt;
  cin >> tt;
  while (tt--) {
    int X, Y;
    cin >> X >> Y;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int w, h;
    cin >> w >> h;
    int ans = INF;
    if (dx + w <= X) {
      ans = min(ans, max(w - x1, 0));
      ans = min(ans, max(w - (X - x2), 0));
    }
    if (dy + h <= Y) {
      ans = min(ans, max(h - y1, 0));
      ans = min(ans, max(h - (Y - y2), 0));
    }
    cout << (ans < INF ? ans : -1) << '\n';
  }
  return 0;
}