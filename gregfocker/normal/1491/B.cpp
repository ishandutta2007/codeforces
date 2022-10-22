#include <bits/stdc++.h>

using namespace std;

#define int long long
const int N = 100 + 7;
int n, u, v, a[N];

signed main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> u >> v;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
    }
    int ret = (int) 1e18;
    for (int i = 1; i <= n; i++) {
      for (int cnt = -2; cnt <= +2; cnt++) {
        int cost = abs(cnt) * v;
        int now = a[i] + cnt, ant = a[i - 1], nxt = a[i + 1];
        if (0 <= now && now <= (int) 1e6 + 1) {
          if (i >= 2 && abs(ant - now) >= 2) {
            ret = min(ret, cost);
          }
          if (i + 1 <= n && abs(nxt - now) >= 2) {
            ret = min(ret, cost);
          }
          if (i >= 2 && abs(ant - now) >= 1) {
            ret = min(ret, cost + u);
          }
          if (i + 1 <= n && abs(nxt - now) >= 1) {
            ret = min(ret, cost + u);
          }
        }
      }
    }
    cout << ret << "\n";
  }
}