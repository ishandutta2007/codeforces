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
  int root = -1;
  REP(i, n) {
    int p; cin >> p; --p;
    if (p != i) {
      graph[p].emplace_back(i);
    } else {
      root = i;
    }
  }
  vector<vector<int>> ans;
  auto f = [&](auto&& f, int ver, vector<int>& path) -> void {
    path.emplace_back(ver);
    if (graph[ver].empty()) {
      ans.emplace_back(path);
    } else {
      f(f, graph[ver].front(), path);
      FOR(i, 1, graph[ver].size()) {
        vector<int> child;
        f(f, graph[ver][i], child);
      }
    }
  };
  vector<int> path;
  f(f, root, path);
  cout << ans.size() << '\n';
  for (const vector<int>& path : ans) {
    const int l = path.size();
    cout << l << '\n';
    REP(i, l) cout << path[i] + 1 << " \n"[i + 1 == l];
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}