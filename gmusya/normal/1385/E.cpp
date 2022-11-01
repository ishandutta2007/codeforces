#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int timer = 0;

void dfs (int v, vector <bool> &used, vector <int> &order, vector <vector <int>> &g) {
  used[v] = true;
  for (int u : g[v])
    if (!used[u])
      dfs(u, used, order, g);
  order[v] = timer++;
}

int main () {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector <pair <pair <int, int>, int>> e;
    vector <vector <int>> g(n);
    for (int i = 0; i < m; i++) {
      int type;
      cin >> type;
      if (type == 0) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e.push_back({{u, v}, type});
        continue;
      }
      if (type == 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
        e.push_back({{u, v}, type});
      }
    }
    vector <bool> used(n);
    vector <int> order(n);
    for (int i = 0; i < n; i++)
      if (!used[i])
        dfs(i, used, order, g);
    bool tf = true;
    for (auto &now : e) {
      int u = now.first.first, v = now.first.second, type = now.second;
      if (type == 1 && order[u] < order[v])
        tf = false;
    }
    if (!tf) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    for (auto &now : e) {
      int u = now.first.first, v = now.first.second;
      if (order[u] < order[v])
        swap(u, v);
      cout << u + 1 << ' ' << v + 1 << '\n';
    }
  }
  return 0;
}