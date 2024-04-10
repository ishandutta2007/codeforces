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
int q(int y1, int x1, int y2, int x2) {
  cout << "? " << y1 + 1 << ' ' << x1 + 1 << ' ' << y2 + 1 << ' ' << x2 + 1 << endl;
  int res; cin >> res;
  if (res == -1) assert(false);
  return res;
}

void solve(vector<vector<int> > &ans, bool correct) {
  int n = ans.size();
  if (!correct) {
    REP(i, n) REP(j, n) {
      if ((i + j) & 1) ans[i][j] ^= 1;
    }
  }
  cout << "!\n";
  REP(i, n) {
    REP(j, n) cout << ans[i][j];
    cout << endl;
  }
  exit(0);
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<vector<int> > ans(n, vector<int>(n, -1));
  ans[0][0] = 1;
  ans[0][1] = 0;
  ans[n - 1][n - 1] = 0;
  REP(i, n) FOR(j, 1, n) if (ans[i][j] == -1) {
    int y1 = (i == 0 ? i : i == 1 ? i - 1 : i - 2), x1 = (i == 0 ? j - 2 : i == 1 ? j - 1 : j);
    ans[i][j] = ans[y1][x1] ^ (q(y1, x1, i, j) == 0 ? 1 : 0);
  }
  FOR(i, 1, n) ans[i][0] = ans[i][2] ^ (q(i, 0, i, 2) == 0 ? 1 : 0);
  REP(i, n - 1) {
    vector<int> y1{i, i + 1}, x1{i + 1, i}, y2, x2;
    if (i - 1 >= 0) {
      y2.emplace_back(i - 1);
      x2.emplace_back(i);
      y2.emplace_back(i);
      x2.emplace_back(i - 1);
    }
    if (i + 2 < n) {
      y2.emplace_back(i + 2);
      x2.emplace_back(i + 1);
      y2.emplace_back(i + 1);
      x2.emplace_back(i + 2);
    }
    if (ans[i][i] == ans[i + 1][i + 1]) {
      REP(a, y1.size()) REP(b, y2.size()) {
        vector<pair<int, int> > points{{i, i}, {i + 1, i + 1}, {y1[a], x1[a]}, {y2[b], x2[b]}};
        sort(ALL(points));
        if (ans[y1[a]][x1[a]] == ans[y2[b]][x2[b]]) {
          int Y1 = points[0].first, X1 = points[0].second, Y2 = points[1].first, X2 = points[1].second;
          solve(ans, q(points[0].first, points[0].second, points[3].first, points[3].second) == 1 ? ans[Y1][X1] == ans[Y2][X2] : ans[Y1][X1] != ans[Y2][X2]);
        }
      }
    } else {
      REP(a, y1.size()) REP(b, y2.size()) {
        vector<pair<int, int> > points{{i, i}, {i + 1, i + 1}, {y1[a], x1[a]}, {y2[b], x2[b]}};
        sort(ALL(points));
        if (ans[y1[a]][x1[a]] != ans[y2[b]][x2[b]]) {
          int Y1 = points[0].first, X1 = points[0].second, Y2 = points[1].first, X2 = points[1].second;
          solve(ans, q(points[0].first, points[0].second, points[3].first, points[3].second) == 1 ? ans[Y1][X1] != ans[Y2][X2] : ans[Y1][X1] == ans[Y2][X2]);
        }
      }
    }
  }
  solve(ans, true);
  return 0;
}