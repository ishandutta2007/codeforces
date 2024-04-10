#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  vector dp(n, 0);
  vector can_be_leaf(n, true);
  function<void(int, int)> dfs = [&](int par, int ver) {
    int child = 0, cnt = 0;
    for (int e : graph[ver]) {
      if (e == par) continue;
      dfs(ver, e);
      dp[ver] += dp[e];
      ++child;
      if (can_be_leaf[e]) ++cnt;
    }
    if (cnt < child || cnt % k != 0) can_be_leaf[ver] = false;
    dp[ver] += cnt / k;
  };
  dfs(-1, 0);
  int ans = 0;
  function<void(int, int, int, bool)> dfs2 = [&](int par, int ver, int root_dp, bool root_is_leaf) {
    int so = root_dp, child = graph[ver].size(), cnt = root_is_leaf;
    for (int e : graph[ver]) {
      if (e != par) {
        so += dp[e];
        cnt += can_be_leaf[e];
      }
    }
    chmax(ans, so + cnt / k);
    for (int e : graph[ver]) {
      if (e == par) continue;
      int nx = so - dp[e] + (cnt - can_be_leaf[e]) / k;
      dfs2(ver, e, nx, cnt - can_be_leaf[e] == child - 1 && (child - 1) % k == 0);
    }
  };
  dfs2(-1, 0, 0, false);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}