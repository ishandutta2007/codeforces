#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

typedef vector <bool> vb;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <ll> vl;
typedef vector <vl> vvl;

const ll INF = 1e18;

struct edge {
  int u, v;
  ll w;
};

vb cen;
vi sz;
vi cp, dp;
vvi g;
vvl dis;
vector <edge> e;

void dfs1(int v, int p) {
  sz[v] = 1;
  for (int i : g[v]) {
    int u = (e[i].u ^ e[i].v ^ v);
    if (u == p || cen[u])
      continue;
    dfs1(u, v);
    sz[v] += sz[u];
  }
}

int dfs2(int v, int p, int est_sz) {
  for (int i : g[v]) {
    int u = (e[i].u ^ e[i].v ^ v);
    if (u == p || cen[u])
      continue;
    if (sz[u] > est_sz)
      return dfs2(u, v, est_sz);
  }
  return v;
}

void dfs3(int v, int p) {
  for (int i : g[v]) {
    int u = (e[i].u ^ e[i].v ^ v);
    ll w = e[i].w;
    if (u == p || cen[u])
      continue;
    dis[u].push_back(dis[v].back() + w);
    dfs3(u, v);
  }
}

void build_centroid_tree(int v, int p, int est_sz) {
  dfs1(v, p);
  int c = dfs2(v, p, est_sz);
  dis[c].push_back(0);
  dfs3(c, -1);
  cp[c] = p;
  if (p != -1)
    dp[c] = dp[p] + 1;
  cen[c] = true;
  for (int i : g[c]) {
    int u = (e[i].u ^ e[i].v ^ c);
    if (!cen[u])
      build_centroid_tree(u, c, est_sz / 2);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  for (int i = 0; i + 1 < n; i++) {
    int u, v, w = 1;
    cin >> u >> v;
    u--, v--;
    e.push_back({u, v, w});
    g[u].push_back(i);
    g[v].push_back(i);
  }
  cen.resize(n);
  sz.resize(n);
  cp.resize(n);
  dp.resize(n);
  dis.resize(n);
  build_centroid_tree(0, -1, n / 2);
  for (int i = 0; i < n; i++)
    cout << (char)(dp[i] + 'A') << ' ';
  return 0;
}