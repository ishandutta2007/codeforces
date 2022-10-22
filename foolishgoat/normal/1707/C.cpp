#include <bits/stdc++.h>

using namespace std;

struct Dsu {
  vector<int> p;
  Dsu(int n) : p(n, -1) {}
  int find(int x) {
    return p[x] < 0 ? x : p[x] = find(p[x]);
  }
  bool merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return false;
    if (-p[u] > -p[v])
      swap(u, v);
    p[v] += p[u];
    p[u] = v;
    return true;
  }
};


constexpr int LG = 20;
vector<int> parent[LG];
vector<vector<int>> tree;
vector<int> in, out, depth;
vector<int> nodes;

void dfs(int v, int par) {
  parent[0][v] = par;
  for (int i = 0; i + 1 < LG; ++i) {
    parent[i+1][v] = parent[i][parent[i][v]];
  }
  in[v] = nodes.size();
  nodes.push_back(v);
  for (int u : tree[v]) {
    if (u == par) continue;
    depth[u] = depth[v] + 1;
    dfs(u, v);
  }
  out[v] = nodes.size();
}

bool is_anc(int u, int v) {
  return in[v] <= in[u] && out[u] <= out[v];
}


struct Fenwick {
  vector<int> bit;
  Fenwick(int n) : bit(n+4, 0) {
  }
  void update(int x, int v) {
    for (++x; x < (int)bit.size(); x += x&-x)
      bit[x] += v;
  }

  int get(int x) {
    int ret = 0;
    for (++x; x; x -= x&-x)
      ret += bit[x];
    return ret;
  }
};

int anc(int v, int d) {
  int diff = depth[v] - d;
  for (int i = 0; i < LG; ++i) {
    if ((diff & (1 << i)))
      v = parent[i][v];
  }
  return v;
}

void work() {
  int n, m;
  cin >> n >> m;
  Dsu dsu(n);
  vector<pair<int, int>> unused;
  in.resize(n);
  out.resize(n);
  tree.resize(n);
  depth.assign(n, 0);
  for (int i = 0; i < LG; ++i)
    parent[i].resize(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    if (dsu.merge(u, v)) {
      tree[u].emplace_back(v);
      tree[v].emplace_back(u);
    } else {
      unused.emplace_back(u, v);
    }
  }
  dfs(0, 0);
  Fenwick fen(n);
  for (auto [u, v] : unused) {
    if (is_anc(u, v) || is_anc(v, u)) {
      if (is_anc(v, u))
        swap(u, v);
      fen.update(0, +1);
      v = anc(u, depth[v]+1);
      fen.update(in[v], -1);
      fen.update(in[u], +1);
      fen.update(out[u], -1);
      fen.update(out[v], +1);
    } else {
      fen.update(in[u], +1);
      fen.update(out[u], -1);
      fen.update(in[v], +1);
      fen.update(out[v], -1);
    }
  }
  int cnt = unused.size();
  string ans(n, '0');
  for (int i = 0; i < n; ++i) {
    if (fen.get(i) == cnt) {
      ans[nodes[i]] = '1';
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc = 1;
  // cin >> tc;
  for (int t = 0; t < tc; ++t) {
    work();
  }
  return 0;
}