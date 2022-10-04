#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <random>
#include <complex>
#include <iomanip>
#include <cassert>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
struct Edge {
  int u, v, w;
  Edge() {}
  Edge(int u, int v, int w) : u(u), v(v), w(w) {}
  bool operator <(const Edge &other) const {
    if (u != other.u) return u < other.u;
    if (v != other.v) return v < other.v;
    return w < other.w;
  }
};
 
const ll Inf = 1e18;
 
vector <ll> dijkstra(vector <vector <Edge>> g, int st) {
  int n = g.size();
  vector <ll> d(n, Inf);
  d[st] = 0;
  set <pair <ll, int>> q;
  q.insert({0, st});
  while (!q.empty()) {
    int u = q.begin()->second;
    q.erase(q.begin());
    for (auto [v, w, i] : g[u]) {
      if (d[v] > d[u] + w) {
        q.erase({d[v], v});
        d[v] = d[u] + w;
        q.insert({d[v], v});
      }
    }
  }
  return d;
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  vector <vector <Edge>> g(n);
  vector <pair <ll, int>> a(k);
  for (int i = 0; i < k; ++i) {
    cin >> a[i].second;
    --a[i].second;
  }
  for (int i = 0; i < m; ++i) {
    int u, v, w;
    cin >> u >> v;
    w = 1;
    --u, --v;
    g[u].emplace_back(v, w, i);
    g[v].emplace_back(u, w, i);
  }
  vector <ll> d = dijkstra(g, 0);
  vector <ll> rd = dijkstra(g, n - 1);
  for (int i = 0; i < k; ++i) a[i].first = d[a[i].second];
  sort(a.begin(), a.end(), [&] (pair <ll, int> f, pair <ll, int> s) {
      return f.first < s.first;
  });
  vector <vector <pair <int, int>>> best(k);
  for (int i = k - 1; i >= 0; --i) {
    if (i + 1 < k) best[i] = best[i + 1];
    best[i].push_back({rd[a[i].second], a[i].second});
    sort(best[i].rbegin(), best[i].rend());
    while (best[i].size() > 2) best[i].pop_back();
  }
  
  ll ans = 0;
  for (auto pr : a) {
    int u = pr.second;
    ll l = 0, r = 1e9;
    while (r - l > 1) {
      ll m = (l + r) >> 1;
      ll r1 = m - rd[u] - 1;
      ll r2 = m - d[u] - 1;
      auto it = lower_bound(a.begin(), a.end(), make_pair(r1, -1));
      if (it == a.end()) {
        r = m;
        continue;
      }
      bool fl = false;
      for (auto p : best[it - a.begin()]) {
        if (p.second != u && p.first >= r2) {
          fl = true;
        }
      }
      if (fl) l = m;
      else r = m;
    }
    ans = max(ans, l);
  }
  ans = min(ans, d[n - 1]);
  cout << ans << '\n';
}