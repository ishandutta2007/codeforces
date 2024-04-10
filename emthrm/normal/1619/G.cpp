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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

struct UnionFind {
  UnionFind(const int n) : data(n, -1) {}

  int root(const int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) {
      std::swap(u, v);
    }
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) {
    return root(u) == root(v);
  }

  int size(const int ver) {
    return -data[root(ver)];
  }

private:
  std::vector<int> data;
};

void solve() {
  int n, k; cin >> n >> k;
  vector<int> x(n), y(n), timer(n); REP(i, n) cin >> x[i] >> y[i] >> timer[i];
  map<int, vector<int>> row, col;
  REP(i, n) {
    row[y[i]].emplace_back(i);
    col[x[i]].emplace_back(i);
  }
  UnionFind uf(n);
  for (auto [_, mines] : row) {
    sort(ALL(mines), [&](int a, int b) -> bool { return x[a] < x[b]; });
    FOR(i, 1, mines.size()) {
      if (x[mines[i]] - x[mines[i - 1]] <= k) uf.unite(mines[i - 1], mines[i]);
    }
  }
  for (auto [_, mines] : col) {
    sort(ALL(mines), [&](int a, int b) -> bool { return y[a] < y[b]; });
    FOR(i, 1, mines.size()) {
      if (y[mines[i]] - y[mines[i - 1]] <= k) uf.unite(mines[i - 1], mines[i]);
    }
  }
  map<int, int> early;
  REP(i, n) {
    if (early.count(uf.root(i)) == 0) early[uf.root(i)] = INF;
    chmin(early[uf.root(i)], timer[i]);
  }
  vector<int> mines;
  for (const auto [_, t] : early) mines.emplace_back(t);
  sort(ALL(mines));
  for (int f = 0, t = 0; ; ++t) {
    mines.pop_back();
    while (f < mines.size() && mines[f] <= t) ++f;
    if (f >= mines.size()) {
      cout << t << '\n';
      return;
    }
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}