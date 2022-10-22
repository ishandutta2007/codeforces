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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int main() {
  int n, m; cin >> n >> m;
  vector<long long> x(n), s(n); REP(i, n) cin >> x[i] >> s[i];
  vector<vector<long long> > dp(m + 1, vector<long long>(n, LINF));
  REP(j, n) dp[0][j] = max(x[j] - s[j], 0LL);
  vector<long long> mn(m + 1, LINF);
  mn[0] = 0;
  FOR(i, 1, m + 1) REP(j, n) {
    if (x[j] - s[j] <= i && i <= x[j] + s[j]) {
      dp[i][j] = mn[i - 1];
    } else if (i < x[j] - s[j]) {
      dp[i][j] = min(dp[i - 1][j], mn[i - 1] + x[j] - s[j] - i);
    } else if (x[j] - (i - x[j]) >= 0) {
      dp[i][j] = dp[x[j] - (i - x[j])][j];
    } else {
      dp[i][j] = i - (x[j] + s[j]);
    }
    mn[i] = min(mn[i], dp[i][j]);
  }
  // REP(i, m + 1) {
  //   cout << i << ':';
  //   REP(j, n) cout << dp[i][j] << ' ';
  //   cout << '\n';
  // }
  cout << mn[m] << '\n';
  return 0;
}