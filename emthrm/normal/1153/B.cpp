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

  int n, m, h; cin >> n >> m >> h;
  vector<int> a(m); REP(i, m) cin >> a[i];
  vector<int> b(n); REP(i, n) cin >> b[i];
  vector<vector<int> > height(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> height[i][j];
  vector<vector<int> > ans(n, vector<int>(m, 0));
  REP(i, n) REP(j, m) if (height[i][j] == 1) {
    ans[i][j] = min(a[j], b[i]);
  }
  REP(i, n) {
    REP(j, m) cout << ans[i][j] << (j == m - 1 ? '\n' : ' ');
  }
  return 0;
}