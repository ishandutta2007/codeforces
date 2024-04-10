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

template <typename Band>
struct SparseTable {
  using Fn = std::function<Band(Band, Band)>;

  SparseTable() = default;

  explicit SparseTable(const std::vector<Band>& a, const Fn fn) { init(a, fn); }

  void init(const std::vector<Band>& a, const Fn fn_) {
    fn = fn_;
    int n = a.size(), table_h = 0;
    lg.assign(n + 1, 0);
    for (int i = 2; i <= n; ++i) {
      lg[i] = lg[i >> 1] + 1;
    }
    while ((1 << table_h) <= n) ++table_h;
    data.assign(table_h, std::vector<Band>(n));
    std::copy(a.begin(), a.end(), data.front().begin());
    for (int i = 1; i < table_h; ++i) {
      for (int j = 0; j + (1 << i) <= n; ++j) {
        data[i][j] = fn(data[i - 1][j], data[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  Band query(const int left, const int right) const {
    assert(left < right);
    const int h = lg[right - left];
    return fn(data[h][left], data[h][right - (1 << h)]);
  }

 private:
  Fn fn;
  std::vector<int> lg;
  std::vector<std::vector<Band>> data;
};

struct EulerTour {
  std::vector<int> tour, depth, left, right, down, up;

  explicit EulerTour(const std::vector<std::vector<int>>& graph,
                     const int root = 0)
      : graph(graph) {
    const int n = graph.size();
    left.resize(n);
    right.resize(n);
    down.assign(n, -1);
    up.assign(n, (n - 1) << 1);
    int idx = 0;
    dfs(-1, root, 0, &idx);
  }

  template <typename Fn>
  void update_v(const int ver, const Fn f) const {
    f(left[ver], right[ver] + 1);
  }

  template <typename T, typename Fn>
  T query_v(const int ver, const Fn f) const {
    return f(left[ver], right[ver] + 1);
  }

  template <typename T, typename Fn>
  T query_e(const int u, const int v, const Fn f) const {
    return f(down[u] + 1, down[v] + 1);
  }

  template <typename Fn>
  void update_subtree_e(const int ver, const Fn f) const {
    f(down[ver] + 1, up[ver]);
  }

  template <typename T, typename Fn>
  T query_subtree_e(const int ver, const Fn f) const {
    return f(down[ver] + 1, up[ver]);
  }

 private:
  const std::vector<std::vector<int>> graph;

  void dfs(const int par, const int ver, int cur_depth, int* idx) {
    left[ver] = tour.size();
    tour.emplace_back(ver);
    depth.emplace_back(cur_depth);
    for (const int e : graph[ver]) {
      if (e != par) {
        down[e] = (*idx)++;
        dfs(ver, e, cur_depth + 1, idx);
        tour.emplace_back(ver);
        depth.emplace_back(cur_depth);
        up[e] = (*idx)++;
      }
    }
    right[ver] = tour.size() - 1;
  }
};

struct LowestCommonAncestor : EulerTour {
  explicit LowestCommonAncestor(const std::vector<std::vector<int>>& graph,
                                const int root = 0)
      : EulerTour(graph, root) {
    const int n = this->tour.size();
    std::vector<std::pair<int, int>> nodes(n);
    for (int i = 0; i < n; ++i) {
      nodes[i] = {this->depth[i], this->tour[i]};
    }
    sparse_table.init(
        nodes,
        [](const std::pair<int, int>& a, const std::pair<int, int>& b)
            -> std::pair<int, int> {
          return std::min(a, b);
        });
  }

  int query(int u, int v) const {
    u = this->left[u];
    v = this->left[v];
    if (u > v) std::swap(u, v);
    return sparse_table.query(u, v + 1).second;
  }

 private:
  SparseTable<std::pair<int, int>> sparse_table;
};

// https://atcoder.jp/contests/nadafes2022_day1/tasks/nadafes2022_day1_h
void solve() {
  int n, k, x, y; cin >> n >> k >> x >> y; --x, --y;
  vector<int> a(k + 2); REP(i, k) cin >> a[i], --a[i];
  a[k] = x;
  a[k + 1] = y;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  LowestCommonAncestor euler_tour(graph);
  sort(ALL(a), [&](int l, int r) -> bool { return euler_tour.left[l] < euler_tour.left[r]; });
  a.erase(unique(ALL(a)), a.end());
  auto dist = [&](int u, int v) -> int {
    return euler_tour.depth[euler_tour.left[u]] + euler_tour.depth[euler_tour.left[v]] - euler_tour.depth[euler_tour.left[euler_tour.query(u, v)]] * 2;
  };
  ll ans = -dist(x, y);
  REP(i, a.size()) ans += dist(a[i], a[(i + 1) % a.size()]);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}