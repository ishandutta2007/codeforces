#include <algorithm>
#include <bitset>
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
/*-------------------------------------------------*/
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<string> pipe(2); REP(i, 2) cin >> pipe[i];
    REP(i, 2) REP(j, n) {
      pipe[i][j] = ('1' <= pipe[i][j] && pipe[i][j] <= '2' ? '0' : '1');
    }
    vector<vector<bool> > dp(n + 1, vector<bool>(2, false));
    dp[0][0] = true;
    REP(i, n) {
      if (pipe[0][i] == '0' || pipe[1][i] == '0') {
        if (pipe[0][i] == '0') dp[i + 1][0] = dp[i][0];
        if (pipe[1][i] == '0') dp[i + 1][1] = dp[i][1];
      } else {
        dp[i + 1][0] = dp[i][1];
        dp[i + 1][1] = dp[i][0];
      }
    }
    cout << (dp[n][1] ? "YES\n" : "NO\n");
  }
  return 0;
}