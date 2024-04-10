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

  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  vector<int> nx(n);
  REP(i, n) nx[i] = upper_bound(ALL(a), a[i] + 5) - a.begin();
  vector<vector<int> > dp(n + 1, vector<int>(k + 1, 0));
  REP(i, n) REP(j, k) {
    dp[nx[i]][j + 1] = max(dp[nx[i]][j + 1], dp[i][j] + nx[i] - i);
    dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
  }
  int ans = 0;
  REP(i, n + 1) ans = max(ans, dp[i][k]);
  cout << ans << '\n';
  return 0;
}