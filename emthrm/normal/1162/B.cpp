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

  int n, m; cin >> n >> m;
  vector<vector<int> > a(n, vector<int>(m)), b(n, vector<int>(m));
  REP(i, n) REP(j, m) cin >> a[i][j];
  REP(i, n) REP(j, m) cin >> b[i][j];
  REP(i, n) REP(j, m) {
    if (a[i][j] > b[i][j]) swap(a[i][j], b[i][j]);
  }
  REP(i, n) FOR(j, 1, m) {
    if (a[i][j - 1] >= a[i][j] || b[i][j - 1] >= b[i][j]) {
      cout << "Impossible\n";
      return 0;
    }
  }
  REP(j, m) FOR(i, 1, n) {
    if (a[i - 1][j] >= a[i][j] || b[i - 1][j] >= b[i][j]) {
      cout << "Impossible\n";
      return 0;
    }
  }
  cout << "Possible\n";
  return 0;
}