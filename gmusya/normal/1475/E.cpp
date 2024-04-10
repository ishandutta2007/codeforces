#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll fact[100'000], _fact[100'000];

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
  for (int i = 1; i < 100'000; i++)
    fact[i] = fact[i - 1] * i % MOD;
  _fact[99'999] = binp(fact[99'999], MOD - 2);
  for (int i = 99'998; i >= 1; i--)
    _fact[i] = _fact[i + 1] * (i + 1) % MOD;
}

ll cnk(ll n, ll k) {
  if (n < 0 || k < 0 || n - k < 0)
    return 0;
  ll res = fact[n];
  res *= _fact[n - k];
  res %= MOD;
  res *= _fact[k];
  res %= MOD;
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++)
      cin >> a[i];
    sort(a.rbegin(), a.rend());
    int l = k - 1, r = k - 1;
    while (l >= 0 && a[l] == a[k - 1])
      l--;
    l++;
    while (r < n && a[r] == a[k - 1])
      r++;
    r--;
    cout << cnk(r - l + 1, k - l) << '\n';
  }
  return 0;
}