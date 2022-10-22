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

  int n; cin >> n;
  vector<int> h1(n), h2(n);
  REP(i, n) cin >> h1[i];
  REP(i, n) cin >> h2[i];
  vector<vector<long long> > dp(n + 1, vector<long long>(3, 0));
  REP(i, n) {
    dp[i + 1][0] = max(dp[i][1], dp[i][2]) + h1[i];
    dp[i + 1][1] = max(dp[i][0], dp[i][2]) + h2[i];
    dp[i + 1][2] = max(dp[i][0], dp[i][1]);
  }
  cout << max({dp[n][0], dp[n][1], dp[n][2]}) << '\n';
  return 0;
}