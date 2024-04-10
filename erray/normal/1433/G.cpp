// author: erray
#include<bits/stdc++.h>
 
using namespace std;

template<typename T> class graph {
  public:
  struct edge {
    int v, u;
    T w;
  };

  int n;
  vector<vector<int>> g;
  vector<edge> edges;

  graph(int _n) : n(_n) {
    g.resize(n);
  }

  graph(const graph<T>& _g) {
    n = _g.n;
    g = _g.g;
    edges = _g.edges;
  }

  graph() { }

  void clear() {
    n = 0;
    g.clear();
    edges.clear();
  }

  virtual int add(int v, int u, T w = 1) = 0;
};

template<typename T> class undigraph : public graph<T> {
  public:
  using graph<T>::n;
  using graph<T>::g;
  using graph<T>::edges;

  undigraph(int _n) : graph<T>(_n) { }

  undigraph(const undigraph<T>& _g) : graph<T>() {
    n = _g.n;
    g = _g.g;
    edges = _g.edges;
  }

  int add(int v, int u, T w = 1) {
    assert(v >= 0 && u >= 0 && v < n && u < n);
    int id = (int) edges.size();
    g[v].push_back(id);
    g[u].push_back(id);
    edges.push_back({v, u, w});
    return id;
  }
};

template<typename T> vector<T> djikstra(const undigraph<T>& g, int sv) {
  assert(sv < g.n);
  vector<T> res(g.n, numeric_limits<T>::max());
  vector<bool> vis(g.n);
  priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
  pq.emplace(0, sv);
  res[sv] = 0;
  while (!pq.empty()) {
    int v;
    T cost;
    tie(cost, v) = pq.top();
    pq.pop();
    if (vis[v]) {
      continue;
    }
    vis[v]  = true;
    for (auto id : g.g[v]) {
      int nxt = g.edges[id].u ^ g.edges[id].v ^ v;
      T nCost = cost + g.edges[id].w;
      if (vis[nxt] || res[nxt] < nCost) {
        continue;
      }
      res[nxt] = nCost;
      pq.emplace(nCost, nxt);
    }
  }
  return res;
}
 
int main () {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  undigraph<int> g(n);
  for (int i = 0; i < m; ++i) {
    int x, y, w;
    cin >> x >> y >> w;
    --x, --y;
    g.add(x, y, w);
  }
  vector<int> a(k), b(k);

  for (int i = 0; i < k; ++i) {
    cin >> a[i] >> b[i];
    --a[i], --b[i];
  }

  vector<vector<int>> dist(n);
  for (int i = 0; i < n; ++i) {
    dist[i] = djikstra(g, i);
  }
  int ans = INT_MAX;
  for (auto[u, v, foo] : g.edges) {
    int res = 0;
    for (int i = 0; i < k; ++i) {
      int cur = dist[a[i]][b[i]];
      cur = min(cur, dist[u][a[i]] + dist[v][b[i]]);
      cur = min(cur, dist[v][a[i]] + dist[u][b[i]]);
      res += cur;
    }     
    ans = min(ans, res);
  }
  cout << ans << '\n';
}