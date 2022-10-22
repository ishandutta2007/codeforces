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
  int n, m; cin >> n >> m;
  vector<long long> dp(n + 1);
  dp[1] = 2;
  if (2 < n + 1) dp[2] = 4;
  FOR(i, 3, n + 1) dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
  if (m > 1) {
    vector<long long> dp2(m - 1);
    dp2[0] = 2;
    if (1 < m - 1) dp2[1] = 2;
    FOR(j, 2, m - 1) dp2[j] = (dp2[j - 1] + dp2[j - 2]) % MOD;
    REP(j, m - 1) (dp[n] += dp2[j]) %= MOD;
  }
  cout << dp[n] << '\n';
  return 0;

  // FOR(i, 1, 4) FOR(j, 1, 7) {
  //   int N = i * j, ans = 0;
  //   REP(bit, 1 << N) {
  //     vector<vector<int> > board(i, vector<int>(j));
  //     REP(y, i) REP(x, j) {
  //       board[y][x] = (bit >> (y * j + x) & 1);
  //     }
  //     bool ok = true;
  //     REP(y, i) REP(x, j) {
  //       int cnt = 0;
  //       REP(k, 4) {
  //         int nx_y = y + dy[k], nx_x = x + dx[k];
  //         if (0 <= nx_y && nx_y < i && 0 <= nx_x && nx_x < j) {
  //           if (board[y][x] == board[nx_y][nx_x]) ++cnt;
  //         }
  //       }
  //       if (cnt >= 2) {
  //         ok = false;
  //         break;
  //       }
  //     }
  //     if (ok) ++ans;
  //   }
  //   cout << ans << (j + 1 == 7 ? '\n' : ' ');
  // }
}