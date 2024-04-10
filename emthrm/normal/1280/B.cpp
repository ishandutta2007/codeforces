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
void solve() {
  int r, c; cin >> r >> c;
  vector<string> grid(r); REP(i, r) cin >> grid[i];
  bool mortal = true;
  REP(i, r) REP(j, c) mortal &= grid[i][j] == 'P';
  if (mortal) {
    cout << "MORTAL\n";
    return;
  }
  bool being = true;
  REP(i, r) REP(j, c) being &= grid[i][j] == 'A';
  if (being) {
    cout << 0 << '\n';
    return;
  }
  bool all_a = true;
  REP(j, c) all_a &= grid[0][j] == 'A';
  if (all_a) {
    cout << 1 << '\n';
    return;
  }
  all_a = true;
  REP(j, c) all_a &= grid[r - 1][j] == 'A';
  if (all_a) {
    cout << 1 << '\n';
    return;
  }
  all_a = true;
  REP(i, r) all_a &= grid[i][0] == 'A';
  if (all_a) {
    cout << 1 << '\n';
    return;
  }
  all_a = true;
  REP(i, r) all_a &= grid[i][c - 1] == 'A';
  if (all_a) {
    cout << 1 << '\n';
    return;
  }
  FOR(i, 1, r - 1) {
    bool all_a2 = true;
    REP(j, c) all_a2 &= grid[i][j] == 'A';
    if (all_a2) {
      cout << 2 << '\n';
      return;
    }
  }
  FOR(j, 1, c - 1) {
    bool all_a2 = true;
    REP(i, r) all_a2 &= grid[i][j] == 'A';
    if (all_a2) {
      cout << 2 << '\n';
      return;
    }
  }
  if (grid[0][0] == 'A' || grid[0][c - 1] == 'A' || grid[r - 1][0] == 'A' || grid[r - 1][c - 1] == 'A') {
    cout << 2 << '\n';
    return;
  }
  bool all_p = true;
  REP(i, r) {
    all_p &= grid[i][0] == 'P';
    all_p &= grid[i][c - 1] == 'P';
  }
  REP(j, c) {
    all_p &= grid[0][j] == 'P';
    all_p &= grid[r - 1][j] == 'P';
  }
  cout << (all_p ? 4 : 3) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}