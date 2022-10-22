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
  map<char, int> mp;
  mp['D'] = 0; mp['L'] = 1; mp['U'] = 2; mp['R'] = 3;
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<string> c(n), s(n);
    REP(i, n) cin >> c[i];
    REP(i, n) cin >> s[i];
    vector deg(n, vector(m, 0));
    vector<vector<vector<pair<int, int>>>> rev(n, vector<vector<pair<int, int>>>(m));
    REP(i, n) REP(j, m) {
      int y = i + dy[mp[s[i][j]]], x = j + dx[mp[s[i][j]]];
      ++deg[y][x];
      rev[y][x].emplace_back(i, j);
    }
    int max_robot = 0, max_black = 0;
    vector dist(n, vector(m, -1));
    REP(sy, n) REP(sx, m) {
      if (dist[sy][sx] != -1 || deg[sy][sx] > 0) continue;
      dist[sy][sx] = 0;
      vector<pair<int, int>> route{{sy, sx}};
      int loop;
      while (true) {
        auto [i, j] = route.back();
        int y = i + dy[mp[s[i][j]]], x = j + dx[mp[s[i][j]]];
        if (dist[y][x] == -1) {
          route.emplace_back(y, x);
          dist[y][x] = dist[i][j] + 1;
        } else {
          loop = dist[i][j] - dist[y][x] + 1;
          break;
        }
      }
      max_robot += loop;
      reverse(ALL(route));
      for (auto [i, j] : route) dist[i][j] = -1;
      dist[route[loop - 1].first][route[loop - 1].second] = loop - 1;
      vector<bool> exist(loop, false);
      exist[loop - 1] = c[route[loop - 1].first][route[loop - 1].second] == '0';
      int now = loop - 1;
      vector<pair<int, int>> que;
      que.emplace_back(route[loop - 1]);
      while (!que.empty()) {
        vector<pair<int, int>> nx;
        (now += loop - 1) %= loop;
        for (auto [i, j] : que) {
          for (auto [y, x] : rev[i][j]) {
            if (dist[y][x] != -1) continue;
            dist[y][x] = now;
            if (c[y][x] == '0') exist[now] = true;
            nx.emplace_back(y, x);
          }
        }
        que.swap(nx);
      }
      REP(i, loop) max_black += exist[i];
    }
    // REP(i, n) REP(j, m) cout << dist[i][j] << " \n"[j + 1 == m];
    // cout << max_robot << ' ' << max_black << '\n';
    REP(i, n) REP(j, m) {
      if (dist[i][j] == -1) {
        ++max_robot;
        max_black += c[i][j] == '0';
      }
    }
    cout << max_robot << ' ' << max_black << '\n';
  }
  return 0;
}