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
  int n, m; cin >> n >> m;
  vector<vector<Edge<int>>> graph(n);
  while (m--) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    graph[u].emplace_back(u, v, w);
    graph[v].emplace_back(v, u, w);
  }
  vector dist(2, vector(2, vector(n, LINF)));
  dist[false][false][0] = 0;
  using P = pair<ll, tuple<bool, bool, int>>;
  priority_queue<P, vector<P>, greater<P>> que;
  que.emplace(0, make_tuple(false, false, 0));
  while (!que.empty()) {
    auto [cost, ijk] = que.top(); que.pop();
    auto [i, j, k] = ijk;
    if (cost > dist[i][j][k]) continue;
    for (const auto &e : graph[k]) {
      if (dist[i][j][e.dst] > cost + e.cost) {
        dist[i][j][e.dst] = cost + e.cost;
        que.emplace(dist[i][j][e.dst], make_tuple(i, j, e.dst));
      }
      if (!i && dist[true][j][e.dst] > cost + e.cost * 2) {
        dist[true][j][e.dst] = cost + e.cost * 2;
        que.emplace(dist[true][j][e.dst], make_tuple(true, j, e.dst));
      }
      if (!j && dist[i][true][e.dst] > cost) {
        dist[i][true][e.dst] = cost;
        que.emplace(dist[i][true][e.dst], make_tuple(i, true, e.dst));
      }
      if (!i && !j && dist[true][true][e.dst] > cost + e.cost) {
        dist[true][true][e.dst] = cost + e.cost;
        que.emplace(dist[true][true][e.dst], make_tuple(true, true, e.dst));
      }
    }
  }
  FOR(i, 1, n) cout << dist[true][true][i] << " \n"[i + 1 == n];
  return 0;
}