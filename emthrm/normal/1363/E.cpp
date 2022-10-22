#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
const int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
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
  vector<int> a(n), b(n), c(n); REP(i, n) cin >> a[i] >> b[i] >> c[i];
  // REP(i, n) cout << a[i] << ' ' << b[i] << ' ' << c[i] << '\n';
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  function<void(int, int, int)> pre = [&](int par, int ver, int mn) {
    chmin(mn, a[ver]);
    a[ver] = mn;
    for (int e : graph[ver]) {
      if (e != par) pre(ver, e, mn);
    }
  };
  pre(-1, 0, INF);
  ll ans = 0;
  function<pair<int, int>(int, int)> dfs = [&](int par, int ver) {
    int zero = 0, one = 0;
    if (b[ver] != c[ver]) (b[ver] == 0 ? zero : one) += 1;
    // cout << ver << " [" << zero << ',' << one << "]\n";
    for (int e : graph[ver]) {
      if (e == par) continue;
      auto [z, o] = dfs(ver, e);
      zero += z;
      one += o;
    }
    int tmp = min(zero, one);
    ans += 1LL * a[ver] * tmp * 2;
    zero -= tmp;
    one -= tmp;
    return make_pair(zero, one);
  };
  auto [zero, one] = dfs(-1, 0);
  cout << (zero == 0 && one == 0 ? ans : -1) << '\n';
  return 0;
}