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

int diameter(vector <vector <int>> &g) {
  int n = g.size();
  vector <int> d0 = d(0, g);
  int id = 0;
  for (int v = 0; v < n; v++)
    if (d0[v] > d0[id])
      id = v;
  vector <int> d1 = d(id, g);
  for (int v = 0; v < n; v++)
    if (d1[v] > d1[id])
      id = v;
  return d1[id];
}

int main() {
  freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  int ans = 0;
  while (n--) {
    int m;
    cin >> m;
    vector <vector <int>> g(m);
    for (int i = 1; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    ans += diameter(g);
  }
  cout << ans;
  return 0;
}