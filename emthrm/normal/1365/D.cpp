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
  int n, m; cin >> n >> m;
  vector<string> maze(n); REP(i, n) cin >> maze[i];
  REP(i, n) REP(j, m) {
    if (maze[i][j] == 'B') {
      REP(k, 4) {
        int y = i + dy[k], x = j + dx[k];
        if (0 <= y && y < n && 0 <= x && x < m && maze[y][x] != 'B') {
          if (maze[y][x] == 'G') {
            cout << "No\n";
            return;
          }
          maze[y][x] = '#';
        }
      }
    }
  }
  int good = 0;
  REP(i, n) good += count(ALL(maze[i]), 'G');
  queue<pair<int, int>> que;
  if (maze[n - 1][m - 1] != '#') {
    que.emplace(n - 1, m - 1);
    good -= maze[n - 1][m - 1] == 'G';
    maze[n - 1][m - 1] = '#';
  }
  while (!que.empty()) {
    auto [i, j] = que.front(); que.pop();
    REP(k, 4) {
      int y = i + dy[k], x = j + dx[k];
      if (0 <= y && y < n && 0 <= x && x < m && maze[y][x] != '#') {
        good -= maze[y][x] == 'G';
        maze[y][x] = '#';
        que.emplace(y, x);
      }
    }
  }
  cout << (good == 0 ? "Yes\n" : "No\n");
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}