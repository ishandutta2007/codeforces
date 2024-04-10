#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main () {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, x, y, n;
    cin >> a >> b >> x >> y >> n;
    ll ans = 1e18;
    {
      ll _a = a, _b = b, _x = x, _y = y, _n = n;
      ll val = min(_a - _x, _n);
      _a -= val, _n -= val;
      val = min(_b - _y, _n);
      _b -= val, _n -= val;
      ans = min(ans, _a * _b);
    }
    {
      ll _a = a, _b = b, _x = x, _y = y, _n = n;
      ll val = min(_b - _y, n);
      _b -= val, _n -= val;
      val = min(_a - _x, _n);
      _a -= val, _n -= val;
      ans = min(ans, _a * _b);
    }
    cout << ans << '\n';
  }
  return 0;
}