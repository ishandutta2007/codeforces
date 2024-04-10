#include <iostream>
#include <vector>

using namespace std;

int n;

vector <int> centroid;

void dfs (int v, int p, vector <bool> &used, vector <int> &sz, vector <vector <int>> &g) {
  sz[v] = 1;
  used[v] = true;
  for (int u : g[v])
    if (!used[u]) {
      dfs(u, p, used, sz, g);
      sz[v] += sz[u];
    }
  if (2 * sz[v] >= n) {
    bool tf = true;
    for (int u : g[v])
      if (u != p && 2 * sz[u] > n)
        tf = false;
    if (tf)
      centroid.push_back(v);
  }
}

int main () {
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    vector <vector <int>> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector <bool> used(n);
    vector <int> sz(n);
    centroid = vector <int>();
    dfs(0, 0, used, sz, g);
    if (centroid.size() == 1) {
      int u = 0, v = g[0][0];
      cout << u + 1 << ' ' << v + 1 << '\n' << u + 1 << ' ' << v + 1 << '\n';
      continue;
    }
    int kid;
    for (int i = 0; i < g[centroid[0]].size(); i++)
      if (g[centroid[0]][i] != centroid[1])
        kid = g[centroid[0]][i];
    cout << kid + 1 << ' ' << centroid[0] + 1 << '\n' << kid + 1 << ' ' << centroid[1] + 1 << '\n';
  }
  return 0;
}