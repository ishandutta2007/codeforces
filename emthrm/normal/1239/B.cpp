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
  int n; cin >> n;
  string s; cin >> s;
  if (count(ALL(s), '(') != count(ALL(s), ')')) {
    cout << "0\n1 1\n";
    return 0;
  }
  vector<int> cum(n);
  cum[0] = (s[0] == '(' ? 1 : -1);
  FOR(i, 1, n) cum[i] = cum[i - 1] + (s[i] == '(' ? 1 : -1);
  int small = *min_element(ALL(cum));
  int beauty = count(ALL(cum), small), l = 1, r = 1;
  for (int mn : {small - 2, small - 1, small, small + 1, small + 2}) {
    // ( ) -> ) (
    vector<vector<long long> > dp(n + 1, vector<long long>(3, -INF));
    vector<vector<int> > prev(n + 1, vector<int>(3, -1));
    dp[0][0] = 0;
    REP(i, n) {
      dp[i + 1][0] = dp[i][0] + (cum[i] == mn ? 1 : cum[i] < mn ? -INF : 0);
      dp[i + 1][1] = dp[i][1];
      if (dp[i][0] > dp[i + 1][1]) {
        prev[i + 1][1] = 0;
        dp[i + 1][1] = dp[i][0];
      }
      dp[i + 1][1] += (cum[i] - 2 == mn ? 1 : cum[i] - 2 < mn ? -INF : 0);
      dp[i + 1][2] = dp[i][2];
      if (dp[i][1] > dp[i + 1][2]) {
        prev[i + 1][2] = 1;
        dp[i + 1][2] = dp[i][1];
      }
      dp[i + 1][2] += (cum[i] == mn ? 1 : cum[i] < mn ? -INF : 0);
    }
    // REP(j, 3) {
    //   REP(i, n + 1) cout << dp[i][j] << ' ';
    //   cout << '\n';
    // }
    if (dp[n][2] > beauty) {
      beauty = dp[n][2];
      int state = 2;
      for (int i = n; i >= 1; --i) {
        if (prev[i][state] == state - 1) {
          if (state == 1) {
            l = i;
            break;
          } else if (state == 2) {
            r = i;
            --state;
          }
        }
      }
    }
    // ) ( -> ( )
    dp.assign(n + 1, vector<long long>(3, -INF));
    prev.assign(n + 1, vector<int>(3, -1));
    dp[0][0] = 0;
    REP(i, n) {
      dp[i + 1][0] = dp[i][0] + (cum[i] == mn ? 1 : cum[i] < mn ? -INF : 0);
      dp[i + 1][1] = dp[i][1];
      if (dp[i][0] > dp[i + 1][1]) {
        prev[i + 1][1] = 0;
        dp[i + 1][1] = dp[i][0];
      }
      dp[i + 1][1] += (cum[i] + 2 == mn ? 1 : cum[i] + 2 < mn ? -INF : 0);
      dp[i + 1][2] = dp[i][2];
      if (dp[i][1] > dp[i + 1][2]) {
        prev[i + 1][2] = 1;
        dp[i + 1][2] = dp[i][1];
      }
      dp[i + 1][2] += (cum[i] == mn ? 1 : cum[i] < mn ? -INF : 0);
    }
    if (dp[n][2] > beauty) {
      beauty = dp[n][2];
      int state = 2;
      for (int i = n; i >= 1; --i) {
        if (prev[i][state] == state - 1) {
          if (state == 1) {
            l = i;
            break;
          } else if (state == 2) {
            r = i;
            --state;
          }
        }
      }
    }
  }
  cout << beauty << '\n' << l << ' ' << r << '\n';
  return 0;
}