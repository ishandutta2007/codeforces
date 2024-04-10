#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

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
  int n;
  cin >> n;
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  ll obr100 = binp(100, MOD - 2);
  for (int i = 0; i < n; i++)
    a[i] = (a[i] * obr100) % MOD;
  ll chisl = 0;
  ll znam = 1;
  for (int i = 0; i < n; i++) {
    chisl = (chisl + znam) % MOD;
    znam = (znam * a[i]) % MOD;
  }
  znam = binp(znam, MOD - 2);
  cout << chisl * znam % MOD;
  return 0;
}