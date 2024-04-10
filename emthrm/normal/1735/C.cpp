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

constexpr int C = 26;

void solve() {
  int n; string t; cin >> n >> t;
  char from[C]{};
  fill(from, from + C, '$');
  set<int> fr;
  REP(c, C) fr.emplace(c);
  UnionFind union_find(C);
  string ans = "";
  for (const char c : t) {
    const int c_int = c - 'a';
    if (from[c_int] == '$') {
      for (auto it = fr.begin(); it != fr.end(); it = next(it)) {
        if (union_find.is_same(c_int, *it)) {
          if (union_find.size(c_int) == C) {
            from[c_int] = 'a' + *it;
            fr.erase(it);
            break;
          }
        } else {
          union_find.unite(c_int, *it);
          from[c_int] = 'a' + *it;
          fr.erase(it);
          break;
        }
      }
    }
    ans += from[c_int];
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}