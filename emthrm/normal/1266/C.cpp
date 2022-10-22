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
  // FOR(r, 1, 100) FOR(c, 1, 100){
  int r, c; cin >> r >> c;
  if (r == 1 && c == 1) {
    cout << 0 << '\n';
    return 0;
    // continue;
  }
  if (c == 1) {
    FOR(i, 2, r + 2) cout << i << '\n';
    return 0;
  }
  vector<vector<int> > a(r, vector<int>(c));
  REP(j, c) a[0][j] = j + 2;
  FOR(i, 1, r) REP(j, c) a[i][j] = (c + 1 + i) * a[0][j];
  REP(i, r) REP(j, c) cout << a[i][j] << " \n"[j + 1 == c];
  // cout << a[r - 1][c - 1] << '\n';
  // set<int> st;
  // REP(i, r) {
  //   int g = a[i][0];
  //   FOR(j, 1, c) g = __gcd(g, a[i][j]);
  //   st.emplace(g);
  // }
  // REP(j, c) {
  //   int g = a[0][j];
  //   FOR(i, 1, r) g = __gcd(g, a[i][j]);
  //   st.emplace(g);
  // }
  // cout << st.size() << ' ' << *st.rbegin() << '\n';
  // if (st.size() != *st.rbegin()) cout << r << ' ' << c << '\n';
  // }
  return 0;
}