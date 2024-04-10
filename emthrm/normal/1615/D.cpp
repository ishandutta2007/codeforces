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

void solve() {
  int n, m; cin >> n >> m;
  vector<Edge<int>> edge;
  UnionFind uf(n * 2);
  REP(_, n - 1) {
    int x, y, v; cin >> x >> y >> v; --x; --y;
    edge.emplace_back(x, y, v);
    if (v != -1) {
      if (__builtin_popcount(v) & 1) {
        uf.unite(x, y + n);
        uf.unite(y, x + n);
      } else {
        uf.unite(x, y);
        uf.unite(x + n, y + n);
      }
    }
  }
  while (m--) {
    int a, b, p; cin >> a >> b >> p; --a; --b;
    if (p == 0) {
      uf.unite(a, b);
      uf.unite(a + n, b + n);
    } else {
      uf.unite(a, b + n);
      uf.unite(b, a + n);
    }
  }
  REP(i, n) {
    if (uf.is_same(i, i + n)) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
  REP(i, n - 1) {
    const auto [x, y, v] = edge[i];
    cout << x + 1 << ' ' << y + 1 << ' ';
    if (v == -1) {
      if (!uf.is_same(x, y) && !uf.is_same(x, y + n)) {
        uf.unite(x, y);
        uf.unite(x + n, y + n);
      }
      cout << uf.is_same(x, y + n) << '\n';
    } else {
      cout << v << '\n';
    }
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}