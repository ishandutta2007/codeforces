#include <bits/stdc++.h>

using namespace std;

int testcase(int tc) {
  int w, h;
  int xa, xb, ya, yb;
  int wa, ha;
  cin >> w >> h;
  cin >> xa >> ya >> xb >> yb;
  cin >> wa >> ha;
  const long long inf = 1e18;
  long long ans = inf;
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      int xmin = min(xa, xb);
      int xmax = max(xa, xb);
      int ymin = min(ya, yb);
      int ymax = max(ya, yb);
      int dx = max(xmin, wa) - xmin;
      int dy = max(ymin, ha) - ymin;
      if (xmax + dx <= w) {
        ans = min(ans, 1LL * dx);
      }
      if (ymax + dy <= h) {
        ans = min(ans, 1LL * dy);
      }
      ya = h - ya;
      yb = h - yb;
    }
    xa = w - xa;
    xb = w - xb;
  }
  if (ans >= inf)
    cout << -1 << '\n';
  else
    cout << ans << '\n';
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(12);
  int tnum = 1;
  cin >> tnum;
  for (int tc = 1; tc <= tnum; ++tc)
    testcase(tc);
  return 0;
}