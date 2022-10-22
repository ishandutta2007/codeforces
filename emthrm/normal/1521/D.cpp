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
  int n; cin >> n;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector<int> dp[3], memo[3];
  vector<map<int, int>> mome(n);
  REP(i, 3) {
    dp[i].assign(n, INF);
    memo[i].assign(n, -1);
  }
  auto f = [&](auto &&f, int par, int ver) -> void {
    dp[0][ver] = 0;
    vector<pair<int, int>> diff;
    for (int e : graph[ver]) {
      if (e != par) {
        f(f, ver, e);
        int least = min({dp[0][e], dp[1][e], dp[2][e]});
        REP(i, 3) {
          if (least == dp[i][e]) mome[ver][e] = i;
        }
        dp[0][ver] += least + 1;
        diff.emplace_back(dp[1][e] - (least + 1), e);
      }
    }
    sort(ALL(diff));
    dp[1][ver] = dp[0][ver];
    if (!diff.empty()) {
      dp[1][ver] += diff.front().first;
      memo[1][ver] = diff.front().second;
    }
    if (diff.size() >= 2) {
      dp[2][ver] = dp[1][ver] + diff[1].first;
      memo[2][ver] = diff[1].second;
    }
  };
  f(f, -1, 0);
  // REP(i, n) REP(j, 3) cout << dp[j][i] << " \n"[j + 1 == 3];
  vector<pair<int, int>> era, chain;
  vector<tuple<int, int, int>> root;
  int j = 0;
  FOR(i, 1, 3) {
    if (dp[i][0] < dp[j][0]) j = i;
  }
  root.emplace_back(-1, 0, j);
  while (!root.empty()) {
    auto [par, r, j] = root.back();
    root.pop_back();
    vector<int> ed;
    if (j == 0 || j == 1) ed.emplace_back(r);
    auto g = [&](auto &&g, int par, int ver, int j) -> void {
      if (j == 0) {
        for (int e : graph[ver]) {
          if (e != par) {
            era.emplace_back(ver, e);
            root.emplace_back(ver, e, mome[ver][e]);
          }
        }
        ed.emplace_back(ver);
      } else if (j == 1) {
        for (int e : graph[ver]) {
          if (e == par) continue;
          if (e == memo[1][ver]) {
            g(g, ver, e, 1);
          } else {
            era.emplace_back(ver, e);
            root.emplace_back(ver, e, mome[ver][e]);
          }
        }
        if (memo[1][ver] == -1) ed.emplace_back(ver);
      } else if (j == 2) {
        for (int e : graph[ver]) {
          if (e == par) continue;
          if (e == memo[1][ver] || e == memo[2][ver]) {
            g(g, ver, e, 1);
          } else {
            era.emplace_back(ver, e);
            root.emplace_back(ver, e, mome[ver][e]);
          }
        }
      }
    };
    g(g, par, r, j);
    assert(ed.size() == 2);
    chain.emplace_back(ed[0], ed[1]);
  }
  assert(era.size() == dp[j][0]);
  cout << dp[j][0] << '\n';
  REP(i, dp[j][0]) cout << era[i].first + 1 << ' ' << era[i].second + 1 << ' ' << chain[i].second + 1 << ' ' << chain[i + 1].first + 1 << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}