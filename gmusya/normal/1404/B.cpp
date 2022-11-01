#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector <int> d(int s, vector <vector <int>> &g) {
  int n = g.size();
  vector <int> d(n, INF);
  queue <int> q;
  d[s] = 0;
  q.push(s);
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

int diameter(vector <vector <int>> &g) {
  int n = g.size();
  vector <int> d0 = d(0, g);
  int id = 0;
  for (int i = 0; i < n; i++)
    if (d0[i] > d0[id])
      id = i;
  vector <int> d1 = d(id, g);
  for (int i = 0; i < n; i++)
    if (d1[i] > d1[id])
      id = i;
  return d1[id];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--, b--;
    vector <vector <int>> g(n);
    for (int i = 1; i < n; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int diam = diameter(g);
    vector <int> dis = d(a, g);
    if (2 * da >= diam || 2 * da >= db || dis[b] <= da)
      cout << "Alice\n";
    else
      cout << "Bob\n";
  }
  return 0;
}