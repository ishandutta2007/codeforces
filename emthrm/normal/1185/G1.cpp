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

  int n, T; cin >> n >> T;
  vector<int> t(n), g(n); REP(i, n) cin >> t[i] >> g[i];
  vector<vector<long long> > dp(1 << n, vector<long long>(4, 0));
  dp[0][0] = 1;
  REP(i, (1 << n) - 1) REP(j, 4) {
    if (i > 0 && j == 0) continue;
    REP(k, n) if (!(i >> k & 1)) {
      if (j != g[k]) (dp[i | (1 << k)][g[k]] += dp[i][j]) %= MOD;
    }
  }
  long long ans = 0;
  REP(i, 1 << n) REP(j, 4) {
    if (i > 0 && j == 0) continue;
    int tm = 0;
    REP(k, n) if (i >> k & 1) tm += t[k];
    if (tm == T) (ans += dp[i][j]) %= MOD;
  }
  cout << ans << '\n';
  return 0;
}