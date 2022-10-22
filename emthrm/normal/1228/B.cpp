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
#include <numeric>
#include <queue>
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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int h, w; cin >> h >> w;
  vector<vector<int> > cell(h, vector<int>(w, -1));
  REP(i, h) {
    int r; cin >> r;
    REP(j, r) cell[i][j] = 1;
    if (r < w) cell[i][r] = 0;
  }
  // REP(i, h) {
  //   REP(j, w) cout << cell[i][j] << ' ';
  //   cout << '\n';
  // }
  REP(j, w) {
    int c; cin >> c;
    REP(i, c) {
      if (cell[i][j] == 0) {
        // cout << j << '\n';
        cout << 0 << '\n';
        return 0;
      }
      cell[i][j] = 1;
    }
    if (c < h) {
      if (cell[c][j] == 1) {
        cout << 0 << '\n';
        return 0;
      }
      cell[c][j] = 0;
    }
    // REP(i, h) {
    //   REP(j, w) cout << cell[i][j] << ' ';
    //   cout << '\n';
    // }
  }
  long long ans = 1;
  REP(i, h) REP(j, w) {
    if (cell[i][j] == -1) (ans <<= 1) %= MOD;
  }
  cout << ans << '\n';
  return 0;
}