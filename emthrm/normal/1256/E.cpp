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
  vector<pair<int, int> > a(n);
  REP(i, n) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(ALL(a));
  vector<long long> dp(n + 1, LINF);
  vector<int> prev(n + 1, 0);
  dp[0] = 0;
  REP(i, n) {
    if (i + 3 <= n) {
      if (dp[i] + a[i + 2].first - a[i].first < dp[i + 3]) {
        prev[i + 3] = i;
        dp[i + 3] = dp[i] + a[i + 2].first - a[i].first;
      }
    }
    if (i + 4 <= n) {
      if (dp[i] + a[i + 3].first - a[i].first < dp[i + 4]) {
        prev[i + 4] = i;
        dp[i + 4] = dp[i] + a[i + 3].first - a[i].first;
      }
    }
    if (i + 5 <= n) {
      if (dp[i] + a[i + 4].first - a[i].first < dp[i + 5]) {
        prev[i + 5] = i;
        dp[i + 5] = dp[i] + a[i + 4].first - a[i].first;
      }
    }
  }
  int now = 1, pos = n;
  vector<int> ans(n, -1);
  while (pos > 0) {
    FOR(k, prev[pos], pos) ans[a[k].second] = now;
    ++now;
    pos = prev[pos];
  }
  cout << dp[n] << ' ' << now - 1 << '\n';
  REP(i, n) cout << ans[i] << (i + 1 == n ? '\n' : ' ');
  return 0;
}