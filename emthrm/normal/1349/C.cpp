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
  int n, m, t; cin >> n >> m >> t;
  vector<string> ini(n); REP(i, n) cin >> ini[i];
  vector dist(n, vector(m, INF));
  vector<pair<int, int>> que;
  REP(i, n) REP(j, m) {
    bool exist = false;
    REP(k, 4) {
      int y = i + dy[k], x = j + dx[k];
      exist |= 0 <= y && y < n && 0 <= x && x < m && ini[i][j] == ini[y][x];
    }
    if (exist) {
      dist[i][j] = 0;
      que.emplace_back(i, j);
    }
  }
  if (que.empty()) {
    while (t--) {
      int i, j; ll p; cin >> i >> j >> p; --i; --j;
      cout << ini[i][j] << '\n';
    }
    return 0;
  }
  while (!que.empty()) {
    vector<pair<int, int>> nx;
    for (auto [i, j] : que) {
      REP(k, 4) {
        int y = i + dy[k], x = j + dx[k];
        if (0 <= y && y < n && 0 <= x && x < m && dist[y][x] == INF) {
          dist[y][x] = dist[i][j] + 1;
          nx.emplace_back(y, x);
        }
      }
    }
    nx.swap(que);
  }
  while (t--) {
    int i, j; ll p; cin >> i >> j >> p; --i; --j;
    if (dist[i][j] > p) {
      cout << ini[i][j] << '\n';
    } else {
      p -= dist[i][j];
      if (p & 1) {
        cout << (ini[i][j] == '0' ? "1\n" : "0\n");
      } else {
        cout << (ini[i][j] == '0' ? "0\n" : "1\n");
      }
    }
  }
  return 0;

  // REP(_, 5) {
  //   vector<string> nx(n);
  //   REP(i, n) REP(j, m) {
  //     bool exist = false;
  //     REP(k, 4) {
  //       int y = i + dy[k], x = j + dx[k];
  //       exist |= 0 <= y && y < n && 0 <= x && x < m && ini[i][j] == ini[y][x];
  //     }
  //     if (exist) {
  //       nx[i] += ini[i][j] == '0' ? '1' : '0';
  //     } else {
  //       nx[i] += ini[i][j] == '0' ? '0' : '1';
  //     }
  //   }
  //   ini.swap(nx);
  //   REP(i, n) {
  //     REP(j, m) cout << ini[i][j];
  //     cout << '\n';
  //   }
  //   cout << '\n';
  // }
}