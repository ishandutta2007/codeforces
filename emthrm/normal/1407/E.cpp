#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr ll LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
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
    int u, v, t; cin >> u >> v >> t; --u; --v;
    graph[v].emplace_back(v, u, t);
  }
  vector<int> dist(n, -1), ans(n, -1);
  dist[n - 1] = 0;
  queue<int> que({n - 1});
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (const Edge<int> &e : graph[ver]) {
      if (dist[e.dst] == -1) {
        if (ans[e.dst] == -1) {
          ans[e.dst] = e.cost ^ 1;
        } else if (ans[e.dst] == e.cost) {
          dist[e.dst] = dist[ver] + 1;
          que.emplace(e.dst);
        }
      }
    }
  }
  cout << dist[0] << '\n';
  REP(i, n) cout << (ans[i] == -1 ? 0 : ans[i]);
  cout << '\n';
  return 0;
}