#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = ll(1e9) + 7;

ll powmod(ll a, ll b) {
a%=MOD;
b%=MOD-1;
ll r = 1;
while (b) {
if (b & 1) r *= a, r %= MOD;
b /= 2;
a *= a, a %= MOD;
}
return r;
}

ll go(ll y) {
  vector<ll> prime_facs;
  ll v = y;
  for (ll p = 2; p * p <= v; p++) {
    if (v % p) continue;
    prime_facs.push_back(p);
    while(v % p == 0) v /= p;
  }
  if (v > 1) prime_facs.push_back(v);
  assert(prime_facs.size() <= 10);
  ll res = 0;
  for (int msk = 0; msk < (1 << prime_facs.size()); msk ++) {
    int sgn = 1;
    ll q = y;
    for (int i = 0; i < prime_facs.size(); i++) {
      if (!(msk & (1 << i))) continue;
      sgn *= -1;
      q /= prime_facs[i];
    }
    res += sgn * powmod(2, q-1);
    res %= MOD;
  }
  res %= MOD;
  if (res < 0) res += MOD;
  return res;
}

int main() {
  int x, y;
  cin >> x >> y;
  if (y % x != 0) {
cout << 0 << '\n';
return 0;
}
  cout << (go(y / x)%MOD) << '\n';
}