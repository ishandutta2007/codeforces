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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
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

void solve() {
  int n; cin >> n;
  vector<vector<Edge<int>>> graph(n);
  REP(i, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(u, v, i);
    graph[v].emplace_back(v, u, i);
  }
  REP(i, n) {
    if (graph[i].size() >= 3) {
      cout << "-1\n";
      return;
    }
  }
  REP(i, n) {
    if (graph[i].size() == 1) {
      int par = -1, ver = i;
      vector<int> ids;
      REP(_, n - 1) {
        for (const auto [_, dst, id] : graph[ver]) {
          if (dst != par) {
            par = ver;
            ver = dst;
            ids.emplace_back(id);
            break;
          }
        }
      }
      vector<int> a(n - 1);
      REP(i, n - 1) a[ids[i]] = (i & 1 ? 2 : 3);
      REP(i, n - 1) cout << a[i] << " \n"[i + 1 == n - 1];
      return;
    }
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}