#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <numeric>
#include <set>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;
typedef vector <vector <pii>> graph;

const ll INF = 1e18;

mt19937 rnd(time(0));

int n, m;

vi dsu;
vi d, p;
vl dis;
vi lg;
vvi up;

graph g, t;

int get(int v) {
  if (dsu[v] == v)
    return v;
  return dsu[v] = get(dsu[v]);
}

void merge(int u, int v) {
  if (rnd() & 1)
    swap(u, v);
  dsu[u] = v;
}

void dfs(int v, int par = -1) {
  for (auto &now : t[v]) {
    int u = now.first, w = now.second;
    if (u == par)
      continue;
    d[u] = d[v] + 1;
    p[u] = v;
    dis[u] = dis[v] + w;
    dfs(u, v);
  }
}

int lca(int u, int v) {
  if (d[u] < d[v])
    swap(u, v);
  for (int i = lg[d[u] - d[v]]; i >= 0; i--)
    if ((1 << i) & (d[u] - d[v]))
      u = up[i][u];
  if (u == v)
    return u;
  for (int i = lg[d[u]]; i >= 0; i--)
    if (up[i][u] != up[i][v])
      u = up[i][u], v = up[i][v];
  return p[u];
}

ll dist(int u, int v) {
  int w = lca(u, v);
  return dis[v] + dis[u] - 2 * dis[w];
}

vl dijkstra(int s) {
  vl res(n, INF);
  res[s] = 0;
  set <pair <ll, ll>> q;
  for (int i = 0; i < n; i++)
    q.insert({res[i], i});
  while (!q.empty()) {
    int v = q.begin()->second;
    q.erase(q.begin());
    for (auto &now : g[v]) {
      int u = now.first, w = now.second;
      if (res[v] + w < res[u]) {
        q.erase({res[u], u});
        res[u] = res[v] + w;
        q.insert({res[u], u});
      }
    }
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> m;
  dsu.resize(n);
  iota(dsu.begin(), dsu.end(), 0);
  vi bad;
  g.resize(n), t.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    int cu = get(u), cv = get(v);
    g[u].push_back({v, w});
    g[v].push_back({u, w});
    if (cu == cv) {
      bad.push_back(u);
      continue;
    }
    t[u].push_back({v, w});
    t[v].push_back({u, w});
    merge(cu, cv);
  }
  d.resize(n), p.resize(n), dis.resize(n);
  dfs(0);
  lg.resize(n + 1);
  for (int i = 2; i <= n; i++)
    lg[i] = lg[i / 2] + 1;
  up.resize(lg[n] + 1, vi(n));
  for (int i = 0; i < n; i++)
    up[0][i] = p[i];
  for (int pow = 1; pow <= lg[n]; pow++)
    for (int i = 0; i < n; i++)
      up[pow][i] = up[pow - 1][up[pow - 1][i]];
  vvl dij;
  for (int s : bad)
    dij.push_back(dijkstra(s));
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    ll ans = dist(u, v);
    for (auto &vect : dij)
      ans = min(ans, vect[u] + vect[v]);
    cout << ans << '\n';
  }
  return 0;
}