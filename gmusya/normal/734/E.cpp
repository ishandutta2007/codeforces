#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int col = 0;
vi c, comp, dp, len;
vvi g, gcomp;

void dfs(int v, int p = -1) {
  comp[v] = col;
  for (int u : g[v])
    if (c[v] == c[u] && u != p)
      dfs(u, v);
}

void diam(int v, int p = -1) {
  vi tmp(2);
  for (int u : gcomp[v]) {
    if (u == p)
      continue;
    diam(u, v);
    tmp.push_back(len[u]);
  }
  sort(tmp.rbegin(), tmp.rend());
  col = max(col, tmp[0] + tmp[1]);
  len[v] = tmp[0] + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  g.resize(n);
  c.resize(n);
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  comp.resize(n, -1);
  for (int i = 0; i < n; i++)
    if (comp[i] == -1) {
      dfs(i);
      col++;
    }
  gcomp.resize(col);
  for (int v = 0; v < n; v++)
    for (int u : g[v])
      if (c[u] != c[v])
        gcomp[comp[v]].push_back(comp[u]);
  dp.resize(col), len.resize(col);
  col = 0;
  diam(0);
  cout << (col + 1) / 2;
  return 0;
}