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

void solve() {
  int n, m; cin >> n >> m;
  vector<string> s(n); REP(i, n) cin >> s[i];
  REP(i, n) FOR(j, 2, m) {
    if (s[i].substr(j - 2, 3) == "***") {
      cout << "NO\n";
      return;
    }
  }
  REP(j, m) FOR(i, 2, n) {
    if (s[i - 2][j] == '*' && s[i - 1][j] == '*' && s[i][j] == '*') {
      cout << "NO\n";
      return;
    }
  }
  UnionFind union_find(n * m);
  REP(i, n) REP(j, m) {
    if (s[i][j] == '.') continue;
    REP(k, 8) {
      const int y = i + DY8[k], x = j + DX8[k];
      if (0 <= y && y < n && 0 <= x && x < m && s[y][x] == '*') {
        union_find.unite(i * m + j, y * m + x);
      }
    }
  }
  REP(i, n) REP(j, m) {
    if (s[i][j] == '*' && union_find.size(i * m + j) != 3) {
      cout << "NO\n";
      return;
    }
  }
  UnionFind union_find2(n * m);
  REP(i, n) REP(j, m) {
    if (s[i][j] == '.') continue;
    REP(k, 4) {
      const int y = i + DY4[k], x = j + DX4[k];
      if (0 <= y && y < n && 0 <= x && x < m && s[y][x] == '*') {
        union_find2.unite(i * m + j, y * m + x);
      }
    }
  }
  REP(i, n) REP(j, m) {
    if (s[i][j] == '*' && union_find2.size(i * m + j) != 3) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}