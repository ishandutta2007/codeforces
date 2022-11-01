#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll MOD = 998244353;

ll binp(ll a, ll p) {
  if (p == 0) return 1;
  if (p % 2) return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

int main () {
  ll n, m;
  cin >> n >> m;
  vector <ll> d(n);
  for (int i = 0; i < n; i++)
    cin >> d[i];
  sort(d.begin(), d.end());
  vector <ll> pre(n);
  pre[0] = d[0];
  for (int i = 1; i < n; i++)
    pre[i] = (pre[i - 1] + d[i]) % MOD;
  vector <ll> a(m), b(m);
  for (int i = 0; i < m; i++)
    cin >> a[i] >> b[i];
  for (int i = 0; i < m; i++) {
    int id = upper_bound(d.begin(), d.end(), b[i] - 1) - d.begin();
    ll num = n - id;
    ll sum1 = (id ? pre[id - 1] : 0);
    ll sum0 = (pre[n - 1] - sum1 + MOD) % MOD;
    if (num < a[i]) {
      cout << "0\n";
      continue;
    }
    ll ans0 = sum0 * (num - a[i]) % MOD;
    ans0 = ans0 * binp(num, MOD - 2) % MOD;
    ll ans1 = sum1 * (num + 1 - a[i]) % MOD;
    ans1 = ans1 * binp(num + 1, MOD - 2) % MOD;
    cout << (ans0 + ans1) % MOD << '\n';
  }
  return 0;
}