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

std::vector<int> topological_sort(const std::vector<std::vector<int>>& graph) {
  const int n = graph.size();
  std::vector<int> deg(n, 0);
  for (int i = 0; i < n; ++i) {
    for (const int e : graph[i]) ++deg[e];
  }
  std::queue<int> que;
  for (int i = 0; i < n; ++i) {
    if (deg[i] == 0) que.emplace(i);
  }
  std::vector<int> res;
  res.reserve(n);
  while (!que.empty()) {
    const int ver = que.front();
    que.pop();
    res.emplace_back(ver);
    for (const int e : graph[ver]) {
      if (--deg[e] == 0) que.emplace(e);
    }
  }
  return res.size() == n ? res : std::vector<int>{};
}

int main() {
  int n, m; cin >> n >> m;
  vector<int> u(m), v(m); REP(i, m) cin >> u[i] >> v[i], --u[i], --v[i];
  vector<vector<int>> in(n), out(n);
  REP(i, m) {
    in[v[i]].emplace_back(i);
    out[u[i]].emplace_back(i);
  }
  vector<int> must_remove(m, false);
  REP(i, n) {
    if (in[i].size() == 1) must_remove[in[i].front()] = true;
    if (out[i].size() == 1) must_remove[out[i].front()] = true;
  }
  vector<vector<int>> graph(n);
  REP(i, m) {
    if (!must_remove[i]) graph[u[i]].emplace_back(v[i]);
  }
  vector<int> dp(n, 1);
  for (int i : topological_sort(graph)) {
    for (int j : graph[i]) chmax(dp[j], dp[i] + 1);
  }
  cout << *max_element(ALL(dp)) << '\n';
  return 0;
}