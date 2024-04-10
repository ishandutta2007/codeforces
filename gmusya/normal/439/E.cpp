#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;

using namespace std;

const ll MOD = 1e9 + 7;
const ll MAXN = 1e5 + 1;

vector <ll> fact, _fact;
vector <vector <int>> fac;
vector <int> sign;

ll binp(ll a, ll p) {
  if (!p)
    return 1;
  if (p & 1)
    return a * binp(a, p - 1) % MOD;
  ll x = binp(a, (p >> 1));
  return x * x % MOD;
}

void init() {
  fact.resize(MAXN), _fact.resize(MAXN);
  fact[0] = _fact[0] = 1;
  for (int i = 1; i < MAXN; i++)
    fact[i] = (fact[i - 1] * i) % MOD;
  _fact[MAXN - 1] = binp(fact[MAXN - 1], MOD - 2);
  for (int i = MAXN - 2; i >= 1; i--)
    _fact[i] = _fact[i + 1] * (i + 1) % MOD;
  fac.resize(MAXN);
  for (int i = 1; i < MAXN; i++)
    for (int j = i; j < MAXN; j += i)
      fac[j].push_back(i);
  sign.resize(MAXN);
  for (int i = 1; i < MAXN; i++)
    sign[i] = i > 1 ? i / fac[i][1] % fac[i][1] ? - sign[i / fac[i][1]] : 0 : 1;
}

ll cnk(ll n, ll k) {
  if (n < 0 || k < 0 || n < k)
    return 0;
  ll ans = 1;
  ans = ans * fact[n] % MOD;
  ans = ans * _fact[k] % MOD;
  ans = ans * _fact[n - k] % MOD;
  return ans;
}

ll solve(int n, ll f) {
  ll ans = 0;
  for (int x : fac[n])
    ans = (ans + sign[x] * cnk(n / x - 1, f - 1)) % MOD;
  if (ans < 0)
    ans += MOD;
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  init();
  int q;
  cin >> q;
  while (q--) {
    ll n, f;
    cin >> n >> f;
    cout << solve(n, f) << '\n';
  }
  return 0;
}