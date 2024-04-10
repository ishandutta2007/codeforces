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
  int n, m; string a, b; cin >> n >> m >> a >> b;
  vector<int> to(m, -1);
  REP(i, m) {
    string s = (i + 1 == m ? b : b.substr(0, i + 1) + (b[i + 1] == '0' ? '1' : '0'));
    s.erase(s.begin());
    to[i] = (i + 1 == m ? m - 2 : i);
    for (; to[i] >= 0; --to[i]) {
      if (s == b.substr(0, to[i] + 1)) break;
      s.erase(s.begin());
    }
  }
  replace_if(ALL(to), [](int x) -> bool { return x == -1; }, m - 1);
  const int oc = n - m + 1;
  vector dp(oc + 1, vector(m, INF));
  dp[0][m - 1] = 0;
  for (char c : a) {
    vector nx(oc + 1, vector(m, INF));
    REP(i, oc + 1) {
      REP(j, m - 1) {
        if (dp[i][j] == INF) continue;
        REP(k, 2) {
          if (k == b[j + 1] - '0') {
            if (j + 1 == m - 1) {
              chmin(nx[i + 1][to[m - 1]], dp[i][j] + (c - '0' != k));
            } else {
              chmin(nx[i][j + 1], dp[i][j] + (c - '0' != k));
            }
          } else {
            chmin(nx[i][to[j]], dp[i][j] + (c - '0' != k));
          }
        }
      }
      if (dp[i][m - 1] != INF) {
        REP(k, 2) {
          if (k == b.front() - '0') {
            if (m == 1) {
              chmin(nx[i + 1][0], dp[i][0] + (c - '0' != k));
            } else {
              chmin(nx[i][0], dp[i][m - 1] + (c - '0' != k));
            }
          } else {
            chmin(nx[i][m - 1], dp[i][m - 1] + (c - '0' != k));
          }
        }
      }
    }
    dp.swap(nx);
  }
  REP(i, oc + 1) {
    int ans = *min_element(ALL(dp[i]));
    cout << (ans == INF ? -1 : ans) << " \n"[i == oc];
  }
  return 0;
}