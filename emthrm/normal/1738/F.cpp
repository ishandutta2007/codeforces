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
constexpr int MOD = 998244353;
// constexpr int MOD = 1000000007;
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

int query(const int u) {
  cout << "? " << u + 1 << endl;
  int e; cin >> e;
  assert(e != -1);
  return e - 1;
}

void solve() {
  int n; cin >> n;
  vector<int> d(n); REP(i, n) cin >> d[i];
  vector<int> ord(n);
  iota(ALL(ord), 0);
  sort(ALL(ord), [&](const int a, const int b) -> bool { return d[a] > d[b]; });
  UnionFind union_find(n);
  vector<int> ans(n, -1);
  for (const int i : ord) {
    if (union_find.size(i) > 1) continue;
    while (d[i]--) {
      const int e = query(i);
      const bool is_isolating = union_find.size(e) == 1;
      union_find.unite(i, e);
      if (!is_isolating) break;
    }
  }
  cout << "!";
  REP(i, n) cout << ' ' << union_find.root(i) + 1;
  cout << endl;
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}