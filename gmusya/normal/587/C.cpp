#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> mrg(vector <int> a, vector <int> b, int k) {
  vector <int> x;
  merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(x));
  x.resize(unique(x.begin(), x.end()) - x.begin());
  while (x.size() > k)
    x.pop_back();
  return x;
}

void dfs (int v, int p, vector <int> &par, vector <int> &dep, vector <vector <int>> &g) {
  for (int u : g[v]) {
    if (u == p) continue;
    par[u] = v;
    dep[u] = dep[v] + 1;
    dfs(u, v, par, dep, g);
  }
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector <vector <int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector <vector <int>> c(n);
  for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    c[x - 1].push_back(i);
  }
  for (int i = 0; i < n; i++)
    if (!c[i].empty()) {
      sort(c[i].begin(), c[i].end());
      while (c[i].size() > 10)
        c[i].pop_back();
    }
  vector <int> par(n), dep(n);
  dfs(0, 0, par, dep, g);
  vector <int> lg(n + 1);
  for (int i = 1; i <= n; i++)
    lg[i] = lg[i / 2] + 1;
  vector <vector <int>> binp(lg[n] + 1, vector <int>(n));
  vector <vector <vector <int>>> func(lg[n] + 1, vector <vector <int>>(n));
  for (int i = 0; i < n; i++)
    binp[0][i] = par[i];
  for (int pow = 1; pow <= lg[n]; pow++)
    for (int i = 0; i < n; i++)
      binp[pow][i] = binp[pow - 1][binp[pow - 1][i]];
  for (int i = 0; i < n; i++)
    func[0][i] = mrg(c[par[i]], c[i], 10);
  for (int pow = 1; pow <= lg[n]; pow++)
    for (int i = 0; i < n; i++)
      func[pow][i] = mrg(func[pow - 1][i], func[pow - 1][binp[pow - 1][i]], 10);
  while (q--) {
    int u, v, a;
    cin >> u >> v >> a;
    u--, v--;
    int lca = -1;
    if (u == v)
      lca = u;
    else {
      if (dep[u] < dep[v])
        swap(u, v);
      int wu = u, wv = v;
      int len = dep[u] - dep[v];
      for (int i = 0; i <= lg[n]; i++)
        if ((1 << i) & len)
          wu = binp[i][wu];
      for (int i = lg[n]; i >= 0; i--) {
        if (binp[i][wu] == binp[i][wv])
          lca = binp[i][wu];
        else
          wu = binp[i][wu], wv = binp[i][wv];
      }
      if (wu == wv)
        lca = wu;
    }
    vector <int> ans = mrg(c[u], c[v], a);
    int len0 = dep[u] - dep[lca] - 1;
    if (len0 >= 0)
      for (int i = 0; i < lg[n]; i++)
        if ((1 << i) & len0) {
          ans = mrg(ans, func[i][u], a);
          u = binp[i][u];
        }
    int len1 = dep[v] - dep[lca];
    if (len1 >= 0)
      for (int i = 0; i <= lg[n]; i++)
        if ((1 << i) & len1) {
          ans = mrg(ans, func[i][v], a);
          v = binp[i][v];
        }
    cout << ans.size() << ' ';
    for (int i = 0; i < ans.size(); i++)
      cout << ans[i] + 1 << ' ';
    cout << '\n';
  }
  return 0;
}