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

void solve() {
  int n; cin >> n;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  auto f = [&](auto&& f, int par, int ver) -> pair<int, int> {
    if (auto it = find(ALL(graph[ver]), par); it != graph[ver].end()) graph[ver].erase(it);
    if (graph[ver].empty()) return {0, 1};
    if (graph[ver].size() == 1) {
      const int c = f(f, ver, graph[ver].front()).second;
      return {c - 1, c + 1};
    }
    const auto [x1, y1] = f(f, ver, graph[ver][0]);
    const auto [x2, y2] = f(f, ver, graph[ver][1]);
    return {max(x1 + y2 - 1, x2 + y1 - 1), y1 + y2 + 1};
  };
  cout << f(f, -1, 0).first << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}