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
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<int> > ob_row(n), ob_col(m);
  REP(i, n) {
    ob_row[i].emplace_back(-1);
    ob_row[i].emplace_back(m);
  }
  REP(j, m) {
    ob_col[j].emplace_back(-1);
    ob_col[j].emplace_back(n);
  }
  REP(_, k) {
    int y, x; cin >> y >> x; --y; --x;
    ob_row[y].emplace_back(x);
    ob_col[x].emplace_back(y);
  }
  REP(i, n) sort(ALL(ob_row[i]));
  REP(j, m) sort(ALL(ob_col[j]));
  vector<int> row_l(n, 0), row_r(n);
  REP(i, n) row_r[i] = ob_row[i].size() - 1;
  vector<int> col_u(m, 0), col_d(m);
  REP(j, m) col_d[j] = ob_col[j].size() - 1;
  int up = -1, down = n, left = -1, right = m, y = 0, x = 0;
  long long passed = 1;
  while (true) {
    while (row_r[y] - 1 > row_l[y] && ob_row[y][row_r[y] - 1] > x) --row_r[y];
    int wall = min(ob_row[y][row_r[y]], right);
    if (x + 1 == wall) {
      if (x != 0 || y != 0) break;
    }
    right = wall;
    up = y;
    passed += wall - x - 1;
    x = wall - 1;
    while (col_d[x] - 1 > col_u[x] && ob_col[x][col_d[x] - 1] > y) --col_d[x];
    wall = min(ob_col[x][col_d[x]], down);
    if (y + 1 == wall) break;
    down = wall;
    right = x;
    passed += wall - y - 1;
    y = wall - 1;
    while (row_l[y] + 1 < row_r[y] && ob_row[y][row_l[y] + 1] < x) ++row_l[y];
    wall = max(ob_row[y][row_l[y]], left);
    if (wall + 1 == x) break;
    left = wall;
    down = y;
    passed += x - wall - 1;
    x = wall + 1;
    while (col_u[x] + 1 < col_d[x] && ob_col[x][col_u[x] + 1] < y) ++col_u[x];
    wall = max(ob_col[x][col_u[x]], up);
    if (wall + 1 == y) break;
    up = wall;
    left = x;
    passed += y - wall - 1;
    y = wall + 1;
  }
  cout << (passed == (long long)n * m - k ? "Yes\n" : "No\n");
  return 0;
}