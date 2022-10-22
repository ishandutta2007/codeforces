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
  vector<string> s(n); REP(i, n) cin >> s[i];
  bool row = false, col = false;
  REP(i, n) {
    int cnt = count(ALL(s[i]), '#');
    row |= cnt == 0;
    if (cnt > 0) {
      int mn = m, mx = 0;
      REP(j, m) {
        if (s[i][j] == '#') {
          chmin(mn, j);
          chmax(mx, j);
        }
      }
      if (mx - mn + 1 > cnt) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  REP(j, m) {
    int cnt = 0;
    REP(i, n) cnt += s[i][j] == '#';
    col |= cnt == 0;
    if (cnt > 0) {
      int mn = n, mx = 0;
      REP(i, n) {
        if (s[i][j] == '#') {
          chmin(mn, i);
          chmax(mx, i);
        }
      }
      if (mx - mn + 1 > cnt) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  if ((row && !col) || (!row && col)) {
    cout << "-1\n";
    return 0;
  }
  int ans = 0;
  vector visited(n, vector(m, false));
  REP(i, n) REP(j, m) {
    if (visited[i][j]) continue;
    visited[i][j] = true;
    if (s[i][j] == '.') continue;
    ++ans;
    queue<pair<int, int>> que;
    que.emplace(i, j);
    while (!que.empty()) {
      auto [i, j] = que.front(); que.pop();
      REP(k, 4) {
        int y = i + dy[k], x = j + dx[k];
        if (0 <= y && y < n && 0 <= x && x < m && s[y][x] == '#' && !visited[y][x]) {
          visited[y][x] = true;
          que.emplace(y, x);
        }
      }
    }
  }
  cout << ans << '\n';
  return 0;
}