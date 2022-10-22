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
  vector<int> f(n + 1, -1);
  const auto dfs = [&](auto&& dfs, int par, int ver, int dep) -> int {
    vector<int> subtree{dep, dep};
    for (int e : graph[ver]) {
      if (e != par) subtree.emplace_back(dfs(dfs, ver, e, dep + 1));
    }
    sort(ALL(subtree), greater<int>());
    if (subtree[1] > 0) chmax(f[subtree[1] - 1], (subtree[0] + subtree[1] - dep * 2 + 1) / 2);
    return subtree.front();
  };
  const int far = dfs(dfs, -1, 0, 0);
  for (int i = n - 1; i >= 0; --i) chmax(f[i], f[i + 1]);
  // REP(i, n + 1) cout << f[i] << " \n"[i == n];
  int ans = 0;
  FOR(i, 1, n + 1) {
    while (ans < far && f[ans] + i > ans) ++ans;
    cout << ans << " \n"[i == n];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}