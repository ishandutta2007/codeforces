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

struct TwoSat {
  TwoSat(int n) : n(n), graph(n << 1), rev_graph(n << 1) {}

  int negate(int x) const { return (n + x) % (n << 1); }

  void add_or(int x, int y) {
    graph[negate(x)].emplace_back(y);
    graph[negate(y)].emplace_back(x);
    rev_graph[y].emplace_back(negate(x));
    rev_graph[x].emplace_back(negate(y));
  }

  void add_if(int x, int y) { add_or(negate(x), y); }

  void add_nand(int x, int y) { add_or(negate(x), negate(y)); }

  void set_true(int x) { add_or(x, x); }

  void set_false(int x) { set_true(negate(x)); }

  std::vector<bool> build() {
    used.assign(n << 1, false);
    id.assign(n << 1, -1);
    order.clear();
    for (int i = 0; i < (n << 1); ++i) {
      if (!used[i]) dfs(i);
    }
    int now = 0;
    for (int i = (n << 1) - 1; i >= 0; --i) {
      if (id[order[i]] == -1) rev_dfs(order[i], now++);
    }
    std::vector<bool> res(n);
    for (int i = 0; i < n; ++i) {
      if (id[i] == id[negate(i)]) return {};
      res[i] = id[negate(i)] < id[i];
    }
    return res;
  }

private:
  int n;
  std::vector<std::vector<int>> graph, rev_graph;
  std::vector<bool> used;
  std::vector<int> id, order;

  void dfs(int ver) {
    used[ver] = true;
    for (int e : graph[ver]) {
      if (!used[e]) dfs(e);
    }
    order.emplace_back(ver);
  }

  void rev_dfs(int ver, int now) {
    id[ver] = now;
    for (int e : rev_graph[ver]) {
      if (id[e] == -1) rev_dfs(e, now);
    }
  }
};

void solve() {
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  REP(i, n) REP(j, n) {
    char c; cin >> c;
    a[i][j] = c - '0';
  }
  REP(i, n) REP(j, n) {
    char c; cin >> c;
    a[i][j] ^= c - '0';
  }
  TwoSat ts(n * 2);
  REP(i, n) REP(j, n) {
    if (a[i][j]) {
      ts.add_or(i, n + j);
      ts.add_nand(i, n + j);
    } else {
      ts.add_if(i, n + j);
      ts.add_if(n + j, i);
    }
  }
  cout << (ts.build().empty() ? "NO\n" : "YES\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}