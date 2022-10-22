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

struct UnionFind {
  UnionFind(int n) : data(n, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  bool unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return false;
    if (data[u] > data[v]) std::swap(u, v);
    data[u] += data[v];
    data[v] = u;
    return true;
  }

  bool same(int u, int v) { return root(u) == root(v); }

  int size(int ver) { return -data[root(ver)]; }

private:
  std::vector<int> data;
};

int main() {
  int n, m1, m2; cin >> n >> m1 >> m2;
  UnionFind mocha(n), diana(n);
  while (m1--) {
    int u, v; cin >> u >> v; --u; --v;
    mocha.unite(u, v);
  }
  while (m2--) {
    int u, v; cin >> u >> v; --u; --v;
    diana.unite(u, v);
  }
  vector<int> u, v;
  REP(i, n) FOR(j, i + 1, n) {
    if (!mocha.same(i, j) && !diana.same(i, j)) {
      u.emplace_back(i);
      v.emplace_back(j);
      mocha.unite(i, j);
      diana.unite(i, j);
    }
  }
  const int h = u.size();
  cout << h << '\n';
  REP(i, h) cout << u[i] + 1 << ' ' << v[i] + 1 << '\n';
  return 0;
}