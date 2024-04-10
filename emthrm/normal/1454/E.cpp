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
  REP(_, n) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<int> loop{0};
  vector<bool> visited(n, false);
  visited[0] = true;
  auto dfs = [&](auto &dfs, int par, int ver) -> bool {
    for (int e : graph[ver]) {
      if (e == par) continue;
      if (visited[e]) {
        vector<int> tmp;
        while (loop.back() != e) {
          tmp.emplace_back(loop.back());
          loop.pop_back();
        }
        tmp.emplace_back(e);
        loop.swap(tmp);
        return true;
      } else {
        loop.emplace_back(e);
        visited[e] = true;
        if (dfs(dfs, ver, e)) return true;
        loop.pop_back();
      }
    }
    return false;
  };
  dfs(dfs, -1, 0);
  ll in_loop = loop.size(), out_of_loop = n - in_loop;
  vector<bool> is_in_loop(n, false);
  for (int e : loop) is_in_loop[e] = true;
  fill(ALL(visited), false);
  ll ans = in_loop * (in_loop - 1);
  auto solve = [&](int root) {
    ll cnt = 0;
    queue<int> que({root});
    while (!que.empty()) {
      int ver = que.front(); que.pop();
      for (int e : graph[ver]) {
        if (!is_in_loop[e] && !visited[e]) {
          ++cnt;
          visited[e] = true;
          que.emplace(e);
        }
      }
    }
    ans += cnt * (cnt - 1) / 2;
    ans += cnt + (in_loop - 1) * cnt * 2;
    ans += cnt * (out_of_loop - cnt);
  };
  for (int e : loop) solve(e);
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}