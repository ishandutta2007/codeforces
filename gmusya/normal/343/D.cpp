#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

struct segment_tree {
  int n;
  vector <int> t, mod;
  segment_tree(int _n, int x) {
    n = _n;
    t.resize(n << 2, x);
    mod.resize(n << 2, x);
  }
  int get(int v, int tl, int tr, int l, int r) {
    if (l > r)
      return -2;
    if (l == tl && r == tr)
      return max(t[v], mod[v]);
    mod[v * 2] = max(mod[v], mod[v * 2]);
    mod[v * 2 + 1] = max(mod[v], mod[v * 2 + 1]);
    int tm = (tl + tr) / 2;
    int x = get(v * 2, tl, tm, l, min(r, tm));
    int y = get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    t[v] = max({t[v * 2], t[v * 2 + 1], mod[v * 2], mod[v * 2 + 1]});
    return max(x, y);
  }
  void upd(int v, int tl, int tr, int l, int r, int val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      mod[v] = val;
      return;
    }
    mod[v * 2] = max(mod[v], mod[v * 2]);
    mod[v * 2 + 1] = max(mod[v], mod[v * 2 + 1]);
    int tm = (tl + tr) / 2;
    upd(v * 2, tl, tm, l, min(r, tm), val);
    upd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = max({t[v * 2], t[v * 2 + 1], mod[v * 2], mod[v * 2 + 1]});
  }
  int get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }
  void upd(int l, int r, int val) {
    upd(1, 0, n - 1, l, r, val);
  }
};

int timer = -1;
vi tin, tout;
vvi g;

void dfs(int v, int p = -1) {
  tin[v] = ++timer;
  for (int u : g[v])
    if (u != p)
      dfs(u, v);
  tout[v] = timer;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  tin.resize(n), tout.resize(n);
  dfs(0);
  segment_tree stm(n, -1), stp(n, -1);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int v;
      cin >> v;
      v--;
      stp.upd(tin[v], tout[v], i);
    }
    if (t == 2) {
      int v;
      cin >> v;
      v--;
      stm.upd(tin[v], tin[v], i);
    }
    if (t == 3) {
      int v;
      cin >> v;
      v--;
      int a = stp.get(tin[v], tin[v]);
      int b = stm.get(tin[v], tout[v]);
      if (a > b)
        cout << 1 << '\n';
      else
        cout << 0 << '\n';
    }
  }
  return 0;
}