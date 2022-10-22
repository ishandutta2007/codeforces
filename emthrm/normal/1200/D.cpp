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

  int n, k; cin >> n >> k;
  vector<vector<char> > cf(n + 1, vector<char>(n + 1)); FOR(i, 1, n + 1) FOR(j, 1, n + 1) cin >> cf[i][j];
  vector<vector<int> > imos(n + 1, vector<int>(n + 1, 0));
  FOR(i, 1, n + 1) {
    int mn = n + 1, mx = 0;
    FOR(j, 1, n + 1) if (cf[i][j] == 'B') {
      mn = min(mn, j);
      mx = max(mx, j);
    }
    if (mx == 0) {
      ++imos[1][1];
      continue;
    }
    if (mx - mn + 1 > k) continue;
    int y1 = max(i - k + 1, 1), x1 = max(mx - k + 1, 1), y2 = i, x2 = mn;
    ++imos[y1][x1];
    if (y2 + 1 <= n) --imos[y2 + 1][x1];
    if (x2 + 1 <= n) --imos[y1][x2 + 1];
    if (y2 + 1 <= n && x2 + 1 <= n) ++imos[y2 + 1][x2 + 1];
  }
  FOR(j, 1, n + 1) {
    int mn = n + 1, mx = 0;
    FOR(i, 1, n + 1) if (cf[i][j] == 'B') {
      mn = min(mn, i);
      mx = max(mx, i);
    }
    if (mx == 0) {
      ++imos[1][1];
      continue;
    }
    if (mx - mn + 1 > k) continue;
    int y1 = max(mx - k + 1, 1), x1 = max(j - k + 1, 1), y2 = mn, x2 = j;
    ++imos[y1][x1];
    if (y2 + 1 <= n) --imos[y2 + 1][x1];
    if (x2 + 1 <= n) --imos[y1][x2 + 1];
    if (y2 + 1 <= n && x2 + 1 <= n) ++imos[y2 + 1][x2 + 1];
  }
  FOR(i, 2, n + 1) {
    FOR(j, 1, n + 1) imos[i][j] += imos[i - 1][j];
  }
  FOR(j, 2, n + 1) {
    FOR(i, 1, n + 1) imos[i][j] += imos[i][j - 1];
  }
  int ans = 0;
  FOR(i, 1, n - k + 2) FOR(j, 1, n - k + 2) ans = max(ans, imos[i][j]);
  cout << ans << '\n';
  return 0;
}