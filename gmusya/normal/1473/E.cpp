#include <iostream>
#include <vector>
#include <set>

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <pii> vp;
typedef vector <vp> vvp;

const ll INF = 1e18;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vvp g(4 * n);
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    u *= 4, v *= 4;
    g[u].push_back({v, w});
    g[u].push_back({v + 1, 0});
    g[u].push_back({v + 2, w + w});
    g[u].push_back({v + 3, w});
    g[u + 1].push_back({v + 1, w});
    g[u + 1].push_back({v + 3, w + w});
    g[u + 2].push_back({v + 2, w});
    g[u + 2].push_back({v + 3, 0});
    g[u + 3].push_back({v + 3, w});
    swap(u, v);
    g[u].push_back({v, w});
    g[u].push_back({v + 1, 0});
    g[u].push_back({v + 2, w + w});
    g[u].push_back({v + 3, w});
    g[u + 1].push_back({v + 1, w});
    g[u + 1].push_back({v + 3, w + w});
    g[u + 2].push_back({v + 2, w});
    g[u + 2].push_back({v + 3, 0});
    g[u + 3].push_back({v + 3, w});
  }
  set <pair <ll, int>> s;
  vector <ll> d(4 * n, INF);
  d[0] = 0;
  s.insert({d[0], 0});
  while (!s.empty()) {
    int v = s.begin()->second;
    s.erase(s.begin());
    for (auto [u, w] : g[v])
      if (d[v] + w < d[u]) {
        s.erase({d[u], u});
        d[u] = d[v] + w;
        s.insert({d[u], u});
      }
  }
  for (int v = 4; v < 4 * n; v += 4)
    cout << d[v + 3] << ' ';
  return 0;
}