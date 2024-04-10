#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll p, q;
    cin >> p >> q;
    if (p % q) {
      cout << p << '\n';
      continue;
    }
    vector<pair<ll,pair<ll,ll>>> fact;
    for (ll i = 2; i * i <= q; i++) {
      if (q % i == 0) {
        int cntp = 0, cntq = 0;
        ll c = p;
        ll x = 1, y = 1;
        while (c % i == 0) {
          cntp++;
          x *= i;
          c /= i;
        }
        while (q % i == 0) {
          cntq++;
          y *= i;
          q /= i;
        }
        fact.push_back({i, {x, y / i}});
      }
    }
    if (q != 1) {
      ll c = p;
      ll z = 1;
      while (c % q == 0) {
        z *= q;
        c /= q;
      }
      fact.push_back({q, {z, 1}});
    }
    ll ans = 0;
    for (auto &now : fact) {
      ll val = now.first, x = now.second.first, y = now.second.second;
      if (x <= y) {
        ans = p;
        break;
      }
      ans = max(ans, p / x * y);
    }
    cout << ans << '\n';
  }
  return 0;
}