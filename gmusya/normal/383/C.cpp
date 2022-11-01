#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

struct segment_tree {
  int n;
  vector <ll> t;
  segment_tree(int _n) {
    n = _n;
    t.resize(n << 2);
  }
  void push(int v) {
    t[v * 2] += t[v];
    t[v * 2 + 1] += t[v];
    t[v] = 0;
  }
  void build(int v, int tl, int tr, vector <int> &a) {
    if (tl == tr) {
      t[v] = a[tl];
      return;
    }
    int tm = (tl + tr) / 2;
    build(v * 2, tl, tm, a);
    build(v * 2 + 1, tm + 1, tr, a);
  }
  void update(int v, int tl, int tr, int l, int r, int val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] += val;
      return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(v * 2, tl, tm, l, min(r, tm), val);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
  }
  ll get(int v, int tl, int tr, int pos) {
    if (tl == tr)
      return t[v];
    push(v);
    int tm = (tl + tr) / 2;
    if (pos <= tm)
      return get(v * 2, tl, tm, pos);
    return get(v * 2 + 1, tm + 1, tr, pos);
  }
  void build(vector <int> &a) {
    build(1, 0, n - 1, a);
  }
  void update(int l, int r, int val) {
    update(1, 0, n - 1, l, r, val);
  }
  ll get(int pos) {
    return get(1, 0, n - 1, pos);
  }
};

int timer = 0;
vector <bool> used;
vector <int> tin, tout, depth, pos;
vector <vector <int>> g;

void dfs(int v) {
  pos[timer] = v;
  tin[v] = timer++;
  used[v] = true;
  for (int u : g[v])
    if (!used[u]) {
      depth[u] = depth[v] + 1;
      dfs(u);
    }
  tout[v] = timer - 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  used.resize(n);
  tin.resize(n), tout.resize(n), depth.resize(n), pos.resize(n);
  g.resize(n);
  vector <int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  dfs(0);
  vector <int> b(n);
  for (int v = 0; v < n; v++) {
    if (depth[v] % 2)
      a[v] = -a[v];
    b[tin[v]] = a[v];
  }
  segment_tree se(n);
  se.build(b);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int v, val;
      cin >> v >> val;
      v--;
      if (depth[v] % 2)
        val = -val;
      se.update(tin[v], tout[v], val);
    }
    if (type == 2) {
      int v;
      cin >> v;
      v--;
      ll val = se.get(tin[v]);
      if (depth[v] % 2)
        val = -val;
      cout << val << '\n';
    }
  }
  return 0;
}