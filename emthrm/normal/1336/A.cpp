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
  int n, k; cin >> n >> k;
  vector<vector<int>> graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<int> dist(n, -1);
  dist[0] = 0;
  queue<int> que;
  que.emplace(0);
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (int e : graph[ver]) {
      if (dist[e] == -1) {
        dist[e] = dist[ver] + 1;
        que.emplace(e);
      }
    }
  }
  vector<pair<int, int>> sub(n);
  function<void(int, int)> dfs = [&](int par, int ver) {
    sub[ver] = {1, ver};
    for (int e : graph[ver]) {
      if (e != par) {
        dfs(ver, e);
        sub[ver].first += sub[e].first;
      }
    }
  };
  dfs(-1, 0);
  REP(i, n) sub[i].first = dist[i] - sub[i].first + 1;
  sort(ALL(sub), greater<pair<int, int>>());
  ll ans = 0;
  REP(i, k) ans += sub[i].first;
  cout << ans << '\n';
  return 0;
}