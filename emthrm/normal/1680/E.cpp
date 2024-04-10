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
constexpr int DY4[]{1, 0, -1, 0}, DX4[]{0, -1, 0, 1};
constexpr int DY8[]{1, 1, 0, -1, -1, -1, 0, 1};
constexpr int DX8[]{0, -1, -1, -1, 0, 1, 1, 1};
template <typename T, typename U>
inline bool chmax(T& a, U b) { return a < b ? (a = b, true) : false; }
template <typename T, typename U>
inline bool chmin(T& a, U b) { return a > b ? (a = b, true) : false; }
struct IOSetup {
  IOSetup() {
    std::cin.tie(nullptr);
    std::ios_base::sync_with_stdio(false);
    std::cout << fixed << setprecision(20);
  }
} iosetup;

void solve() {
  int n; cin >> n;
  string s[2]; REP(i, 2) cin >> s[i];
  REP(_, 2) {
    while (s[0].back() == '.' && s[1].back() == '.') {
      s[0].pop_back();
      s[1].pop_back();
    }
    REP(i, 2) reverse(ALL(s[i]));
  }
  n = s[0].length();
  // 0: connected  1: ox  2: xo  3: oo
  int dp[4]{1, INF, INF, INF};
  if (s[0].front() == '*' && s[1].front() == '.') {
    dp[1] = 0;
  } else if (s[0].front() == '.' && s[1].front() == '*') {
    dp[2] = 0;
  } else {
    dp[3] = 0;
  }
  FOR(i, 1, n) {
    int nxt[4];
    fill(nxt, nxt + 4, INF);
    REP(j, 4) REP(x, 2) {
      if (!x && (j == 1 || j == 3)) continue;
      REP(y, 2) {
        if ((!x && !y) || (!y && (j == 2 || j == 3))) continue;
        if (j == 0) {
          if (x && y) {
            chmin(nxt[0], dp[j] + x + y);
          } else {
            chmin(nxt[x | (y << 1)], dp[j] + x + y);
          }
        } else {
          chmin(nxt[j], dp[j] + x + y);
        }
      }
    }
    swap(dp, nxt);
    if (s[0][i] == '*') {
      chmin(dp[3], dp[2]);
      dp[2] = INF;
    }
    if (s[1][i] == '*') {
      chmin(dp[3], dp[1]);
      dp[1] = INF;
    }
    chmin(dp[0], min({dp[1], dp[2], dp[3]}) + 1);
  }
  cout << min({dp[0], dp[1], dp[2]}) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}