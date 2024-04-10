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

struct UnionFind {
  explicit UnionFind(const int n) : data(n, -1) {}

  int root(const int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) { return root(u) == root(v); }

  int size(const int ver) { return -data[root(ver)]; }

 private:
  std::vector<int> data;
};

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

void solve() {
  int n, m, q; cin >> n >> m >> q;
  vector<int> u(m), v(m); REP(i, m) cin >> u[i] >> v[i], --u[i], --v[i];
  vector<int> lb(n - 1, -1), ub(n - 1, m - 1);
  while (true) {
    vector<vector<int>> queries(m);
    bool is_finished = true;
    REP(i, n - 1) {
      if (lb[i] + 1 < ub[i]) {
        queries[(lb[i] + ub[i]) / 2].emplace_back(i);
        is_finished = false;
      }
    }
    if (is_finished) break;
    UnionFind union_find(n);
    REP(i, m) {
      union_find.unite(u[i], v[i]);
      for (const int id : queries[i]) {
        (union_find.is_same(id, id + 1) ? ub : lb)[id] = i;
      }
    }
  }
  SparseTable<int> sparse_table(ub, [](const int a, const int b) -> int { return max(a, b); });
  while (q--) {
    int l, r; cin >> l >> r; --l; --r;
    cout << (l == r ? 0 : sparse_table.query(l, r) + 1) << " \n"[q == 0];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}