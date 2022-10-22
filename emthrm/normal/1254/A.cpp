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
#include <iostream>
#include <iomanip>
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
void solve() {
  int r, c, k; cin >> r >> c >> k;
  vector<string> field(r); REP(i, r) cin >> field[i];
  int rice = 0;
  REP(i, r) REP(j, c) rice += field[i][j] == 'R';
  vector<int> ge(k, rice / k);
  REP(i, rice % k) ++ge[i];
  vector<char> sign(k);
  for (int i = 0; i < 26 && i < k; ++i) sign[i] = 'a' + i;
  for (int i = 26; i < 52 && i < k; ++i) sign[i] = 'A' + (i - 26);
  for (int i = 52; i < 62 && i < k; ++i) sign[i] = '0' + (i - 52);
  ge.emplace_back(INF);
  sign.emplace_back(sign[k - 1]);
  vector<vector<char> > ans(r, vector<char>(c, '.'));
  int now = 0;
  REP(i, r) {
    if (i % 2 == 0) {
      REP(j, c) {
        ans[i][j] = sign[now];
        if (field[i][j] == 'R') {
          --ge[now];
          if (ge[now] == 0) ++now;
        }
      }
    } else {
      for (int j = c - 1; j >= 0; --j) {
        ans[i][j] = sign[now];
        if (field[i][j] == 'R') {
          --ge[now];
          if (ge[now] == 0) ++now;
        }
      }
    }
  }
  REP(i, r) {
    REP(j, c) cout << ans[i][j];
    cout << '\n';
  }
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}