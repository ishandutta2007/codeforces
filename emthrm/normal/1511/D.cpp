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

std::vector<int> eulerian_trail_in_directed_graph(const std::vector<std::vector<int>> &graph, int s = -1) {
  int n = graph.size(), edges = 0;
  std::vector<std::vector<int>> tmp(graph);
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    deg[i] += tmp[i].size();
    for (int e : tmp[i]) --deg[e];
    edges += tmp[i].size();
  }
  int not0 = n - std::count(deg.begin(), deg.end(), 0);
  if (s == -1) {
    for (int i = 0; i < n; ++i) {
      if (not0 == 0) {
        if (!tmp[i].empty()) {
          s = i;
          break;
        }
      } else if (not0 == 2) {
        if (deg[i] == 1) {
          s = i;
          break;
        }
      }
    }
    if (s == -1) return {};
  }
  if (not0 == 0 || (not0 == 2 && deg[s] == 1)) {
    std::vector<int> res;
    std::function<void(int)> dfs = [&tmp, &res, &dfs](int ver) {
      while (!tmp[ver].empty()) {
        int nx = tmp[ver].back();
        tmp[ver].pop_back();
        dfs(nx);
      }
      res.emplace_back(ver);
    };
    dfs(s);
    if (res.size() == edges + 1) {
      std::reverse(res.begin(), res.end());
      return res;
    }
  }
  return {};
}

int main() {
  int n, k; cin >> n >> k;
  vector<vector<int>> graph(k);
  REP(i, k) REP(j, k) graph[i].emplace_back(j);
  vector<int> s = eulerian_trail_in_directed_graph(graph, 0);
  assert(!s.empty());
  s.pop_back();
  REP(i, n) cout << char('a' + s[i % s.size()]);
  cout << '\n';
  return 0;
}