#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <random>
#include <numeric>

using namespace std;

mt19937_64 gen(time(0));

vector <bool> used;
vector <int> dsu;
vector <int> maxdepth, diam;
vector <vector <int>> g;

int get(int v) {
  if (dsu[v] == v)
    return v;
  return dsu[v] = get(dsu[v]);
}

void merge(int u, int v) {
  u = get(u), v = get(v);
  int newdiam = (diam[u] + 1) / 2 + (diam[v] + 1) / 2 + 1;
  newdiam = max({newdiam, diam[u], diam[v]});
  if (gen() % 2)
    swap(u, v);
  dsu[v] = u;
  diam[u] = newdiam;
}

void dfs(int v, int root) {
  used[v] = true;
  dsu[v] = root;
  vector <int> tmp = {0, 0};
  maxdepth[v] = 1;
  for (int u : g[v]) {
    if (used[u]) continue;
    dfs(u, root);
    diam[v] = max(diam[v], diam[u]);
    tmp.push_back(maxdepth[u]);
    if (tmp[1] < tmp[2])
      swap(tmp[1], tmp[2]);
    if (tmp[0] < tmp[1])
      swap(tmp[0], tmp[1]);
    tmp.pop_back();
  }
  maxdepth[v] = tmp[0] + 1;
  diam[v] = max(diam[v], tmp[0] + tmp[1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  used.resize(n);
  dsu.resize(n);
  maxdepth.resize(n), diam.resize(n);
  g.resize(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  for (int v = 0; v < n; v++)
    if (!used[v])
      dfs(v, v);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int v;
      cin >> v;
      v--;
      v = get(v);
      cout << diam[v] << '\n';
    } else {
      int u, v;
      cin >> u >> v;
      u--, v--;
      u = get(u), v = get(v);
      if (u == v) continue;
      merge(u, v);
    }
  }
  return 0;
}

/*
10 9 1
1 2
2 3
3 4
2 5
2 6
5 7
2 8
3 9
2 10
1 4
*/