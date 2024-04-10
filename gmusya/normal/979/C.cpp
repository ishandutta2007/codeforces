#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

vector <int> d(int s, vector <vector <int>> &g) {
  int n = g.size();
  queue <int> q;
  vector <int> d(n, INF);
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

void dfs(int v, long long &cnt, vector <bool> &used, vector <vector <int>> &g) {
  used[v] = true;
  cnt++;
  for (int u : g[v])
    if (!used[u])
      dfs(u, cnt, used, g);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n >> x >> y;
  x--, y--;
  vector <vector <int>> g(n);
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v), g[v].push_back(u);
  }
  vector <int> dx = d(x, g), dy = d(y, g);
  long long szx = 0, szy = 0;
  vector <bool> used(n);
  for (int i = 0; i < n; i++)
    if (dx[i] + dy[i] == dx[y])
      used[i] = true;
  dfs(x, szx, used, g);
  dfs(y, szy, used, g);
  long long ans = (long long) n * n - n - szx * szy;
  cout << ans;
  return 0;
}