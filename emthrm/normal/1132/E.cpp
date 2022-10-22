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

  int n = 8;
  long long l = 840;
  long long w; cin >> w;
  vector<long long> cnt(n); REP(i, n) cin >> cnt[i];
  vector<vector<long long> > dp(n + 1, vector<long long>(l * n + 1, -1));
  dp[0][0] = 0;
  REP(i, n) REP(j, l * n + 1) if (dp[i][j] != -1) {
    int now = i + 1, mx = min(cnt[i], l / now);
    REP(k, mx + 1) dp[i + 1][j + k * now] = max(dp[i + 1][j + k * now], dp[i][j] + (cnt[i] - k) / (l / now));
  }
  long long ans = 0;
  REP(j, l * n + 1) if (dp[n][j] != -1) {
    if (w >= j) ans = max(ans, l * min(dp[n][j], (w - j) / l) + j);
  }
  cout << ans << '\n';
  return 0;
}