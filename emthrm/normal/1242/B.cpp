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

template <typename CostType>
UnionFind connencted_component_of_complement_graph(const std::vector<std::vector<Edge<CostType>>> &graph) {
  int n = graph.size();
  UnionFind uf(n);
  auto check = [&graph, n, &uf](int ver) -> void {
    std::vector<bool> adj(n, false);
    for (const Edge<CostType> &e : graph[ver]) adj[e.dst] = true;
    for (int i = 0; i < n; ++i) {
      if (!adj[i]) uf.unite(ver, i);
    }
  };
  int argmin_deg = 0;
  for (int i = 1; i < n; ++i) {
    if (graph[i].size() < graph[argmin_deg].size()) argmin_deg = i;
  }
  check(argmin_deg);
  for (const Edge<CostType> &e : graph[argmin_deg]) check(e.dst);
  return uf;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<Edge<bool>>> graph(n);
  while (m--) {
    int a, b;
    std::cin >> a >> b;
    --a; --b;
    graph[a].emplace_back(a, b);
    graph[b].emplace_back(b, a);
  }
  UnionFind uf = connencted_component_of_complement_graph(graph);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    ans += uf.root(i) == i;
  }
  std::cout << ans - 1 << '\n';
  return 0;
}