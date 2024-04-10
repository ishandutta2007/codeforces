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

struct UnionFind {
  explicit UnionFind(const int n) : data(n, -1) {}

  int root(const int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool is_same(const int u, const int v) { return root(u) == root(v); }

  int size(const int ver) { return -data[root(ver)]; }

 private:
  std::vector<int> data;
};

int main() {
  constexpr int B = 30;
  int n, m; cin >> n >> m;
  vector<int> a(m), b(m), w(m); REP(i, m) cin >> a[i] >> b[i] >> w[i], --a[i], --b[i];
  vector union_find(B, UnionFind(n)), uf(B, UnionFind(n));
  REP(i, m) {
    REP(bit, B) {
      if (w[i] >> bit & 1) union_find[bit].unite(a[i], b[i]);
    }
    if (w[i] & 1) {
      FOR(bit, 1, B) {
        if (w[i] >> bit & 1) uf[bit].unite(a[i], b[i]);
      }
    }
  }
  set<int> mex_is_1[B]{};
  REP(i, m) {
    if (!(w[i] & 1)) {
      FOR(bit, 1, B) {
        mex_is_1[bit].emplace(uf[bit].root(a[i]));
        mex_is_1[bit].emplace(uf[bit].root(b[i]));
      }
    }
  }
  const auto f = [&](const int u, const int v) -> int {
    REP(bit, B) {
      if (union_find[bit].is_same(u, v)) return 0;
    }
    FOR(bit, 1, B) {
      if (mex_is_1[bit].count(uf[bit].root(u))) return 1;
    }
    return 2;
  };
  int q; cin >> q;
  while (q--) {
    int u, v; cin >> u >> v; --u; --v;
    cout << f(u, v) << '\n';
  }
  return 0;
}