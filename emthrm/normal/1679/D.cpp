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
  int n, m; ll k; cin >> n >> m >> k;
  vector<int> a(n), u(m), v(m);
  REP(i, n) cin >> a[i];
  REP(i, m) cin >> u[i] >> v[i], --u[i], --v[i];
  int lb = *min_element(ALL(a)) - 1, ub = *max_element(ALL(a)) + 1;
  while (ub - lb > 1) {
    const int mid = (lb + ub) / 2;
    vector<vector<int>> graph(n);
    REP(i, m) {
      if (a[u[i]] <= mid && a[v[i]] <= mid) graph[u[i]].emplace_back(v[i]);
    }
    const vector<int> order = topological_sort(graph);
    if (order.empty()) {
      ub = mid;
      continue;
    }
    vector<int> dp(n, 1);
    for (int i : order) {
      for (int j : graph[i]) chmax(dp[j], dp[i] + 1);
    }
    (*max_element(ALL(dp)) >= k ? ub : lb) = mid;
  }
  cout << (ub == *max_element(ALL(a)) + 1 ? -1 : ub) << '\n';
  return 0;
}