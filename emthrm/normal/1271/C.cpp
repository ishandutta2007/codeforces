#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int main() {
  const int MAX = 1000000000;
  int n, sx, sy; cin >> n >> sx >> sy;
  vector<int> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  int ans = -INF, px, py;
  REP(k, 4) {
    int gx = sx + dx[k], gy = sy + dy[k];
    if (gx < 0 || MAX < gx || gy < 0 || MAX < gy) continue;
    int cnt = 0;
    REP(i, n) {
      if (k == 0) {
        cnt += y[i] >= gy;
      } else if (k == 1) {
        cnt += x[i] <= gx;
      } else if (k == 2) {
        cnt += y[i] <= gy;
      } else {
        cnt += x[i] >= gx;
      }
    }
    if (cnt > ans) {
      ans = cnt;
      px = gx;
      py = gy;
    }
  }
  cout << ans << '\n' << px << ' ' << py << '\n';
  return 0;
}