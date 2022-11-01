#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;

const ll MOD = 1e9 + 7;

ll timer = 0;
vi tin, tout, d;
vvi g;

void dfs(ll v) {
  tin[v] = timer++;
  for (ll u : g[v]) {
    d[u] = d[v] + 1;
    dfs(u);
  }
  tout[v] = timer - 1;
}

struct segment_tree {
  ll n;
  vector <ll> t;
  segment_tree(ll _n) {
    n = _n;
    t.resize(n << 2);
  }
  void upd(ll v, ll tl, ll tr, ll l, ll r, ll val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] += val;
      if (t[v] >= MOD)
        t[v] -= MOD;
      return;
    }
    ll tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), val);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
  }
  ll get(ll v, ll tl, ll tr, ll pos) {
    if (tl == tr)
      return t[v];
    ll tm = (tl + tr) / 2;
    t[v * 2] += t[v];
    if (t[v * 2] >= MOD)
      t[v * 2] -= MOD;
    t[v * 2 + 1] += t[v];
    if (t[v * 2 + 1] >= MOD)
      t[v * 2 + 1] -= MOD;
    t[v] = 0;
    if (pos <= tm)
      return get(v * 2, tl, tm, pos);
    else
      return get(v * 2 + 1, tm + 1, tr, pos);
  }
  void upd(ll l, ll r, ll val) {
    upd(1, 0, n - 1, l, r, val);
  }
  ll get(ll pos) {
    return get(1, 0, n - 1, pos);
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin >> n;
  g.resize(n);
  for (ll i = 1; i < n; i++) {
    ll p;
    cin >> p;
    p--;
    g[p].push_back(i);
  }
  tin.resize(n), tout.resize(n), d.resize(n);
  dfs(0);
  segment_tree sta(n), stb(n);
  ll q;
  cin >> q;
  while (q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll v, x, k;
      cin >> v >> x >> k;
      v--;
      x = (x + k * d[v]) % MOD;
      sta.upd(tin[v], tout[v], x);
      stb.upd(tin[v], tout[v], k);
    }
    if (t == 2) {
      ll v;
      cin >> v;
      v--;
      ll ans = sta.get(tin[v]) - stb.get(tin[v]) * 1ll * d[v];
      cout << (ans % MOD + MOD) % MOD << '\n';
    }
  }
  return 0;
}