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

int main() {
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i], --a[i];
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  int cur_p = 0, cur_a = 1;
  vector<int> par(n, -1), post(n, -1), ans(n, 0), height(n, 0);
  auto f = [&](auto &&f, int ver) -> void {
    auto it = find(ALL(graph[ver]), par[ver]);
    if (it != graph[ver].end()) graph[ver].erase(it);
    sort(ALL(graph[ver]), [&](int l, int r) -> bool { return a[l] < a[r]; });
    for (int e : graph[ver]) {
      par[e] = ver;
      ans[e] = cur_a++;
      height[e] = height[ver] + 1;
      f(f, e);
    }
    post[ver] = cur_p++;
  };
  f(f, 0);
  ll day = 0;
  if (a[0] > 0) {
    bool is_valid = false;
    int ver = find(ALL(post), a[0] - 1) - post.begin();
    while (ver != -1) {
      is_valid |= a[ver] == a[0] - 1;
      ver = par[ver];
    }
    if (!is_valid) {
      cout << "NO\n";
      return 0;
    }
    ver = find(ALL(a), a[0] - 1) - a.begin();
    while (ver != 0) {
      ++day;
      swap(a[ver], a[par[ver]]);
      ver = par[ver];
    }
  }
  REP(i, n) {
    if (post[i] < a[0]) {
      if (a[i] != post[i]) {
        cout << "NO\n";
        return 0;
      }
      day += height[i];
    }
  }
  int cur = a[0];
  auto g = [&](auto &&g, int ver) -> void {
    for (int e : graph[ver]) {
      if (a[e] > a[0]) {
        if (a[e] != ++cur) {
          cout << "NO\n";
          exit(0);
        }
        g(g, e);
      }
    }
  };
  g(g, 0);
  cout << "YES\n" << day << '\n';
  REP(i, n) cout << ans[i] + 1 << " \n"[i + 1 == n];
  return 0;
}