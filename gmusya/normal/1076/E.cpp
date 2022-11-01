#include <iostream>
#include <vector>
#include <algorithm>

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
  void update(int v, int tl, int tr, int l, int r, ll val) {
    if (l > r)
      return;
    if (l == tl && r == tr) {
      t[v] += val;
      return;
    }
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
  void update(int l, int r, ll val) {
    update(1, 0, n - 1, l, min(r, n - 1), val);
  }
  ll get(int pos) {
    return get(1, 0, n - 1, pos);
  }
};

void dfs(int v, vector <bool> &used, vector <int> &d, vector <ll> &ans,
  vector <vector <int>> &g, vector <vector <pair <ll, ll>>> &que, segment_tree &se) {
  used[v] = true;
  for (auto &now : que[v])
    se.update(d[v], d[v] + now.first, now.second);
  ans[v] = se.get(d[v]);
  for (int u : g[v])
    if (!used[u]) {
      d[u] = d[v] + 1;
      dfs(u, used, d, ans, g, que, se);
    }
  for (auto &now : que[v])
    se.update(d[v], d[v] + now.first, -now.second);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <vector <int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int q;
  cin >> q;
  vector <vector <pair <ll, ll>>> que(n);
  while (q--) {
    int v, d, x;
    cin >> v >> d >> x;
    v--;
    que[v].push_back({d, x});
  }
  vector <bool> used(n);
  vector <int> d(n);
  vector <ll> ans(n);
  segment_tree se(n);
  dfs(0, used, d, ans, g, que, se);
  for (auto &now : ans)
    cout << now << ' ';
  return 0;
}