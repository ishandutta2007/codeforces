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
#include <queue>
#include <random>
#include <set>
#include <sstream>
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
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, x; cin >> n >> x;
  vector<long long> a(n); REP(i, n) cin >> a[i];
  vector<vector<vector<long long> > > dp(n + 1, vector<vector<long long> >(2, vector<long long>(2, -INF)));
  dp[0][false][false] = 0;
  long long ans = 0;
  REP(i, n) {
    dp[i + 1][true][true] = max(dp[i][true][true], dp[i][false][false]) + a[i] * x;
    dp[i + 1][false][true] = max(max(dp[i][true][true], dp[i][false][true]) + a[i], 0LL);
    dp[i + 1][false][false] = max(dp[i][false][false] + a[i], 0LL);
    ans = max({ans, dp[i + 1][true][true], dp[i + 1][false][true], dp[i + 1][false][false]});
  }
  cout << ans << '\n';
  return 0;
}