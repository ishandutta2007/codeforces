#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(0)->sync_with_stdio(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> xvals(n), yvals(m);
    for (int i = 0; i < n; i++) {
      cin >> xvals[i];
    }
    for (int j = 0; j < m; j++) {
      cin >> yvals[j];
    }

    long long ans = 0;

    vector<int> xcnt(n), ycnt(m);
    vector<map<int, int>> xline(n), yline(m);
    for (int i = 0; i < k; i++) {
      int x, y;
      cin >> x >> y;
      auto xt = lower_bound(begin(xvals), end(xvals), x);
      if (*xt != x) {
        int j = xt - begin(xvals);
        xcnt[j] += 1;
        ans -= xline[j][y]++;
      }
      auto yt = lower_bound(begin(yvals), end(yvals), y);
      if (*yt != y) {
        int j = yt - begin(yvals);
        ycnt[j] += 1;
        ans -= yline[j][x]++;
      }
    }

    for (int i = 0; i < n; i++) {
      ans += (long long) xcnt[i] * (xcnt[i] - 1) / 2;
    }
    for (int j = 0; j < m; j++) {
      ans += (long long) ycnt[j] * (ycnt[j] - 1) / 2;
    }
    cout << ans << '\n';
  }

  return 0;
}