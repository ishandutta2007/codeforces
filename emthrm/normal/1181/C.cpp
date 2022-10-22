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
#define int long long

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int h, w; cin >> h >> w;
  vector<vector<char> > moufu(h, vector<char>(w)); REP(i, h) REP(j, w) cin >> moufu[i][j];
  vector<vector<int> > yoko(h, vector<int>(w)), tate(h, vector<int>(w));
  REP(i, h) {
    for (int j = 0; j < w;) {
      char now = moufu[i][j];
      int idx = j + 1;
      while (idx < w && moufu[i][idx] == now) ++idx;
      FOR(k, j, idx) yoko[i][k] = idx;
      j = idx;
    }
  }
  REP(j, w) {
    for (int i = 0; i < h;) {
      char now = moufu[i][j];
      int idx = i + 1;
      while (idx < h && moufu[idx][j] == now) ++idx;
      FOR(k, i, idx) tate[k][j] = idx;
      i = idx;
    }
  }
  vector<long long> dp(w + 1, 0);
  FOR(i, 1, w + 1) dp[i] = dp[i - 1] + i;
  long long ans = 0;
  FOR(i, 1, h) REP(j, w) if (moufu[i - 1][j] != moufu[i][j]) {
    int len = tate[i][j] - i;
    if (i - len < 0 || tate[i - len][j] != i) continue;
    if (i + len >= h || tate[i + len][j] < i + 2 * len) continue;
    int width = INF;
    FOR(k, i - len, i + 2 * len) width = min(width, yoko[k][j] - j);
    ans += width;
  }
  cout << ans << '\n';
  return 0;
}