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

bool is_bipartite(const std::vector<std::vector<int>> &graph, std::vector<int> &color) {
  int n = graph.size();
  color.assign(n, -1);
  std::function<bool(int, int)> dfs = [&graph, &color, &dfs](int ver, int now) -> bool {
    color[ver] = now;
    for (int e : graph[ver]) {
      if (color[e] == now || (color[e] == -1 && !dfs(e, now ^ 1))) return false;
    }
    return true;
  };
  for (int i = 0; i < n; ++i) {
    if (color[i] == -1 && !dfs(i, 0)) return false;
  }
  return true;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<ll> t(n); REP(i, n) cin >> t[i];
  REP(i, n) {
    int ti; cin >> ti;
    t[i] = ti - t[i];
  }
  vector<vector<int>> graph(n);
  while (m--) {
    int i, j; cin >> i >> j; --i; --j;
    graph[i].emplace_back(j);
    graph[j].emplace_back(i);
  }
  if (accumulate(ALL(t), 0LL) & 1) {
    cout << "NO\n";
    return;
  }
  vector<int> color;
  if (is_bipartite(graph, color)) {
    ll diff = 0;
    REP(i, n) diff += t[i] * (color[i] == 1 ? 1 : -1);
    if (diff != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}