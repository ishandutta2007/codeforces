#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>

typedef long long ll;

using namespace std;

mt19937 gen(time(0));

vector <int> dsu;

int get(int v) {
  if (dsu[v] == v) return v;
  return dsu[v] = get(dsu[v]);
}

void merge(int u, int v) {
  if (gen() % 2)
    swap(u, v);
  dsu[u] = v;
}

void dfs(int v, int _p, vector <int> &p, vector <int> &d, vector <ll> &w, vector <vector <pair <int, ll>>> &g) {
  for (auto now : g[v]) {
    int u = now.first, _w = now.second;
    if (u != _p) {
      p[u] = v;
      w[u] = _w;
      d[u] = d[v] + 1;
      dfs(u, v, p, d, w, g);
    }
  }
}

int lca(int u, int v, vector <int> &d, vector <int> &lg, vector <vector <int>> &binup) {
  int n = d.size();
  if (d[u] < d[v])
    swap(u, v);
  int dis = d[u] - d[v];
  for (int i = 0; i <= lg[n]; i++)
    if ((1 << i) & dis)
      u = binup[i][u];
  if (u == v)
    return u;
  int lca = -1;
  for (int i = lg[n]; i >= 0; i--) {
    if (binup[i][u] == binup[i][v])
      lca = binup[i][u];
    else
      u = binup[i][u], v = binup[i][v];
  }
  if (u == v)
    return u;
  return lca;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <pair <int, pair <pair <int, int>, int>>> edges(m);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    edges[i] = {w, {{u, v}, i}};
  }
  sort(edges.begin(), edges.end());
  dsu.resize(n);
  iota(dsu.begin(), dsu.end(), 0);
  ll ans = 0;
  vector <vector <pair <int, ll>>> g(n);
  for (auto &now : edges) {
    int w = now.first, u = now.second.first.first, v = now.second.first.second;
    int nu = get(u), nv = get(v);
    if (nu == nv) continue;
    ans += w;
    merge(nu, nv);
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector <int> p(n), d(n);
  vector <ll> w(n);
  dfs(0, 0, p, d, w, g);
  vector <int> lg(n + 1);
  for (int i = 2; i <= n; i++)
    lg[i] = lg[i / 2] + 1;
  vector <vector <int>> binup(lg[n] + 1, vector <int>(n));
  vector <vector <ll>> binmax(lg[n] + 1, vector <ll>(n));
  for (int i = 0; i < n; i++) {
    binup[0][i] = p[i];
    binmax[0][i] = w[i];
  }
  for (int pow = 1; pow <= lg[n]; pow++)
    for (int i = 0; i < n; i++) {
      binup[pow][i] = binup[pow - 1][binup[pow - 1][i]];
      binmax[pow][i] = max(binmax[pow - 1][i], binmax[pow - 1][binup[pow - 1][i]]);
    }
  vector <ll> answer(m);
  for (auto &now : edges) {
    int w = now.first, u = now.second.first.first, v = now.second.first.second;
    if (d[u] < d[v])
      swap(u, v);
    int lc = lca(u, v, d, lg, binup);
    ll ma = 0;
    {
      int dis = d[u] - d[lc];
      for (int i = 0; i <= lg[n]; i++)
        if ((1 << i) & dis) {
          ma = max(ma, binmax[i][u]);
          u = binup[i][u];
        }
    }
    {
      int dis = d[v] - d[lc];
      for (int i = 0; i <= lg[n]; i++)
        if ((1 << i) & dis) {
          ma = max(ma, binmax[i][v]);
          v = binup[i][v];
        }
    }
    answer[now.second.second] = ans - ma + w;
  }
  for (auto &now : answer)
    cout << now << '\n';
  return 0;
}