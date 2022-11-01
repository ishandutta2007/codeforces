#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

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
  ll k;
  cin >> n >> k;
  vector <ll> c(n);
  c[0] = 1;
  for (int i = 1; i < n; i++) {
    c[i] = c[i - 1];
    c[i] *= (k + i - 1);
    c[i] %= MOD;
    c[i] *= binp(i, MOD - 2);
    c[i] %= MOD;
  }
  vector <ll> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  vector <ll> s(n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= i; j++)
      s[i] = (s[i] + a[j] * c[i - j]) % MOD;
  for (auto &now : s)
    cout << now << ' ';
  return 0;
}