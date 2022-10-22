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

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<int> x(m), y(m); REP(i, m) cin >> x[i] >> y[i], --x[i], --y[i];
    int ans = INF;
    auto solve = [&]() {
      vector<int> id(n, -1);
      REP(i, m) id[x[i]] = i;
      vector<vector<int>> graph(m);
      vector<int> deg(m, 0);
      REP(i, m) {
        if (x[i] != y[i] && id[y[i]] != -1) {
          graph[i].emplace_back(id[y[i]]);
          ++deg[id[y[i]]];
        }
      }
      int res = 0;
      vector<bool> visited(m, false);
      REP(i, m) {
        if (x[i] != y[i] && deg[i] == 0) {
          ++res;
          visited[i] = true;
          if (!graph[i].empty()) {
            int pos = graph[i][0];
            ++res;
            visited[pos] = true;
            while (!graph[pos].empty()) {
              pos = graph[pos][0];
              ++res;
              visited[pos] = true;
              if (pos == i) break;
            }
          }
        }
      }
      REP(i, m) {
        if (x[i] != y[i] && !visited[i]) {
          ++res;
          visited[i] = true;
          assert(!graph[i].empty());
          int pos = graph[i][0];
          ++res;
          visited[pos] = true;
          while (!graph[pos].empty()) {
            pos = graph[pos][0];
            ++res;
            visited[pos] = true;
            if (pos == i) break;
          }
        }
      }
      chmin(ans, res);
    };
    solve();
    swap(x, y);
    solve();
    cout << ans << '\n';
  }
  return 0;
}