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
  vector<vector<int>> a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  vector<int> r(n), c(m, 0);
  REP(i, n) r[i] = *max_element(ALL(a[i]));
  sort(ALL(r), greater<int>());
  REP(j, m) REP(i, n) chmax(c[j], a[i][j]);
  sort(ALL(c), greater<int>());
  vector ans(n, vector(m, -1));
  queue<pair<int, int>> que;
  int y = -1, x = -1, i = 0, j = 0;
  for (int t = n * m; t >= 1; --t) {
    // cout << t << ' ' << i << ' ' << j << ' ' << y << ' ' << x << endl;
    int flag = 0;
    if (i < n && r[i] == t) {
      ++i;
      ++y;
      flag |= 1;
    }
    if (j < m && c[j] == t) {
      ++j;
      ++x;
      flag |= 2;
    }
    if (flag == 0) {
      assert(!que.empty());
      auto [yi, xj] = que.front(); que.pop();
      ans[yi][xj] = t;
    } else if (flag == 1) {
      ans[y][x] = t;
      for (int k = x - 1; k >= 0; --k) que.emplace(y, k);
    } else if (flag == 2) {
      ans[y][x] = t;
      for (int k = y - 1; k >= 0; --k) que.emplace(k, x);
    } else if (flag == 3) {
      ans[y][x] = t;
      for (int k = x - 1; k >= 0; --k) que.emplace(y, k);
      for (int k = y - 1; k >= 0; --k) que.emplace(k, x);
    }
  }
  REP(ii, n) REP(jj, m) cout << ans[ii][jj] << " \n"[jj + 1 == m];
  return 0;
}