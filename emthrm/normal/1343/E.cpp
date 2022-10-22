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

void solve() {
  int n, m, a, b, c; cin >> n >> m >> a >> b >> c; --a; --b; --c;
  vector<ll> p(m + 1);
  FOR(i, 1, m + 1) cin >> p[i];
  sort(ALL(p));
  FOR(i, 1, m + 1) p[i] += p[i - 1];
  vector<vector<int>> graph(n);
  REP(_, m) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector dist(n, vector(3, INF));
  vector s{a, b, c};
  REP(j, 3) {
    dist[s[j]][j] = 0;
    queue<int> que;
    que.emplace(s[j]);
    while (!que.empty()) {
      int ver = que.front(); que.pop();
      for (int e : graph[ver]) {
        if (dist[e][j] == INF) {
          dist[e][j] = dist[ver][j] + 1;
          que.emplace(e);
        }
      }
    }
  }
  ll ans = LINF;
  REP(i, n) {
    int two = dist[i][1], one = dist[i][0] + dist[i][2];
    if (one + two <= m) chmin(ans, p[two] * 2 + (p[one + two] - p[two]));
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}