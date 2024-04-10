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

  string s; cin >> s;
  int n = s.length();
  vector<vector<long long> > dp(n, vector<long long>(2)); // true -> tight
  dp[0][true] = s[0] - '0';
  dp[0][false] = max((s[0] - '0') - 1, 1);
  FOR(i, 1, n) {
    dp[i][true] = dp[i - 1][true] * (s[i] - '0');
    dp[i][false] = dp[i - 1][false] * 9;
    if (s[i] != '0') dp[i][false] = max(dp[i][false], dp[i - 1][true] * ((s[i] - '0') - 1));
  }
  cout << max(dp[n - 1][true], dp[n - 1][false]) << '\n';
  return 0;
}