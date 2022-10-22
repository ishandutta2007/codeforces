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

int main() {
  int n; cin >> n;
  vector<int> l(n); REP(i, n) cin >> l[i];
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(b);
    graph[b].emplace_back(a);
  }
  vector ans(n, 0LL), light(n, 0LL);
  function<void(int, int)> dfs1 = [&](int par, int ver) {
    light[ver] = l[ver];
    for (int e : graph[ver]) {
      if (e == par) continue;
      dfs1(ver, e);
      ans[ver] += ans[e] + light[e];
      light[ver] += light[e];
    }
  };
  dfs1(-1, 0);
  function<void(int, int, ll, ll)> dfs2 = [&](int par, int ver, ll par_dp, ll par_light) {
    ans[ver] += par_dp + par_light;
    light[ver] += par_light;
    for (int e : graph[ver]) {
      if (e != par) dfs2(ver, e, ans[ver] - ans[e] - light[e], light[ver] - light[e]);
    }
  };
  dfs2(-1, 0, 0, 0);
  cout << *max_element(ALL(ans)) << '\n';
  return 0;
}