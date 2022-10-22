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

bool solve() {
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
  REP(j, m) {
    int x = 0;
    for (int i = 0; i < n && j - i >= 0; ++i) x ^= a[i][j - i];
    if (x > 0) return true;
  }
  FOR(i, 1, n) {
    int x = 0;
    for (int j = 0; i + j < n && m - 1 - j >= 0; ++j) x ^= a[i + j][m - 1 - j];
    if (x > 0) return true;
  }
  return false;
}

int main() {
  int t; cin >> t;
  while (t--) cout << (solve() ? "Ashish\n" : "Jeel\n");
  return 0;
}