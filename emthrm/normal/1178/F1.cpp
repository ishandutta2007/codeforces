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
const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
long long dp[500][500];
int c[500];
long long rec(int l, int r) {
  if (dp[l][r] != -1) return dp[l][r];
  if (r < l) return dp[l][r] = 0;
  if (l == r) return dp[l][r] = 1;
  int idx, mn = INF;
  FOR(i, l, r + 1) {
    if (c[i] < mn) {
      mn = c[i];
      idx = i;
    }
  }
  dp[l][r] = 0;
  long long left = 0;
  FOR(i, l, idx + 1) {
    long long tmp = (l < i ? rec(l, i - 1) : 1);
    (tmp *= (i < idx ? rec(i, idx - 1) : 1)) %= MOD;
    (left += tmp) %= MOD;
  }
  long long right = 0;
  FOR(j, idx, r + 1) {
    long long tmp = (idx < j ? rec(idx + 1, j) : 1);
    (tmp *= (j < r ? rec(j + 1, r) : 1)) %= MOD;
    (right += tmp) %= MOD;
  }
  return dp[l][r] = left * right % MOD;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  REP(i, 500) REP(j, 500) dp[i][j] = -1;
  int n; cin >> n >> n;
  REP(i, n) cin >> c[i];
  cout << rec(0, n - 1) << '\n';
  // REP(i, n) {
  //   REP(j, n) cout << dp[i][j] << ' ';
  //   cout << '\n';
  // }
  return 0;
}