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
  int m, n; cin >> m >> n;
  vector<int> a(m), b(n);
  REP(i, m) cin >> a[i];
  REP(i, n) cin >> b[i];
  vector<vector<int>> A(m);
  REP(i, m) {
    int s; cin >> s;
    A[i].resize(s);
    REP(j, s) cin >> A[i][j], --A[i][j];
  }
  vector<pair<int, int>> idx;
  REP(i, m) REP(j, A[i].size()) idx.emplace_back(i, j);
  sort(ALL(idx), [&](pair<int, int> p, pair<int, int> q) {
    auto [p1, p2] = p;
    auto [q1, q2] = q;
    return a[p1] + b[A[p1][p2]] > a[q1] + b[A[q1][q2]];
  });
  UnionFind uf(m);
  vector<int> last(n, -1);
  ll ans = 0;
  for (auto [i, j] : idx) {
    if (last[A[i][j]] == -1) {
      last[A[i][j]] = i;
      continue;
    }
    if (uf.same(last[A[i][j]], i)) {
      ans += a[i] + b[A[i][j]];
    } else {
      uf.unite(last[A[i][j]], i);
      last[A[i][j]] = i;
    }
  }
  cout << ans << '\n';
  return 0;
}