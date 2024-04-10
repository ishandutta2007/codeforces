#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

ll binp(ll a, ll p) {
  if (!p)
    return 1;
  if (p % 2)
    return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

vector <ll> fact(4e5), _fact(4e5);

ll cnk(ll n, ll k) {
  if (n < 0 || k < 0 || n < k)
    return 0;
  ll res = fact[n];
  res = res * _fact[k] % MOD;
  res = res * _fact[n - k] % MOD;
  return res;
}

int main() {
  int n;
  cin >> n;
  fact[0] = _fact[0] = 1;
  for (int i = 1; i <= 2 * n; i++)
    fact[i] = fact[i - 1] * i % MOD;
  _fact[2 * n] = binp(fact[2 * n], MOD - 2);
  for (int i = 2 * n - 1; i >= 1; i--)
    _fact[i] = _fact[i + 1] * (i + 1) % MOD;
  vector <ll> a(n + n);
  for (int i = 0; i < n + n; i++)
    cin >> a[i];
  sort(a.begin(), a.end());
  ll sum = 0;
  for (int i = 0; i < n; i++)
    sum -= a[i];
  for (int i = 0; i < n; i++)
    sum += a[i + n];
  sum %= MOD;
  cout << cnk(n + n, n) * sum % MOD;
  return 0;
}