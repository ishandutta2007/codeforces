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

void solve() {
  int n; cin >> n;
  vector<string> s(n); REP(i, n) cin >> s[i];
  vector<int> x(3, 0), o(3, 0);
  REP(i, n) REP(j, n) {
    if (s[i][j] == 'X') ++x[(i + j) % 3];
    if (s[i][j] == 'O') ++o[(i + j) % 3];
  }
  int k = accumulate(ALL(x), 0) + accumulate(ALL(o), 0);
  REP(change_x, 3) REP(change_o, 3) {
    if (change_x == change_o || x[change_x] + o[change_o] > k / 3) continue;
    REP(i, n) REP(j, n) {
      if (s[i][j] == 'X' && (i + j) % 3 == change_x) {
        s[i][j] = 'O';
      } else if (s[i][j] == 'O' && (i + j) % 3 == change_o) {
        s[i][j] = 'X';
      }
    }
    REP(i, n) cout << s[i] << '\n';
    return;
  }
  assert(false);
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}