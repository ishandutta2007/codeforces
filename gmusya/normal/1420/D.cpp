#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

const ll MOD = 998244353;

vector <ll> fact, _fact;

ll binp(ll a, ll p) {
  if (!p) return 1;
  if (p % 2) return a * binp(a, p - 1) % MOD;
  ll x = binp(a, p / 2);
  return x * x % MOD;
}

ll cnk(int n, int k) {
  if (n < 0 || k < 0 || n - k < 0) return 0;
  ll ans = fact[n];
  ans = ans * _fact[k] % MOD;
  ans = ans * _fact[n - k] % MOD;
  return ans;
}

void init(int n) {
  fact.resize(n + 1), _fact.resize(n + 1);
  fact[0] = _fact[0] = 1;
  for (int i = 1; i <= n; i++)
    fact[i] = (fact[i - 1] * i) % MOD;
  _fact[n] = binp(fact[n], MOD - 2);
  for (int i = n - 1; i >= 1; i--)
    _fact[i] = (_fact[i + 1] * (i + 1)) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  init(n);
  vector <pair <int, int>> seg;
  for (int i = 0; i < n; i++) {
    int l, r;
    cin >> l >> r;
    seg.push_back({l, 0});
    seg.push_back({r, 1});
  }
  sort(seg.begin(), seg.end());
  ll ans = 0;
  int bal = 0;
  for (int i = 0; i < (int)seg.size(); i++) {
    if (seg[i].second == 0) {
      bal++;
      continue;
    }
    bal--;
    ans = (ans + cnk(bal, k - 1)) % MOD;
  }
  cout << ans;
  return 0;
}