#pragma optimize("Ofast")

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector <ll> vi;
typedef vector <vi> vvi;

struct segment_tree {
  ll n;
  vector <ll> t, mod;
  segment_tree(ll _n) {
    n = _n;
    t.resize(n << 2);
    mod.resize(n << 2, -1);
  }
  void push(ll v) {
    if (mod[v] == -1)
      return;
    mod[v * 2] = mod[v * 2 + 1] = t[v * 2] = t[v * 2 + 1] = t[v] = mod[v];
    mod[v] = -1;
  }
  void upd(ll v, ll tl, ll tr, ll l, ll r, ll val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] = mod[v] = val;
      return;
    }
    push(v);
    ll tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), val);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = (t[v * 2] | t[v * 2 + 1]);
  }
  ll get(ll v, ll tl, ll tr, ll l, ll r) {
    if (l > r)
      return 0;
    if (l == tl && r == tr) {
      if (mod[v] != -1)
        t[v] = mod[v];
      return t[v];
    }
    push(v);
    ll tm = (tl + tr) / 2;
    ll x = get(v * 2, tl, tm, l, min(r, tm));
    ll y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = (t[v * 2] | t[v * 2 + 1]);
    return (x | y);
  }
  void upd(ll l, ll r, ll val) {
    upd(1, 0, n - 1, l, r, val);
  }
  ll get(ll l, ll r) {
    return get(1, 0, n - 1, l, r);
  }
};

ll n, q, timer = -1;
vi tin, tout;
vvi g;

void dfs(ll v, ll p = -1) {
  tin[v] = ++timer;
  for (ll u : g[v])
    if (u != p)
      dfs(u, v);
  tout[v] = timer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  g.resize(n);
  vector <ll> c(n);
  for (ll i = 0; i < n; i++) {
    cin >> c[i];
    c[i]--;
  }
  segment_tree st(n);
  for (ll i = 1; i < n; i++) {
    ll u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  tin.resize(n), tout.resize(n);
  dfs(0);
  for (ll i = 0; i < n; i++)
    st.upd(tin[i], tin[i], (1ll << c[i]));
  while (q--) {
    ll t;
    cin >> t;
    if (t == 1) {
      ll v, c;
      cin >> v >> c;
      v--, c--;
      ll x = (1ll << c);
      st.upd(tin[v], tout[v], x);
    }
    if (t == 2) {
      ll v;
      cin >> v;
      v--;
      ll res = st.get(tin[v], tout[v]);
      ll ans = 0;
      for (ll i = 0; i < 60; i++)
        if (res & (1ll << i))
          ans++;
      cout << ans << endl;
    }
  }
  return 0;
}