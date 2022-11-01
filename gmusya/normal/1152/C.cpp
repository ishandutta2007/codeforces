#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

int main () {
  ll a, b;
  cin >> a >> b;
  if (a > b)
    swap(a, b);
  if (a == b) {
    cout << 0;
    return 0;
  }
  vector <ll> g;
  for (int i = 1; i * i <= b - a; i++) {
    if ((b - a) % i == 0) {
      g.push_back(i);
      if (i * i != b - a)
        g.push_back((b - a) / i);
    }
  }
  sort(g.begin(), g.end());
  ll nok = 1e18, ans = 1e18;
  for (ll val : g) {
    if (a % val != b % val)
      continue;
    if (a % val == 0) {
      if ((a * b) / __gcd(a, b) < nok)
        nok = (a * b) / __gcd(a, b), ans = 0;
      continue;
    }
    ll na = (val - a % val + a);
    ll nb = (val - b % val + b);
    if ((na * nb) / __gcd(na, nb) < nok)
      nok = (na * nb) / __gcd(na, nb), ans = val - a % val;
  }
  cout << ans;
  return 0;
}