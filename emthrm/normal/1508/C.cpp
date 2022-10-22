#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename CostType>
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &x) const {
    return cost != x.cost ? cost < x.cost : dst != x.dst ? dst < x.dst : src < x.src;
  }
  inline bool operator<=(const Edge &x) const { return !(x < *this); }
  inline bool operator>(const Edge &x) const { return x < *this; }
  inline bool operator>=(const Edge &x) const { return !(*this < x); }
};

struct UnionFind {
  UnionFind(int n) : data(n, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool same(int u, int v) { return root(u) == root(v); }

  int size(int ver) { return -data[root(ver)]; }

private:
  std::vector<int> data;
};

int main() {
  int n, m; cin >> n >> m;
  if (n == 2) {
    cout << 0 << '\n';
    return 0;
  }
  vector<Edge<int>> edge;
  int x = 0;
  REP(_, m) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    if (u > v) swap(u, v);
    edge.emplace_back(u, v, w);
    x ^= w;
  }
  sort(ALL(edge));
  if (n * (n - 1LL) / 2 - m < n) {
    vector graph(n, vector(n, false));
    for (auto [u, v, _] : edge) graph[u][v] = true;
    UnionFind uf(n);
    bool has_loop = false;
    REP(i, n) FOR(j, i + 1, n) {
      if (!graph[i][j]) has_loop |= !uf.unite(i, j);
    }
    ll ans = 0;
    for (auto [u, v, w] : edge) {
      if (uf.unite(u, v)) ans += w;
    }
    if (!has_loop) {
      ans += x;
      vector<pair<int, int>> w0;
      REP(i, n) FOR(j, i + 1, n) {
        if (!graph[i][j]) w0.emplace_back(i, j);
      }
      const int w0_size = w0.size();
      REP(i, w0_size) {
        UnionFind uf2(n);
        REP(j, w0_size) {
          if (j != i) uf2.unite(w0[j].first, w0[j].second);
        }
        ll cost = 0;
        for (int j = 0; j < m && uf2.size(0) < n; ++j) {
          if (uf2.unite(edge[j].src, edge[j].dst)) cost += edge[j].cost;
        }
        chmin(ans, cost);
      }
    }
    cout << ans << '\n';
  } else {
    vector<vector<int>> graph(n);
    for (auto [u, v, _] : edge) {
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    }
    set<int> rem;
    REP(i, n) rem.emplace(i);
    UnionFind uf(n);
    REP(i, n) {
      if (rem.count(i) == 0) continue;
      rem.erase(i);
      queue<int> que({i});
      while (!que.empty()) {
        int ver = que.front(); que.pop();
        sort(ALL(graph[ver]));
        int prev = -1;
        for (int nxt : graph[ver]) {
          for (auto it = rem.upper_bound(prev); it != rem.end() && *it < nxt; it = rem.erase(it)) {
            uf.unite(i, *it);
            que.emplace(*it);
          }
          prev = nxt;
        }
        for (auto it = rem.upper_bound(prev); it != rem.end(); it = rem.erase(it)) {
          uf.unite(i, *it);
          que.emplace(*it);
        }
      }
    }
    ll ans = 0;
    for (auto [u, v, w] : edge) {
      if (uf.unite(u, v)) ans += w;
    }
    cout << ans << '\n';
  }
  return 0;
}