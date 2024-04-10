#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
template <typename T> using posteriority_queue = priority_queue<T, vector<T>, greater<T> >;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
template <typename T> void unique(vector<T> &a) { a.erase(unique(ALL(a)), a.end()); }
struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n; cin >> n;
  vector<vector<int> > graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<vector<int> > par(n, vector<int>(n, -1)), sub(n, vector<int>(n, 1));
  REP(i, n) {
    function<void(int)> dfs = [&](int ver) {
      for (int e : graph[ver]) {
        if (e == par[i][ver]) continue;
        par[i][e] = ver;
        dfs(e);
        sub[i][ver] += sub[i][e];
      }
    };
    dfs(i);
  }
  vector<vector<ll> > dp(n, vector<ll>(n, -LINF));
  function<ll(int, int)> rec = [&](int l, int r) {
    ll &d = dp[l][r];
    if (d != -LINF) return d;
    if (l == r) return d = 0;
    return d = max(rec(par[r][l], r), rec(l, par[l][r])) + 1LL * sub[r][l] * sub[l][r];
  };
  ll ans = 0;
  REP(i, n) FOR(j, i + 1, n) chmax(ans, rec(i, j));
  cout << ans << '\n';
  return 0;
}