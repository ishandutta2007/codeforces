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
  vector<int> t(n), h(n);
  REP(i, n) cin >> t[i];
  REP(i, n) cin >> h[i];
  vector in(n, 0), out(n, 0);
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    if (h[u] == h[v]) {
      graph[u].emplace_back(v);
      graph[v].emplace_back(u);
    } else if (h[u] < h[v]) {
      ++out[u];
      ++in[v];
    } else {
      ++out[v];
      ++in[u];
    }
  }
  ll ans = 0;
  vector visited(n, false);
  function<pair<ll, ll>(int, int)> dfs = [&](int par, int ver) -> pair<ll, ll> {
    visited[ver] = true;
    ll cost = 0;
    vector<ll> diff;
    for (int e : graph[ver]) {
      if (e == par) continue;
      auto [f, g] = dfs(ver, e);
      cost += f;
      diff.emplace_back(g - f);
    }
    int c = diff.size();
    sort(ALL(diff));
    function<ll(int, int)> calc = [&](int x, int y) {
      return 1LL * t[ver] * max(in[ver] + x, out[ver] + y);
    };
    ll f = cost + calc(par != -1, c), g = cost + calc(0, c + (par != -1));
    REP(i, c) {
      cost += diff[i];
      chmin(f, cost + calc((par != -1) + i + 1, c - (i + 1)));
      chmin(g, cost + calc(i + 1, c - (i + 1) + (par != -1)));
    }
    return {f, g};
  };
  REP(i, n) {
    if (visited[i]) continue;
    auto [f, g] = dfs(-1, i);
    ans += min(f, g);
  }
  cout << ans << '\n';
  return 0;
}