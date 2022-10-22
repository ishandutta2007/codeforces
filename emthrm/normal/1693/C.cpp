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

int main() {
  int n, m; cin >> n >> m;
  vector<int> deg(n, 0);
  vector<vector<int>> graph(n);
  while (m--) {
    int v, u; cin >> v >> u; --v; --u;
    graph[u].emplace_back(v);
    ++deg[v];
  }
  vector<int> dist(n, INF), is_visited(n, false);
  dist[n - 1] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;
  que.emplace(dist[n - 1], n - 1);
  while (!que.empty()) {
    const int city = que.top().second; que.pop();
    if (is_visited[city]) continue;
    is_visited[city] = true;
    for (int e : graph[city]) {
      --deg[e];
      if (chmin(dist[e], dist[city] + deg[e] + 1)) que.emplace(dist[e], e);
    }
  }
  cout << dist[0] << '\n';
  return 0;
}