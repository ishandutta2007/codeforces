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

struct UnionFind {
  UnionFind(const int n) : data(n, -1) {}

  int root(const int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) {
      std::swap(u, v);
    }
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) {
    return root(u) == root(v);
  }

  int size(const int ver) {
    return -data[root(ver)];
  }

private:
  std::vector<int> data;
};

int main() {
  int n, m; cin >> n >> m;
  vector<Edge<int>> edges;
  edges.reserve(m);
  REP(i, m) {
    int v, u, w; cin >> v >> u >> w; --v; --u;
    edges.emplace_back(v, u, w);
  }
  vector<int> xs(m);
  REP(i, m) xs[i] = edges[i].cost;
  sort(ALL(xs));
  xs.erase(unique(ALL(xs)), xs.end());
  int s = xs.size();
  REP(i, s) FOR(j, i + 1, s) {
    const int l = xs[i], r = xs[j];
    xs.emplace_back((l + r) / 2);
    xs.emplace_back((l + r + 1) / 2);
  }
  xs.emplace_back(0);
  xs.emplace_back(100000000);
  sort(ALL(xs));
  xs.erase(unique(ALL(xs)), xs.end());
  s = xs.size();
  vector<ll> costs(s, 0);
  REP(i, s) {
    vector<Edge<int>> tmp = edges;
    REP(j, m) tmp[j].cost = abs(tmp[j].cost - xs[i]);
    sort(ALL(tmp));
    UnionFind union_find(n);
    for (const auto [v, u, w] : tmp) {
      if (union_find.unite(v, u)) costs[i] += w;
    }
  }
  int p, k, a, b, c; cin >> p >> k >> a >> b >> c;
  int q = 0;
  ll ans = 0;
  REP(i, k) {
    if (i < p) {
      cin >> q;
    } else {
      q = (1LL * q * a + b) % c;
    }
    int idx = upper_bound(ALL(xs), q) - xs.begin();
    if (idx > 0) --idx;
    ans ^= costs[idx] + (costs[idx + 1] - costs[idx]) / (xs[idx + 1] - xs[idx]) * (q - xs[idx]);
  }
  cout << ans << '\n';
  return 0;
}