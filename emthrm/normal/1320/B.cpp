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
  int n, m; cin >> n >> m;
  vector<vector<int> > graph(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[v].emplace_back(u);
  }
  int k; cin >> k;
  vector<int> p(k); REP(i, k) cin >> p[i], --p[i];
  vector<int> dist(n, INF);
  dist[p[k - 1]] = 0;
  vector<set<int> > st(n);
  queue<int> que;
  que.emplace(p[k - 1]);
  while (!que.empty()) {
    int ver = que.front(); que.pop();
    for (int e : graph[ver]) {
      if (dist[e] > dist[ver] + 1) {
        dist[e] = dist[ver] + 1;
        st[e].clear();
        st[e].emplace(ver);
        que.emplace(e);
      } else if (dist[e] == dist[ver] + 1) {
        st[e].emplace(ver);
      }
    }
  }
  // REP(i, n) cout << dist[i] << " \n"[i + 1 == n];
  int ans_mn = 0, ans_mx = 0;
  REP(i, k - 1) {
    if (st[p[i]].count(p[i + 1]) == 0) ++ans_mn;
    if (st[p[i]].count(p[i + 1]) == 0 || st[p[i]].size() >= 2) ++ans_mx;
  }
  cout << ans_mn << ' ' << ans_mx << '\n';
  return 0;
}