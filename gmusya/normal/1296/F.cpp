#include <iostream>
#include <vector>
#include <queue>

#define fi first
#define se second

using namespace std;

const int MAXF = 1e6;

typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;

int d[5000][5000];

void bfs(int s, vi &e, vvi &g) {
  int n = (int)g.size();
  d[s][s] = 0;
  queue <int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int id : g[v]) {
      int u = e[id] - v;
      if (d[s][v] + 1 < d[s][u]) {
        d[s][u] = d[s][v] + 1;
        q.push(u);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vvi g(n);
  vi e(n - 1);
  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    e[i] = u + v;
    g[u].push_back(i), g[v].push_back(i);
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      d[i][j] = n;
  for (int i = 0; i < n; i++)
    bfs(i, e, g);
  vi f(n - 1, 1);
  int q;
  cin >> q;
  vector <pair <pii, int>> que;
  for (int i = 0; i < q; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    que.push_back({{u, v}, w});
  }
  for (int i = 0; i < q; i++) {
    int u = que[i].fi.fi, v = que[i].fi.se, w = que[i].se;
    for (int a = 0; a < n; a++)
      for (int id : g[a]) {
        int b = e[id] - a;
        if ((d[u][a] + 1 + d[b][v] == d[u][v]) || (d[u][b] + 1 + d[a][v] == d[u][v]))
          f[id] = max(f[id], w);
      }
  }
  bool flag = true;
  for (int i = 0; i < q; i++) {
    bool tmp = false;
    int u = que[i].fi.fi, v = que[i].fi.se, w = que[i].se;
    for (int a = 0; a < n; a++)
      for (int id : g[a]) {
        int b = e[id] - a;
        if ((d[u][a] + 1 + d[b][v] == d[u][v]) || (d[u][b] + 1 + d[a][v] == d[u][v]))
          if (f[id] == w)
            tmp = true;
      }
    if (!tmp)
      flag = false;
  }
  if (!flag) {
    cout << -1;
    return 0;
  }
  for (int w : f)
    cout << w << ' ';
  return 0;
}