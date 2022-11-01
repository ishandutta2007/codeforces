#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <bool> vb;

void bfs(int s, vi &d, vi &p, vvi &g) {
  int n = g.size();
  d.assign(n, n);
  p.assign(n, -1);
  d[s] = 0;
  queue <int> q;
  q.push(s);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v])
      if (d[v] + 1 < d[u]) {
        d[u] = d[v] + 1;
        p[u] = v;
        q.push(u);
      }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvi g(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vb used(n);
  vi sz, rt;
  for (int v = 0; v < n; v++) {
    if (used[v])
      continue;
    vi p(n), d(n);
    bfs(v, d, p, g);
    int l = v;
    for (int i = 0; i < n; i++)
      if (d[i] != n) {
        used[i] = true;
        if (d[i] > d[l])
          l = i;
      }
    bfs(l, d, p, g);
    v = l;
    for (int i = 0; i < n; i++)
      if (d[i] != n && d[i] > d[v])
        v = i;
    int k = d[v];
    sz.push_back(k);
    k /= 2;
    while (k--)
      v = p[v];
    rt.push_back(v);
  }
  vi per(sz.size());
  for (int i = 0; i < (int) per.size(); i++)
    per[i] = i;
  sort(per.begin(), per.end(), [&](int i, int j) {
    return sz[i] > sz[j];
  });
  vector <pair <int, int>> e;
  for (int i = 1; i < (int) per.size(); i++)
    e.push_back({rt[per[i]], rt[per[0]]});
  for (auto [u, v] : e) {
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi p(n), d(n);
  bfs(0, d, p, g);
  int l = 0;
  for (int i = 0; i < n; i++)
    if (d[i] > d[l])
      l = i;
  bfs(l, d, p, g);
  cout << *max_element(d.begin(), d.end()) << '\n';
  for (auto [u, v] : e)
    cout << u + 1 << ' ' << v + 1 << '\n';
  return 0;
}