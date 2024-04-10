#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

map <ll, ll> g;

vector <ll> p;

ll build(ll n) {
  if (g.find(n) != g.end())
    return g[n];
  ll res = 0;
  for (ll x : p)
    if (n % x == 0)
      res += build(n / x);
  return g[n] = res % MOD;
}

ll binp(ll a, ll p) {
  if (!p)
    return 1;
  if (p & 1)
    return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll D;
  cin >> D;
  ll n = D;
  for (ll i = 2; i * i <= D; i++) {
    if (D % i)
      continue;
    p.push_back(i);
    while (D % i == 0)
      D /= i;
  }
  if (D > 1)
    p.push_back(D);
  g[1] = 1;
  build(n);
  int q;
  cin >> q;
  while (q--) {
    ll a, b;
    cin >> a >> b;
    ll c = __gcd(a, b);
    ll val = 1;
    val = (val * g[a / c]) % MOD;
    val = (val * g[b / c]) % MOD;
    cout << val << '\n';
  }
  return 0;
}