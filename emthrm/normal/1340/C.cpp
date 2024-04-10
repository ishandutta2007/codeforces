#pragma GCC optimize("Ofast", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper")
#pragma GCC target("avx2")

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
  vector<int> d(m); REP(i, m) cin >> d[i];
  sort(ALL(d));
  int g, r; cin >> g >> r;
  vector dist(m, vector(g, INF));
  dist[0][0] = 0;
  deque<pair<int, int>> que;
  que.emplace_back(0, 0);
  while (!que.empty()) {
    auto [i, j] = que.front(); que.pop_front();
    // REP(i, m) REP(j, g) cout << (dist[i][j] == INF ? -1 : dist[i][j]) << " \n"[j + 1 == g];
    // cout << '\n';
    if (i > 0) {
      if (j + d[i] - d[i - 1] < g) {
        if (dist[i - 1][j + d[i] - d[i - 1]] == INF) {
          dist[i - 1][j + d[i] - d[i - 1]] = dist[i][j];
          que.emplace_front(i - 1, j + d[i] - d[i - 1]);
        }
      } else if (j + d[i] - d[i - 1] == g) {
        if (dist[i - 1][0] == INF) {
          dist[i - 1][0] = dist[i][j] + 1;
          que.emplace_back(i - 1, 0);
        }
      }
    }
    if (i + 1 < m) {
      if (j + d[i + 1] - d[i] < g) {
        if (dist[i + 1][j + d[i + 1] - d[i]] == INF) {
          dist[i + 1][j + d[i + 1] - d[i]] = dist[i][j];
          que.emplace_front(i + 1, j + d[i + 1] - d[i]);
        }
      } else if (j + d[i + 1] - d[i] == g) {
        if (dist[i + 1][0] == INF) {
          dist[i + 1][0] = dist[i][j] + 1;
          que.emplace_back(i + 1, 0);
        }
      }
    }
  }
  // REP(j, g) cout << dist[m - 1][j] << " \n"[j + 1 == g];
  int ans = dist[m - 1][0] == INF ? INF : (dist[m - 1][0] - 1) * (g + r) + g;
  FOR(j, 1, g) {
    if (dist[m - 1][j] != INF) chmin(ans, dist[m - 1][j] * (g + r) + j);
  }
  cout << (ans == INF ? -1 : ans) << '\n';
  return 0;
}