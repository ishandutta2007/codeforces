#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  Dsu(int n) : p(n, -1) {}

  int find(int x) { return p[x] < 0 ? x : p[x] = find(p[x]); }

  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v)
      return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};

const int N = 5e5 + 5, LG = 20;

vector<pair<int, int>> g[N];
int col[N], par[N], lv[N], in[N], out[N], ccounter = 0;
int anc[LG][N];

void dfs(int v) {
  anc[0][v] = par[v];
  for (int i = 0; i+1 < LG; ++i) {
    anc[i+1][v] = anc[i][anc[i][v]];
  }
  in[v] = ccounter++;
  for (auto& [u, w] : g[v]) {
    if (u == par[v]) continue;
    col[u] = col[v] ^ w;
    par[u] = v;
    lv[u] = lv[v] + 1;
    dfs(u);
  }
  out[v] = ccounter;
}

int lca(int u, int v) {
  if (lv[u] > lv[v])
    swap(u, v);
  int diff = lv[v] - lv[u];
  for (int i = 0; i < LG; ++i) {
    if (diff & (1 << i)) {
      v = anc[i][v];
    }
  }
  if (u == v)
    return u;
  for (int i = LG-1; i >= 0; --i) {
    if (anc[i][u] != anc[i][v]) {
      u = anc[i][u];
      v = anc[i][v];
    }
  }
  return anc[0][v];
}

struct Fenwick {
  vector<int> sum;
  Fenwick(int _n) : sum(_n + 5, 0) {}

  void update(int x, int v) {
    for (++x; x < (int)sum.size(); x += x&-x)
      sum[x] += v;
  }

  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x)
      ret += sum[x];
    return ret;
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> x(q), y(q), z(q);
  Dsu dsu(n);
  vector<int> ans(q, 0);
  for (int i = 0; i < q; ++i) {
    cin >> x[i] >> y[i] >> z[i];
    --x[i], --y[i];
    if (dsu.merge(x[i], y[i])) {
      g[x[i]].emplace_back(y[i], z[i]);
      g[y[i]].emplace_back(x[i], z[i]);
      ans[i] = 1;
    }
  }
  memset(col, -1, sizeof col);
  for (int i = 0; i < n; ++i) {
    if (col[i] != -1) continue;
    par[i] = i;
    col[i] = 0;
    dfs(i);
  }
  Fenwick fen(n);
  for (int i = 0; i < q; ++i) {
    if (ans[i]) continue;
    int u = x[i], v = y[i], w = z[i];
    int cycle = col[u] ^ col[v] ^ w;
    if (cycle == 0) continue;
    int a = lca(u, v);
    int tot = fen.get(in[u]) + fen.get(in[v]) - 2 * fen.get(in[a]);
    if (tot > 0) {
      continue;
    }
    ans[i] = 1;
    while (u != v) {
      if (lv[u] > lv[v]) {
        swap(u, v);
      }
      fen.update(in[v], +1);
      fen.update(out[v], -1);
      v = par[v];
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << (ans[i] ? "YES\n" : "NO\n");
  }
  return 0;
}