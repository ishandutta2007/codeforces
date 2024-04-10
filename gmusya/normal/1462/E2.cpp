#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;
const int MAXN = 200'000;

ll fact[MAXN + 1], _fact[MAXN + 1];

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
  for (int i = 1; i <= MAXN; i++)
    fact[i] = (fact[i - 1] * i) % MOD;
  _fact[MAXN] = binp(fact[MAXN], MOD - 2);
  for (int i = MAXN - 1; i >= 1; i--)
    _fact[i] = _fact[i + 1] * (i + 1) % MOD;
}

ll cnk(ll n, ll k) {
  if (n < k || n < 0 || k < 0)
    return 0;
  ll res = fact[n];
  res *= _fact[k];
  res %= MOD;
  res *= _fact[n - k];
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
    int n, m, k;
    cin >> n >> m >> k;
    vector <int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      cnt[x]++;
    }
    for (int i = 1; i <= n; i++)
      cnt[i] += cnt[i - 1];
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= min(m, cnt[i] - cnt[i - 1]); j++) {
        ll tmp1 = cnk(cnt[i] - cnt[i - 1], j);
        ll tmp2 = cnk(cnt[i - 1] - (i - k > 0 ? cnt[i - k - 1] : 0), m - j);
        ans = (ans + tmp1 * tmp2) % MOD;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}