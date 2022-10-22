#include <algorithm>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  string s; cin >> s;
  vector<vector<long long> > dp(n, vector<long long>(n, LINF));
  REP(i, n) dp[i][i] = 1;
  FOR(width, 1, n) {
    for (int i = 0; i + width < n; ++i) {
      int j = i + width;
      dp[i][j] = dp[i + 1][j] + 1;
      FOR(k, i + 1, j + 1) if (s[i] == s[k]) {
        dp[i][j] = min(dp[i][j], (i + 1 > k - 1 ? 0 : dp[i + 1][k - 1]) + dp[k][j]);
      }
    }
  }
  cout << dp[0][n - 1] << '\n';
  return 0;
}