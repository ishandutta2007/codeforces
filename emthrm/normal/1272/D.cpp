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
#include <iomanip>
#include <iostream>
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
  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<vector<int> > dp(n, vector<int>(2, 0));
  dp[0][false] = 1;
  FOR(i, 1, n) {
    dp[i][false] = 1;
    if (a[i - 1] < a[i]) {
      dp[i][true] = dp[i - 1][true] + 1;
      dp[i][false] = max(dp[i][false], dp[i - 1][false] + 1);
    }
    if (i - 2 >= 0 && a[i - 2] < a[i]) {
      dp[i][true] = max(dp[i][true], dp[i - 2][false] + 1);
    }
  }
  int ans = 1;
  REP(i, n) REP(j, 2) ans = max(ans, dp[i][j]);
  cout << ans << '\n';
  return 0;
}