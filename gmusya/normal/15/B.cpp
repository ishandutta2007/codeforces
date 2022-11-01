#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, m, x1, y1, x2, y2;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    ll lenx = n - abs(x1 - x2);
    ll leny = m - abs(y1 - y2);
    ll cx1 = n - lenx, cx2 = lenx, cy1 = m - leny, cy2 = leny;
    ll s = lenx * leny;
    ll k = max(0ll, cx2 - cx1) * max(0ll, cy2 - cy1);
    cout << n * m - (2 * s - k) << '\n';
  }
  return 0;
}