#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

vector <ll> fact(1001), _fact(1001);

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
  for (int i = 1; i <= 1000; i++)
    fact[i] = fact[i - 1] * i % MOD;
  _fact[1000] = binp(fact[1000], MOD - 2);
  for (int i = 999; i >= 1; i--)
    _fact[i] = _fact[i + 1] * (i + 1) % MOD;
}

ll cnk(ll n, ll k) {
  if (n < 0 || k < 0 || n - k < 0)
    return 0;
  ll res = fact[n];
  res = res * _fact[k] % MOD;
  res = res * _fact[n - k] % MOD;
  return res;
}

int main() {
  init();
  int n, x, pos;
  cin >> n >> x >> pos;
  x--;
  int l = 0;
  int r = n;
  int cnt0 = 0, cnt1 = 0;
  while (l < r) {
    int m = (l + r) / 2;
    if (pos >= m) {
      if (pos != m)
        cnt0++;
      l = m + 1;
    } else {
      cnt1++;
      r = m;
    }
  }
  int ost = n - cnt0 - cnt1 - 1;
  ll ans = fact[ost];
  ans *= cnk(x, cnt0);
  ans %= MOD;
  ans *= fact[cnt0];
  ans %= MOD;
  ans *= cnk(n - x - 1, cnt1);
  ans %= MOD;
  ans *= fact[cnt1];
  ans %= MOD;
  cout << ans;
  return 0;
}