#include <iostream>
#include <vector>
#include <set>

using namespace std;

const int INF = 1e9;

vector <int> dijkstra(int s, vector <vector <pair <int, int>>> &g) {
  int n = g.size();
  vector <int> d(n, INF);
  set <pair <int, int>> se;
  d[s] = 0;
  for (int i = 0; i < n; i++)
    se.insert({d[i], i});
  while (!se.empty()) {
    int v = se.begin()->second;
    se.erase(se.begin());
    for (auto &e : g[v]) {
      int u = e.first, w = e.second;
      if (d[v] + w < d[u]) {
        se.erase({d[u], u});
        d[u] = d[v] + w;
        se.insert({d[u], u});
      }
    }
  }
  return d;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  vector <vector <pair <int, int>>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    g[u].push_back({v, w});
    g[v].push_back({u, w});
  }
  vector <vector <int>> d(n);
  for (int i = 0; i < n; i++)
    d[i] = dijkstra(i, g);
  vector <pair <int, int>> c(k);
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    c[i] = {u, v};
  }
  int ans = 2e9;
  for (int i = 0; i < n; i++) {
    for (auto &e : g[i]) {
      int u = i, v = e.first;
      int sum = 0;
      for (int j = 0; j < k; j++) {
        int st = c[j].first, fi = c[j].second;
        int tmp = d[st][fi];
        tmp = min(tmp, d[st][u] + d[v][fi]);
        tmp = min(tmp, d[st][v] + d[u][fi]);
        sum += tmp;
      }
      ans = min(ans, sum);
    }
  }
  cout << ans;
  return 0;
}