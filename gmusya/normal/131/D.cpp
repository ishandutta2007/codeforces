#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector <int> vi;
typedef vector <vi> vvi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vvi g(n);
  for (int i = 0; i < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vi deg(n);
  for (int i = 0; i < n; i++)
    deg[i] = (int) g[i].size();
  queue <int> q;
  for (int i = 0; i < n; i++)
    if (deg[i] == 1)
      q.push(i);
  vector <bool> used(n);
  while (!q.empty()) {
    int v = q.front();
    used[v] = true;
    q.pop();
    for (int u : g[v]) {
      deg[u]--;
      if (deg[u] == 1)
        q.push(u);
    }
  }
  vi d(n, n);
  for (int i = 0; i < n; i++)
    if (!used[i]) {
      q.push(i);
      d[i] = 0;
    }
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    for (int u : g[v])
      if (d[v] + 1 < d[u]) {
        d[u] = d[v] + 1;
        q.push(u);
      }
  }
  for (int x : d)
    cout << x << ' ';
  return 0;
}