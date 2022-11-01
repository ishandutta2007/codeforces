#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

vector <ll> fact(200'001), _fact(200'001);

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
  for (int i = 1; i <= 200'000; i++)
    fact[i] = fact[i - 1] * i % MOD;
  _fact[200'000] = binp(fact[200'000], MOD - 2);
  for (int i = 199'999; i >= 1; i--)
    _fact[i] = _fact[i + 1] * (i + 1) % MOD;
}

ll cnk(ll k, ll n) {
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
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int h, w, n;
  cin >> h >> w >> n;
  vector <int> r(n), c(n);
  for (int i = 0; i < n; i++) {
    cin >> r[i] >> c[i];
    r[i]--, c[i]--;
  }
  r.push_back(h - 1), c.push_back(w - 1);
  n++;
  vector <int> p(n);
  iota(p.begin(), p.end(), 0);
  sort(p.begin(), p.end(), [&](int x, int y) {
    if (r[x] != r[y])
      return r[x] < r[y];
    return c[x] < c[y];
  });
  vector <ll> dp(n);
  for (int i = 0; i < n; i++) {
    int id = p[i];
    dp[i] = cnk(r[id], r[id] + c[id]);
    for (int j = 0; j < i; j++)
      if (r[id] >= r[p[j]] && c[id] >= c[p[j]]) {
        dp[i] -= cnk(r[id] - r[p[j]], r[id] + c[id] - r[p[j]] - c[p[j]]) * dp[j];
        dp[i] %= MOD;
      }
    dp[i] %= MOD;
    if (dp[i] < 0)
      dp[i] += MOD;
  }
  cout << dp[n - 1];
  return 0;
}