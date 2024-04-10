#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

ll fact[1'000], _fact[1'000];

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
  for (int i = 1; i <= 999; i++)
    fact[i] = fact[i - 1] * i % MOD;
  _fact[999] = binp(fact[999], MOD - 2);
  for (int i = 998; i >= 1; i--)
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
  init();
  int n;
  cin >> n;
  vector <int> cnt(10);
  for (int i = 0; i < 10; i++)
    cin >> cnt[i];
  vector <vector <ll>> dp(n + 1, vector<ll>(10));
  for (int i = cnt[9]; i <= n; i++)
    dp[i][9] = 1;
  for (int d = 8; d >= 1; d--)
    for (int i = 0; i <= n; i++)
      for (int j = cnt[d]; j <= i; j++)
        dp[i][d] = (dp[i][d] + dp[i - j][d + 1] * cnk(i, j)) % MOD;
  for (int i = 0; i <= n; i++)
    for (int j = cnt[0]; j <= i; j++)
      dp[i][0] = (dp[i][0] + dp[i - j][1] * cnk(i - 1, j)) % MOD;
  ll ans = 0;
  for (int i = 1; i <= n; i++)
    ans += dp[i][0];
  cout << ans % MOD;
  return 0;
}