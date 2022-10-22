#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
template <typename T, typename U> inline void chmin(T &a, U b) { if (a > b) a = b; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
  }
} iosetup;

void solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> graph(n);
  FOR(i, 1, n) {
    int p; cin >> p; --p;
    graph[p].emplace_back(i);
  }
  vector<vector<vector<int>>> dp(n);
  vector<vector<vector<vector<pair<bool, int>>>>> path(n);
  auto f = [&](auto &&f, int ver) -> int {
    int sub = 1;
    vector tmp(graph[ver].size() + 1, vector(2, vector(2, 0)));
    vector prev(graph[ver].size() + 1, vector(2, vector(2, make_pair(false, -1))));
    REP(i, graph[ver].size()) {
      int e = graph[ver][i], child = f(f, e);
      REP(j, 2) tmp[i + 1][j].assign(sub + child + 1, INF);
      REP(j, 2) prev[i + 1][j].assign(sub + child + 1, {false, -1});
      REP(x, sub + 1) REP(j, 2) {
        if (tmp[i][j][x] < tmp[i + 1][j][x]) {
          tmp[i + 1][j][x] = tmp[i][j][x];
          prev[i + 1][j][x] = {j, x};
        }
        FOR(y, 1, child + 1) REP(k, 2) {
          if (j && k) continue;
          if (int nx = tmp[i][j][x] + dp[e][k][y] + (k ? 1 : 2); nx < tmp[i + 1][j | k][x + y]) {
            tmp[i + 1][j | k][x + y] = nx;
            prev[i + 1][j | k][x + y] = {j, x};
          }
        }
      }
      sub += child;
    }
    dp[ver] = tmp.back();
    path[ver].resize(2);
    REP(p, 2) {
      path[ver][p].resize(sub + 1);
      FOR(q, 1, sub + 1) {
        vector<pair<bool, int>> resto;
        bool j = p;
        int k = q;
        for (int i = graph[ver].size(); i > 0; --i) {
          auto [nx_j, nx_k] = prev[i][j][k];
          resto.emplace_back(j ^ nx_j, k - nx_k);
          j = nx_j;
          k = nx_k;
        }
        reverse(ALL(resto));
        path[ver][p][q] = resto;
      }
    }
    return sub;
  };
  f(f, 0);
  vector<int> ans;
  auto g = [&](auto &&g, int ver, bool j, int k) -> void {
    ans.emplace_back(ver);
    if (k == 1) return;
    int last = -1;
    REP(i, graph[ver].size()) {
      auto [p, q] = path[ver][j][k][i];
      if (q > 0) {
        if (p) {
          assert(j);
          last = i;
        } else {
          g(g, graph[ver][i], false, q);
          ans.emplace_back(ver);
        }
      }
    }
    if (last != -1) g(g, graph[ver][last], true, path[ver][j][k][last].second);
  };
  g(g, 0, true, k);
  assert(ans.size() == dp[0][true][k] + 1);
  cout << dp[0][true][k] << '\n';
  REP(i, dp[0][true][k] + 1) cout << ans[i] + 1 << " \n"[i + 1 == dp[0][true][k] + 1];
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}