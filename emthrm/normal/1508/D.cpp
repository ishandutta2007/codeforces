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
  int n; cin >> n;
  vector<int> x(n), y(n), a(n); REP(i, n) cin >> x[i] >> y[i] >> a[i], --a[i];
  vector<int> ord;
  REP(i, n) {
    if (a[i] != i) ord.emplace_back(i);
  }
  if (ord.empty()) {
    cout << 0 << '\n';
    return 0;
  }
  sort(ALL(ord), [&](int l, int r) -> bool {
    return x[l] < x[r] || (x[l] == x[r] && y[l] < y[r]);
  });
  int root = ord.front();
  sort(ord.begin() + 1, ord.end(), [&](int l, int r) -> bool {
    int lx = x[l] - x[root], ly = y[l] - y[root];
    int rx = x[r] - x[root], ry = y[r] - y[root];
    return atan2(ly, lx) < atan2(ry, rx);
  });
  vector<pair<int, int>> ans;
  auto swp = [&](int i, int j) -> void {
    swap(a[i], a[j]);
    ans.emplace_back(i, j);
  };
  UnionFind uf(n);
  for (int i : ord) uf.unite(i, a[i]);
  FOR(i, 2, ord.size()) {
    if (uf.unite(ord[i - 1], ord[i])) swp(ord[i - 1], ord[i]);
  }
  FOR(i, 1, ord.size()) swp(root, a[root]);
  assert(is_sorted(ALL(a)));
  cout << ans.size() << '\n';
  for (auto [i, j] : ans) cout << i + 1 << ' ' << j + 1 << '\n';
  return 0;
}