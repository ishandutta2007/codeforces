#include <iostream>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll fact[200'000], _fact[200'000];

ll binp(ll a, ll p) {
  if (!p)
    return 1;
  if (p & 1)
    return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

void init() {
  fact[0] = _fact[0] = 1;
  for (int i = 1; i <= 199'999; i++)
    fact[i] = fact[i - 1] * i % MOD;
  _fact[199'999] = binp(fact[199'999], MOD - 2);
  for (int i = 199'998; i >= 1; i--)
    _fact[i] = _fact[i + 1] * (i + 1) % MOD;
}

ll cnk(ll n, ll k) {
  if (n < 0 || k < 0 || n - k < 0)
    return 0;
  ll res = fact[n];
  res *= _fact[k];
  res %= MOD;
  res *= _fact[n - k];
  res %= MOD;
  return res;
}

int main() {
  init();
  int n;
  cin >> n;
  cout << (2 * cnk(n * 2 - 1, n) - n) % MOD;
  return 0;
}