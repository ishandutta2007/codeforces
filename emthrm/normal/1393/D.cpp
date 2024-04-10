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
  vector<tuple<int, int, char>> que;
  REP(i, n) REP(j, m) que.emplace_back(i, j, s[i][j]);
  vector level(n, vector(m, INF));
  for (int d = 1; !que.empty(); ++d) {
    vector<tuple<int, int, char>> nx;
    for (auto [i, j, c] : que) {
      REP(k, 4) {
        int y = i + dy[k], x = j + dx[k];
        if (0 <= y && y < n && 0 <= x && x < m && s[y][x] != c && level[y][x] > d) {
          level[y][x] = d;
          nx.emplace_back(y, x, c);
        }
      }
    }
    que.swap(nx);
    // REP(i, n) REP(j, m) cout << (level[i][j] == INF ? -1 : level[i][j]) << " \n"[j + 1 == m];
    // cout << '\n';
  }
  ll ans = 0;
  REP(i, n) REP(j, m) ans += min({level[i][j], i + 1, j + 1, n - i, m - j});
  cout << ans << '\n';
  return 0;
}