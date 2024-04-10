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

int main() {
  int n; cin >> n;
  vector<int> h(n); REP(i, n) cin >> h[i];
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  ll ans = 0;
  const auto f = [&](auto&& f, int par, int ver) -> int {
    int tower = 0;
    for (int e : graph[ver]) {
      if (e != par) chmax(tower, f(f, ver, e));
    }
    if (tower < h[ver]) {
      ans += h[ver] - tower;
      tower = h[ver];
    }
    return tower;
  };
  const int root = max_element(ALL(h)) - h.begin();
  vector<int> children;
  for (int e : graph[root]) children.emplace_back(f(f, root, e));
  sort(ALL(children), greater<int>());
  if (children.size() == 1) children.emplace_back(0);
  REP(i, 2) ans += max(h[root] - children[i], 0);
  cout << ans << '\n';
  return 0;
}