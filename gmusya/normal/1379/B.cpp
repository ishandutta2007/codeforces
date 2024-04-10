#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll l, r, m;
    cin >> l >> r >> m;
    for (ll a = l; a <= r; a++) {
      ll mod = m % a;
      if (mod <= r - l && m >= a) {
        cout << a << ' ' << l + mod << ' ' << l << '\n';
        break;
      }
      mod = a - mod;
      if (mod <= r - l) {
        cout << a << ' ' << l << ' ' << l + mod << '\n';
        break;
      }
    }
  }
  return 0;
}