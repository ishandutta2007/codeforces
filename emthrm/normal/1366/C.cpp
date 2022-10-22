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
  vector<vector<int>> a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  vector<pair<int, int>> fro{{0, 0}}, bac{{n - 1, m - 1}};
  vector visited(n, vector(m, false));
  visited[0][0] = visited[n - 1][m - 1]= true;
  int ans = 0;
  REP(_, (n + m - 1) / 2) {
    vector cnt(2, 0);
    for (auto [y, x] : fro) ++cnt[a[y][x]];
    for (auto [y, x] : bac) ++cnt[a[y][x]];
    ans += *min_element(ALL(cnt));
    vector<pair<int, int>> nx_fro, nx_bac;
    for (auto [i, j] : fro) {
      REP(k, 4) {
        int y = i + dy[k], x = j + dx[k];
        if (0 <= y && y < n && 0 <= x && x < m && !visited[y][x]) {
          visited[y][x] = true;
          nx_fro.emplace_back(y, x);
        }
      }
    }
    for (auto [i, j] : bac) {
      REP(k, 4) {
        int y = i + dy[k], x = j + dx[k];
        if (0 <= y && y < n && 0 <= x && x < m && !visited[y][x]) {
          visited[y][x] = true;
          nx_bac.emplace_back(y, x);
        }
      }
    }
    fro.swap(nx_fro);
    bac.swap(nx_bac);
  }
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}