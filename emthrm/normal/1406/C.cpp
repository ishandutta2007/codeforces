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

template <typename CostType>
std::vector<int> centroid(const std::vector<std::vector<Edge<CostType>>> &graph) {
  int n = graph.size();
  std::vector<int> subtree(n, 1), res;
  std::function<void(int, int)> dfs = [&graph, n, &subtree, &res, &dfs](int par, int ver) {
    bool is_centroid = true;
    for (const Edge<CostType> &e : graph[ver]) {
      if (e.dst != par) {
        dfs(ver, e.dst);
        subtree[ver] += subtree[e.dst];
        is_centroid &= subtree[e.dst] <= n / 2;
      }
    }
    if (is_centroid && (n - subtree[ver]) <= n / 2) res.emplace_back(ver);
  };
  dfs(-1, 0);
  std::sort(res.begin(), res.end());
  return res;
}

void solve() {
  int n; cin >> n;
  vector<vector<Edge<int>>> graph(n);
  REP(_, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(x, y);
    graph[y].emplace_back(y, x);
  }
  vector<int> cen = centroid(graph);
  if (cen.size() == 1) {
    cout << 1 << ' ' << graph[0][0].dst + 1 << '\n' << 1 << ' ' << graph[0][0].dst + 1 << '\n';
  } else {
    vector visited(n, false);
    function<void(int, int)> dfs = [&](int par, int ver) {
      for (const Edge<int> &e : graph[ver]) {
        if (e.dst != par) {
          visited[e.dst] = true;
          dfs(ver, e.dst);
        }
      }
    };
    dfs(cen[0], cen[1]);
    REP(i, n) {
      if (visited[i] && graph[i].size() == 1) {
        cout << i + 1 << ' ' << graph[i][0].dst + 1 << '\n' << i + 1 << ' ' << cen[0] + 1 << '\n';
        return;
      }
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}