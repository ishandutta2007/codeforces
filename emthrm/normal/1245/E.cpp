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
int main() {
  vector<vector<int> > mp(10, vector<int>(10));
  int idx = 0;
  REP(i, 10) {
    if (i % 2 == 0) {
      REP(j, 10) mp[i][j] = idx++;
    } else {
      for (int j = 9; j >= 0; --j) mp[i][j] = idx++;
    }
  }
  vector<vector<int> > ghostory(10, vector<int>(10));
  REP(i, 10) REP(j, 10) cin >> ghostory[i][j];
  REP(i, 5) swap(ghostory[i], ghostory[9 - i]);
  vector<vector<double> > dp(100, vector<double>(2, INF));
  dp[99][0] = 0;
  // FOR(j, 1, 6) {
  //   double tmp = 0;
  //   REP(k, j) tmp += dp[9][k];
  //   tmp /= 6;
  //   tmp += 1;
  //   tmp *= 6;
  //   tmp /= j;
  //   dp[9][j] = tmp;
  // }
  FOR(i, 1, 6) dp[99 - i][0] = 6;
  for (int i = 93; i >= 0; --i) {
    int y = i / 10, x = i % 10;
    if (y & 1) x = 9 - x;
    dp[i][0] = 0;
    FOR(j, 1, 7) dp[i][0] += min(dp[i + j][0], dp[i + j][1]);
    dp[i][0] /= 6;
    dp[i][0] += 1;
    // cout << y << ' ' << x << "->";
    y += ghostory[y][x];
    // cout << y << ' ' << x << '\n';
    dp[i][1] = dp[mp[y][x]][0];
  }
  cout << min(dp[0][0], dp[0][1]) << '\n';
  return 0;
}