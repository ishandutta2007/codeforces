#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x, y;
    cin >> x >> y;
    // 1 <= a <= x && 1 <= b <= y
    // a / b = a % b
    // a = kb + k, k < b
    // a = (b + 1) * k, b + 1 > k + 1; a > k * (k + 1)
    ll ans = 0;
    for (ll k = 1; k <= 100'000; k++) {
      if (k * (k + 1) >= x)
        break;
      ans += max(0ll, min(x / k, y + 1) - (k + 1));
    }
    cout << ans << '\n';
  }
  return 0;
}