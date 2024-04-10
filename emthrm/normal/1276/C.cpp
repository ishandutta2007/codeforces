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
  map<int, int> cnt;
  REP(_, n) {
    int a; cin >> a;
    ++cnt[a];
  }
  vector<int> prs;
  for (auto &pr : cnt) prs.emplace_back(pr.second);
  sort(ALL(prs));
  int m = prs.size(), idx = 0, sum = 0, h = 1, w = 1;
  for (int y = 1; y * y <= n; ++y) {
    while (idx < m && prs[idx] <= y) sum += prs[idx++];
    int can = sum + (m - idx) * y, col = can / y;
    // cout << y << ' ' << col << ' ';
    if (col >= y && y * col > h * w) {
      h = y;
      w = col;
    }
    // cout << h << ' ' << w << '\n';
  }
  cout << h * w << '\n' << h << ' ' << w << '\n';
  vector<pair<int, int> > tsukau;
  for (auto &pr : cnt) {
    int tmp = min(h, pr.second);
    tsukau.emplace_back(tmp, pr.first);
  }
  sort(tsukau.rbegin(), tsukau.rend());
  vector<int> use;
  for (auto &pr : tsukau) {
    REP(_, pr.first) use.emplace_back(pr.second);
  }
  use.reserve(h * w);
  vector<vector<int> > ans(h, vector<int>(w, -1));
  int now = 0;
  REP(j, w) {
    REP(y, h) {
      int x = (j + y) % w;
      ans[y][x] = use[now++];
    }
  }
  REP(i, h) {
    REP(j, w) cout << ans[i][j] << ' ';
    cout << '\n';
  }
  return 0;
}