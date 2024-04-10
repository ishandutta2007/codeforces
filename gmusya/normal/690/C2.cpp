#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector <int> d(int s, vector <vector <int>> &g) {
  int n = g.size();
  vector <int> d(n, INF);
  queue <int> q;
  q.push(s);
  d[s] = 0;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v])
      if (d[v] + 1 < d[u]) {
        d[u] = d[v] + 1;
        q.push(u);
      }
  }
  return d;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector <vector <int>> g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector <int> dis = d(0, g);
  int id = 0;
  for (int v = 0; v < n; v++)
    if (dis[v] > dis[id])
      id = v;
  dis = d(id, g);
  for (int v = 0; v < n; v++)
    if (dis[v] > dis[id])
      id = v;
  cout << dis[id];
  return 0;
}