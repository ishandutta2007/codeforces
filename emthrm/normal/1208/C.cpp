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
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<vector<int> > ans(n, vector<int>(n));
  int magic = 0;
  for (int i = 0; i < n; i += 2) for (int j = 0; j < n; j += 2) {
    ans[i][j] = magic;
    ans[i][j + 1] = magic + 1;
    ans[i + 1][j] = magic + 2;
    ans[i + 1][j + 1] = magic + 3;
    magic += 4;
  }
  // REP(i, n) {
  //   int val = 0;
  //   REP(j, n) val ^= ans[i][j];
  //   cout << val << '\n';
  // }
  // REP(j, n) {
  //   int val = 0;
  //   REP(i, n) val ^= ans[i][j];
  //   cout << val << '\n';
  // }
  REP(i, n) {
    REP(j, n) cout << ans[i][j] << (j + 1 == n ? '\n' : ' ');
  }
  return 0;
}