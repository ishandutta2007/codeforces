#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
void solve() {
  int l, r; cin >> l >> r;
  long long dp[31][2][2][2][2] = {};
  dp[30][0][0][0][0] = 1;
  for (int i = 30; i > 0; --i) {
    int L = l >> (i - 1) & 1, R = r >> (i - 1) & 1;
    REP(j, 2) REP(k, 2) REP(m, 2) REP(x, 2) {
      // 0 1
      bool ok = true;
      int nx_j = j;
      if (j == 0 && L) ok = false;
      int nx_k = k;
      if (k == 0 && R) nx_k = 1;
      int nx_m = m;
      if (m == 0 && !L) nx_m = 1;
      int nx_x = x;
      if (x == 0 && !R) ok = false;
      if (ok) dp[i - 1][nx_j][nx_k][nx_m][nx_x] += dp[i][j][k][m][x];
      // 1 0
      ok = true;
      nx_j = j;
      if (j == 0 && !L) nx_j = 1;
      nx_k = k;
      if (k == 0 && !R) ok = false;
      nx_m = m;
      if (m == 0 && L) ok = false;
      nx_x = x;
      if (x == 0 && R) nx_x = 1;
      if (ok) dp[i - 1][nx_j][nx_k][nx_m][nx_x] += dp[i][j][k][m][x];
      // 0 0
      ok = true;
      nx_j = j;
      if (j == 0 && L) ok = false;
      nx_k = k;
      if (k == 0 && R) nx_k = 1;
      nx_m = m;
      if (m == 0 && L) ok = false;
      nx_x = x;
      if (x == 0 && R) nx_x = 1;
      if (ok) dp[i - 1][nx_j][nx_k][nx_m][nx_x] += dp[i][j][k][m][x];
    }
  }
  long long ans = 0;
  REP(j, 2) REP(k, 2) REP(m, 2) REP(x, 2) ans += dp[0][j][k][m][x];
  cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}