#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
using ll = long long;
constexpr int INF = 0x3f3f3f3f;
constexpr long long LINF = 0x3f3f3f3f3f3f3f3fLL;
constexpr double EPS = 1e-8;
constexpr int MOD = 1000000007;
// constexpr int MOD = 998244353;
constexpr int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
constexpr int dy8[] = {1, 1, 0, -1, -1, -1, 0, 1}, dx8[] = {0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T &a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T &a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int main() {
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m)), b(n, vector<int>(m));
  REP(i, n) REP(j, m) cin >> a[i][j];
  REP(i, n) REP(j, m) cin >> b[i][j];
  vector<int> inv(m, 0);
  REP(j, m) REP(i, n - 1) inv[j] += b[i][j] > b[i + 1][j];
  queue<int> que;
  REP(j, m) {
    if (inv[j] == 0) que.emplace(j);
  }
  vector<bool> sepa(n - 1, false);
  vector<int> ans;
  while (!que.empty()) {
    int col = que.front(); que.pop();
    ans.emplace_back(col);
    REP(i, n - 1) {
      if (!sepa[i] && b[i][col] < b[i + 1][col]) {
        sepa[i] = true;
        REP(j, m) {
          if (b[i][j] > b[i + 1][j]) {
            --inv[j];
            if (inv[j] == 0) que.emplace(j);
          }
        }
      }
    }
  }
  reverse(ALL(ans));
  vector<int> row(n);
  iota(ALL(row), 0);
  for (int col : ans) {
    stable_sort(ALL(row), [&](int l, int r) -> bool { return a[l][col] < a[r][col]; });
  }
  // REP(i, n) cout << row[i] << " \n"[i + 1 == n];
  REP(i, n) REP(j, m) {
    if (a[row[i]][j] != b[i][j]) {
      cout << "-1\n";
      return 0;
    }
  }
  int k = ans.size();
  cout << k << '\n';
  REP(i, k) cout << ans[i] + 1 << " \n"[i + 1 == k];
  return 0;
}