#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x, y;
    cin >> x >> y;
    vector <ll> c(6);
    for (int i = 0; i < 6; i++)
      cin >> c[i];
    vector <pair <ll, ll>> mov(6);
    mov[0] = {1, 1};
    mov[1] = {0, 1};
    mov[2] = {-1, 0};
    mov[3] = {-1, -1};
    mov[4] = {0, -1};
    mov[5] = {1, 0};
    int n = 6;
    ll ans = 2e18;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ll x1 = mov[i].first, y1 = mov[i].second;
        ll x2 = mov[j].first, y2 = mov[j].second;
        ll detmain = x1 * y2 - y1 * x2;
        ll detx = x * y2 - y * x2;
        ll dety = -(x * y1 - y * x1);
        if (detmain == 0 && (detx != 0 || dety != 0))
          continue;
        if (detmain == 0) {
          ll k = 0;
          if (x1)
            k = (x / x1);
          if (y1)
            k = (y / y1);
          if (k < 0)
            continue;
          ans = min(ans, k * c[i]);
          continue;
        }
        ll k1 = detx / detmain;
        ll k2 = dety / detmain;
        if (k1 < 0 || k2 < 0)
          continue;
        ans = min(ans, k1 * c[i] + k2 * c[j]);
      }
    }
    cout << ans << '\n';
  }
  return 0;
}