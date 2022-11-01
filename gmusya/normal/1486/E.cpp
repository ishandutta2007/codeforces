#pragma GCC optimize("O3")

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vi> vvi;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <vector <pair <int, int>>> g(n * 51);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    u *= 51, v *= 51;
    g[u].push_back({v + w, 0});
    g[v].push_back({u + w, 0});
    for (int j = 1; j <= 50; j++) {
      g[u + j].push_back({v, w});
      g[v + j].push_back({u, w});
    }
  }
  vector <int> d(n * 51, INF);
  d[0] = 0;
  set <pii> s;
  for (int v = 0; v < n * 51; v++)
    s.insert({d[v], v});
  while (!s.empty()) {
    int v = s.begin()->second;
    s.erase(s.begin());
    for (pii e : g[v]) {
      int u = e.first, w = e.second;
      if (w != 0) {
        w += v % 51;
        w *= w;
      }
      if (d[v] + w < d[u]) {
        s.erase({d[u], u});
        d[u] = d[v] + w;
        s.insert({d[u], u});
      }
    }
  }
  for (int v = 0; v < n; v++) {
    int ans = d[v * 51];
    if (ans == INF)
      ans = -1;
    cout << ans << ' ';
  }
  return 0;
}