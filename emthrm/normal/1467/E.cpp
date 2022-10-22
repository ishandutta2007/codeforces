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
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<int> v;
  {
    vector<int> b = a;
    sort(ALL(b));
    b.erase(unique(ALL(b)), b.end());
    REP(i, n) a[i] = lower_bound(ALL(b), a[i]) - b.begin();
    v.assign(b.size(), 0);
  }
  REP(i, n) ++v[a[i]];
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<map<int, int>> mp(n);
  auto merge = [&](int i, int j) {
    if (mp[i].size() < mp[j].size()) swap(mp[i], mp[j]);
    for (auto [key, val] : mp[j]) mp[i][key] += val;
    mp[j].clear();
  };
  set<pair<int, int>> dir;
  auto f = [&](auto &&f, int par, int ver) -> void {
    for (int e : graph[ver]) {
      if (e != par) {
        f(f, ver, e);
        if (mp[e].count(a[ver]) == 1) dir.emplace(ver, e);
        merge(ver, e);
      }
    }
    ++mp[ver][a[ver]];
    if (par != -1 && mp[ver][a[ver]] < v[a[ver]]) dir.emplace(ver, par);
  };
  f(f, -1, 0);
  vector<int> child(n, 0);
  auto g = [&](auto &&g, int par, int ver) -> void {
    for (int e : graph[ver]) {
      if (e != par) {
        g(g, ver, e);
        child[ver] += child[e] + dir.count({e, ver});
      }
    }
  };
  g(g, -1, 0);
  int ans = 0;
  auto h = [&](auto &&h, int par, int ver, int par_c) -> void {
    child[ver] += par_c;
    ans += child[ver] == dir.size();
    for (int e : graph[ver]) {
      if (e != par) h(h, ver, e, child[ver] - child[e] - dir.count({e, ver}) + dir.count({ver, e}));
    }
  };
  h(h, -1, 0, 0);
  cout << ans << '\n';
  return 0;
}