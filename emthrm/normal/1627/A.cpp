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
constexpr int DY[]{1, 0, -1, 0}, DX[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1}, DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U> inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U> inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

int solve() {
  int n, m, r, c; cin >> n >> m >> r >> c; --r; --c;
  vector<string> s(n); REP(i, n) cin >> s[i];
  if (s[r][c] == 'B') return 0;
  REP(i, n) {
    if (s[i][c] == 'B') return 1;
  }
  REP(j, m) {
    if (s[r][j] == 'B') return 1;
  }
  REP(i, n) REP(j, m) {
    if (s[i][j] == 'B') return 2;
  }
  return -1;
}

int main() {
  int t; cin >> t;
  while (t--) cout << solve() << '\n';
  return 0;
}