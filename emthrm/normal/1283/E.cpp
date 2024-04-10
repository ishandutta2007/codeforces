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
  vector<int> x(n); REP(i, n) cin >> x[i];
  sort(ALL(x));
  vector<bool> occ(n + 2, false);
  REP(i, n) {
    if (!occ[x[i] - 1]) {
      occ[x[i] - 1] = true;
    } else if (!occ[x[i]]) {
      occ[x[i]] = true;
    } else if (!occ[x[i] + 1]) {
      occ[x[i] + 1] = true;
    }
  }
  int ans = 0;
  REP(i, n + 2) ans += occ[i];
  x.erase(unique(ALL(x)), x.end());
  n = x.size();
  vector<int> dp(n + 1, INF);
  dp[0] = 0;
  REP(i, n) {
    dp[i + 1] = min(dp[i + 1], dp[i] + 1);
    if (i + 1 < n && x[i + 1] - x[i] <= 2) dp[i + 2] = min(dp[i + 2], dp[i] + 1);
    if (i + 2 < n && x[i + 2] - x[i] == 2) dp[i + 3] = min(dp[i + 3], dp[i] + 1);
  }
  cout << dp[n] << ' ' << ans << '\n';
  return 0;
}