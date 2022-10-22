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
  int n; cin >> n;
  int mn_x = INF, mn_y = INF;
  vector<int> x(n), y(n);
  REP(i, n) {
    cin >> x[i] >> y[i];
    mn_x = min(mn_x, x[i]);
    mn_y = min(mn_y, y[i]);
  }
  REP(i, n) {
    x[i] -= mn_x;
    y[i] -= mn_y;
  }
  while (true) {
    bool same = true;
    FOR(i, 1, n) same &= (x[0] + y[0]) % 2 == (x[i] + y[i]) % 2;
    if (!same) {
      vector<int> ans;
      REP(i, n) {
        if ((x[i] + y[i]) & 1) ans.emplace_back(i);
      }
      cout << ans.size() << '\n';
      REP(i, ans.size()) cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
      return 0;
    }
    if ((x[0] + y[0]) & 1) {
      REP(i, n) ++x[i];
    }
    same = false;
    FOR(i, 1, n) same |= x[0] % 2 != x[i] % 2;
    if (same) {
      vector<int> ans;
      REP(i, n) {
        if (x[i] & 1) ans.emplace_back(i);
      }
      cout << ans.size() << '\n';
      REP(i, ans.size()) cout << ans[i] + 1 << " \n"[i + 1 == ans.size()];
      return 0;
    }
    if (x[0] & 1) {
      REP(i, n) {
        ++x[i];
        ++y[i];
      }
    }
    REP(i, n) {
      x[i] /= 2;
      y[i] /= 2;
    }
  }
}