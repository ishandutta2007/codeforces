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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

template <typename CostType>
struct Edge {
  int src, dst;
  CostType cost;
  explicit Edge(const int src, const int dst, const CostType cost = 0)
      : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge& x) const {
    if (cost != x.cost) return cost < x.cost;
    return src != x.src ? src < x.src : dst < x.dst;
  }
  inline bool operator<=(const Edge& x) const { return !(x < *this); }
  inline bool operator>(const Edge& x) const { return x < *this; }
  inline bool operator>=(const Edge& x) const { return !(*this < x); }
};

template <typename CostType>
struct Dijkstra {
  const CostType inf;

  Dijkstra(const std::vector<std::vector<Edge<CostType>>>& graph,
           const CostType inf = std::numeric_limits<CostType>::max())
      : inf(inf), is_built(false), graph(graph) {}

  std::vector<CostType> build(const int s) {
    is_built = true;
    const int n = graph.size();
    std::vector<CostType> dist(n, inf);
    dist[s] = 0;
    prev.assign(n, -1);
    std::priority_queue<std::pair<CostType, int>,
                        std::vector<std::pair<CostType, int>>,
                        std::greater<std::pair<CostType, int>>> que;
    que.emplace(0, s);
    while (!que.empty()) {
      CostType d;
      int ver;
      std::tie(d, ver) = que.top();
      que.pop();
      if (d > dist[ver]) continue;
      for (const Edge<CostType>& e : graph[ver]) {
        if (dist[ver] + e.cost < dist[e.dst]) {
          dist[e.dst] = dist[ver] + e.cost;
          prev[e.dst] = ver;
          que.emplace(dist[e.dst], e.dst);
        }
      }
    }
    return dist;
  }

  std::vector<int> build_path(int t) const {
    assert(is_built);
    std::vector<int> res;
    for (; t != -1; t = prev[t]) {
      res.emplace_back(t);
    }
    std::reverse(res.begin(), res.end());
    return res;
  }

 private:
  bool is_built;
  std::vector<int> prev;
  std::vector<std::vector<Edge<CostType>>> graph;
};

template <typename T, bool IS_MINIMIZED = true>
struct ConvexHullTrick {
  ConvexHullTrick() = default;

  void add(T a, T b) {
    if (!IS_MINIMIZED) {
      a = -a;
      b = -b;
    }
    const Line line(a, b);
    if (deq.empty()) {
      deq.emplace_back(line);
    } else if (deq.back().first >= a) {
      if (deq.back().first == a) {
        if (b >= deq.back().second) return;
        deq.pop_back();
      }
      for (int i = static_cast<int>(deq.size()) - 2; i >= 0; --i) {
        if (!must_pop(deq[i], deq[i + 1], line)) break;
        deq.pop_back();
      }
      deq.emplace_back(line);
    } else {
      if (deq.front().first == a) {
        if (b >= deq.front().second) return;
        deq.pop_front();
      }
      while (deq.size() >= 2 && must_pop(line, deq.front(), deq[1])) {
        deq.pop_front();
      }
      deq.emplace_front(line);
    }
  }

  T query(const T x) const {
    // assert(!deq.empty());
    int lb = -1, ub = deq.size() - 1;
    while (ub - lb > 1) {
      const int mid = (lb + ub) >> 1;
      (f(deq[mid], x) < f(deq[mid + 1], x) ? ub : lb) = mid;
    }
    return IS_MINIMIZED ? f(deq[ub], x) : -f(deq[ub], x);
  }

  T monotonically_increasing_query(const T x) {
    while (deq.size() >= 2 && f(deq.front(), x) >= f(deq[1], x)) {
      deq.pop_front();
    }
    return IS_MINIMIZED ? f(deq.front(), x) : -f(deq.front(), x);
  }

  T monotonically_decreasing_query(const T x) {
    for (int i = static_cast<int>(deq.size()) - 2; i >= 0; --i) {
      if (f(deq[i], x) > f(deq[i + 1], x)) break;
      deq.pop_back();
    }
    return IS_MINIMIZED ? f(deq.back(), x) : -f(deq.back(), x);
  }

 private:
  using Line = std::pair<T, T>;

  std::deque<Line> deq;

  using Real = long double;
  bool must_pop(const Line& l1, const Line& l2, const Line& l3) const {
    // const Real lhs =
    //     static_cast<Real>(l3.second - l2.second) / (l2.first - l3.first);
    // const Real rhs =
    //     static_cast<Real>(l2.second - l1.second) / (l1.first - l2.first);
    // return lhs <= rhs;
    const T lhs_num = l3.second - l2.second, lhs_den = l2.first - l3.first;
    const T rhs_num = l2.second - l1.second, rhs_den = l1.first - l2.first;
    return __int128(lhs_num) * rhs_den <= __int128(rhs_num) * lhs_den;
  }

  T f(const Line& l, const T x) const { return l.first * x + l.second; }
};

int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<Edge<ll>>> graph(n + 1);
  graph[n].reserve(n);
  while (m--) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    graph[u].emplace_back(u, v, w);
    graph[v].emplace_back(v, u, w);
  }
  vector<ll> dist = Dijkstra(graph).build(0);
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
  while (k--) {
    ConvexHullTrick<ll> convex_hull_trick;
    REP(i, n) {
      if (dist[i] == numeric_limits<ll>::max()) continue;
      convex_hull_trick.add(-2 * i, dist[i] + 1LL * i * i);
    }
    graph[n].clear();
    REP(i, n) graph[n].emplace_back(n, i, convex_hull_trick.monotonically_increasing_query(i) + 1LL * i * i);
    dist = Dijkstra(graph).build(n);
  }
  REP(i, n) cout << dist[i] << " \n"[i + 1 == n];
  return 0;
}