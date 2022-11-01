#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x;
    cin >> x;
    bool flag = false;
    for (ll a = 1; a * a * a < x; a++) {
      ll tmp = pow(x - a * a * a, 1.0 / 3);
      for (ll b = max(1ll, tmp - 2); b <= tmp + 2; b++)
        if (a * a * a + b * b * b == x)
          flag = true;
    }
    if (flag)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}