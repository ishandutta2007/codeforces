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

// https://yukicoder.me/problems/no/1268/editorial
int main() {
  int n; cin >> n;
  vector<int> f{1, 1};
  while (f.back() < n) {
    int m = f.size();
    f.emplace_back(f[m - 2] + f[m - 1]);
  }
  if (f.back() != n) {
    cout << "NO\n";
    return 0;
  }
  vector<unordered_set<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace(v);
    graph[v].emplace(u);
  }
  auto g = [&](auto &&g, int root, int size) -> bool {
    if (f[size] <= 3) return true;
    unordered_map<int, int> child;
    auto h = [&](auto &&h, int par, int ver) -> int {
      child[ver] = 1;
      int u = -1, v = -1;
      for (int e : graph[ver]) {
        if (e != par) {
          int dfs = h(h, ver, e);
          if (dfs != -1) return dfs == 1;
          if (child[e] == f[size - 1]) {
            graph[ver].erase(e);
            graph[e].erase(ver);
            return g(g, ver, size - 2) && g(g, e, size - 1) ? 1 : 0;
          } else if (child[e] == f[size - 2]) {
            graph[ver].erase(e);
            graph[e].erase(ver);
            return g(g, ver, size - 1) && g(g, e, size - 2) ? 1 : 0;
          }
          child[ver] += child[e];
        }
      }
      return -1;
    };
    return h(h, -1, root) == 1;
  };
  cout << (g(g, 0, f.size() - 1) ? "YES\n" : "NO\n");
  return 0;
}