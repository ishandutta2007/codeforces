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

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> graph(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
  }
  vector<int> d(n, -1), ans(n, -1);
  d[0] = ans[0] = 0;
  queue<int> que({0});
  vector<int> ord{0};
  while (!que.empty()) {
    int v = que.front(); que.pop();
    ord.emplace_back(v);
    for (int e : graph[v]) {
      if (d[e] == -1) {
        d[e] = ans[e] = d[v] + 1;
        que.emplace(e);
      } else {
        chmin(ans[v], d[e]);
      }
    }
  }
  reverse(ALL(ord));
  for (int v : ord) {
    for (int e : graph[v]) {
      if (d[e] > d[v]) chmin(ans[v], ans[e]);
    }
  }
  REP(i, n) cout << ans[i] << " \n"[i + 1 == n];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}