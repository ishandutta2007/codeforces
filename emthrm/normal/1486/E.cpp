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

template <typename CostType>
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &x) const {
    return cost != x.cost ? cost < x.cost : dst != x.dst ? dst < x.dst : src < x.src;
  }
  inline bool operator<=(const Edge &x) const { return !(x < *this); }
  inline bool operator>(const Edge &x) const { return x < *this; }
  inline bool operator>=(const Edge &x) const { return !(*this < x); }
};

int main() {
  constexpr int X = 50;
  int n, m; cin >> n >> m;
  vector<vector<Edge<int>>> graph(n);
  while (m--) {
    int v, u, w; cin >> v >> u >> w; --v; --u;
    graph[v].emplace_back(v, u, w);
    graph[u].emplace_back(u, v, w);
  }
  vector dist(n, vector(X + 1, LINF));
  dist[0][0] = 0;
  using P = pair<ll, pair<int, int>>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.emplace(0, make_pair(0, 0));
  while (!que.empty()) {
    auto [cost, ij] = que.top(); que.pop();
    auto [i, j] = ij;
    if (cost > dist[i][j]) continue;
    for (const Edge<int> &e : graph[i]) {
      ll nx = dist[i][j] + e.cost * e.cost;
      if (j == 0) {
        if (dist[e.dst][e.cost] > nx) {
          dist[e.dst][e.cost] = nx;
          que.emplace(nx, make_pair(e.dst, e.cost));
        }
      } else {
        nx += 2 * j * e.cost;
        if (dist[e.dst][0] > nx) {
          dist[e.dst][0] = nx;
          que.emplace(nx, make_pair(e.dst, 0));
        }
      }
    }
  }
  REP(i, n) cout << (dist[i][0] == LINF ? -1 : dist[i][0]) << " \n"[i + 1 == n];
  return 0;
}