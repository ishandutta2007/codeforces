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

template <typename T>
vector<vector<T>> rot(const vector<vector<T>> &grid, int angle, T basis = ' ') {
  int h = grid.size(), w = grid.front().size();
  vector<vector<T>> rotated_grid;
  if (angle == 45) {
    rotated_grid.assign(h + w - 1, vector<T>(h + w - 1, basis));
    REP(i, h) REP(j, w) rotated_grid[i + j][i - j + w - 1] = grid[i][j];
  } else if (angle == 90) {
    rotated_grid.assign(w, vector<T>(h));
    REP(i, h) REP(j, w) rotated_grid[w - 1 - j][i] = grid[i][j];
  } else {
    assert(false);
  }
  return rotated_grid;
}

int main() {
  int n, m; cin >> n >> m;
  if (n >= 4 && m >= 4) {
    cout << "-1\n";
    return 0;
  }
  if (min(n, m) == 1) {
    cout << 0 << '\n';
    return 0;
  }
  vector<vector<char>> a(n, vector<char>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  if (n < m) {
    swap(n, m);
    a = rot(a, 90);
  }
  vector dp(n, vector(1 << m, INF));
  {
    vector<int> b(m);
    REP(j, m) b[j] = a[0][j] - '0';
    REP(j, 1 << m) {
      dp[0][j] = 0;
      REP(i, m) dp[0][j] += b[i] != (j >> i & 1);
    }
  }
  const vector<vector<vector<int>>> pre{
    {
      {1, 2},
      {0, 3},
      {0, 3},
      {1, 2}
    },
    {
      {2, 5},
      {3, 4},
      {0, 7},
      {1, 6},
      {1, 6},
      {0, 7},
      {3, 4},
      {2, 5}
    }
  };
  FOR(i, 1, n) REP(j, 1 << m) {
    int diff = 0;
    REP(x, m) diff += (j >> x & 1) != a[i][x] - '0';
    for (int e : pre[m - 2][j]) chmin(dp[i][j], dp[i - 1][e] + diff);
  }
  cout << *min_element(ALL(dp[n - 1])) << '\n';
  return 0;
}