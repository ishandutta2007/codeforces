#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

const ll MOD = 998244353;

ll binpow(ll a, ll p) {
  if (!p)
    return 1;
  if (p & 1)
    return a * binpow(a, p - 1) % MOD;
  ll x = binpow(a, p / 2);
  return x * x % MOD;
}

int main() {
  int n;
  cin >> n;
  vector <ll> f(n + 1);
  f[1] = 1, f[2] = 1;
  for (int i = 3; i <= n; i++)
    f[i] = (f[i - 1] + f[i - 2]) % MOD;
  cout << f[n] * binpow(binpow(2, MOD - 2), n) % MOD << '\n';
  return 0;
}