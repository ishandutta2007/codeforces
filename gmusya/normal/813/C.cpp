#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main () {
  int n, x;
  cin >> n >> x;
  x--;
  vector <vector <int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector <int> d(n, INF);
  d[0] = 0;
  queue <int> q;
  q.push(0);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v])
      if (d[v] + 1 < d[u]) {
        d[u] = d[v] + 1;
        q.push(u);
      }
  }
  vector <int> p(n, INF);
  p[x] = 0;
  q.push(x);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (d[v] == p[v]) continue;
    for (int u : g[v])
      if (p[v] + 1 < p[u]) {
        p[u] = p[v] + 1;
        q.push(u);
      }
  }
  int ans = 0;
  for (int i = 0; i < n; i++)
    if (d[i] >= p[i])
      ans = max(ans, d[i] * 2);
  cout << ans;
  return 0;
}