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
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
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
  vector<int> dep[2]{};
  auto f = [&](auto&& f, int par, int ver, int d) -> void {
    dep[d].emplace_back(ver);
    for (int e : graph[ver]) {
      if (e != par) f(f, ver, e, d ^ 1);
    }
  };
  f(f, -1, 0, 0);
  vector<vector<int>> msb;
  for (int node = 1; node <= n;) {
    const int nx = min(node * 2, n + 1);
    msb.emplace_back();
    FOR(i, node, nx) msb.back().emplace_back(i);
    node = nx;
  }
  sort(ALL(msb), [](const vector<int>& a, const vector<int>& b) -> bool { return a.size() > b.size(); });
  vector<int> ans(n, 0);
  for (vector<int>& v : msb) {
    REP(idx, 2) {
      if (dep[idx].size() >= v.size()) {
        while (!v.empty()) {
          ans[dep[idx].back()] = v.back();
          dep[idx].pop_back();
          v.pop_back();
        }
      }
    }
  }
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}