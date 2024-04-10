#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void dfs (int v, int p, vector <int> &par, vector <int> &sz, vector <int> &dep, vector <vector <int>> &g) {
  sz[v] = 1;
  for (int u : g[v])
    if (u != p) {
      par[u] = v;
      dep[u] = dep[v] + 1;
      dfs(u, v, par, sz, dep, g);
      sz[v] += sz[u];
    }
}

int main () {
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
  vector <int> par(n), sz(n), d(n);
  dfs(0, 0, par, sz, d, g);
  vector <int> lg(n + 1);
  for (int i = 2; i <= n; i++)
    lg[i] = lg[i / 2] + 1;
  vector <vector <int>> binp(lg[n] + 1, vector <int>(n));
  for (int i = 0; i < n; i++)
    binp[0][i] = par[i];
  for (int pow = 1; pow <= lg[n]; pow++)
    for (int i = 0; i < n; i++)
      binp[pow][i] = binp[pow - 1][binp[pow - 1][i]];
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    if (u == v) {
      cout << n << '\n';
      continue;
    }
    if ((d[u] + d[v]) % 2) {
      cout << "0\n";
      continue;
    }
    if (d[u] < d[v])
      swap(u, v);
    int tmp = u;
    for (int i = 0; i <= lg[n]; i++)
      if ((1 << i) & (d[tmp] - d[v]))
        tmp = binp[i][tmp];
    int wu = tmp, wv = v, lca = -1;
    for (int i = lg[n]; i >= 0; i--) {
      if (binp[i][wu] == binp[i][wv])
        lca = binp[i][wu];
      else
        wu = binp[i][wu], wv = binp[i][wv];
    }
    if (wu == wv)
      lca = wu;
    if (d[u] == d[v]) {
      int x = u, y = v;
      int len = d[v] - d[lca] - 1;
      for (int i = 0; i <= lg[n]; i++)
        if ((1 << i) & len)
          x = binp[i][x], y = binp[i][y];
      cout << n - sz[x] - sz[y] << '\n';
      continue;
    }
    int len0 = d[u] - d[lca] - (d[u] - d[v]) / 2;
    int len1 = len0 - 1;
    int x = u, y = u;
    for (int i = 0; i <= lg[n]; i++) {
      if ((1 << i) & len0)
        x = binp[i][x];
      if ((1 << i) & len1)
        y = binp[i][y];
    }
    cout << sz[x] - sz[y] << '\n';
  }
  return 0;
}