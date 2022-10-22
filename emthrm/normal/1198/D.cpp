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
int n, dp[51][51][51][51];
string grid[50];
int rec(int r1, int c1, int r2, int c2) {
  if (dp[r1][c1][r2][c2] != INF) return dp[r1][c1][r2][c2];
  // cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << '\n';
  if (r1 == r2 || c1 == c2) return dp[r1][c1][r2][c2] = 0;
  if (r1 + 1 == r2 && c1 + 1 == c2) return dp[r1][c1][r2][c2] = (grid[r1][c1] == '#' ? 1 : 0);
  FOR(r, r1 + 1, r2) dp[r1][c1][r2][c2] = min(dp[r1][c1][r2][c2], rec(r1, c1, r, c2) + rec(r, c1, r2, c2));
  FOR(c, c1 + 1, c2) dp[r1][c1][r2][c2] = min(dp[r1][c1][r2][c2], rec(r1, c1, r2, c) + rec(r1, c, r2, c2));
  dp[r1][c1][r2][c2] = min(dp[r1][c1][r2][c2], max(r2 - r1, c2 - c1));
  return dp[r1][c1][r2][c2];
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  REP(i, 51) REP(j, 51) REP(k, 51) REP(l, 51) dp[i][j][k][l] = INF;
  cin >> n;
  REP(i, n) cin >> grid[i];
  cout << rec(0, 0, n, n) << '\n';
}