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
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m)); REP(i, n) REP(j, m) cin >> a[i][j];
    vector<int> idx(m), mx(m, 0);
    iota(ALL(idx), 0);
    REP(j, m) {
      REP(i, n) mx[j] = max(mx[j], a[i][j]);
    }
    sort(ALL(idx), [&](int l, int r) { return mx[l] > mx[r]; });
    m = min(m, n);
    vector<vector<int> > mat(n, vector<int>(m));
    REP(j, m) {
      REP(i, n) mat[i][j] = a[i][idx[j]];
    }
    vector<vector<int> > dp1(m, vector<int>(1 << n, 0));
    REP(j, m) REP(i, 1 << n) {
      REP(k, n) {
        int sum = 0;
        REP(l, n) if (i >> l & 1) sum += mat[(k + l) % n][j];
        dp1[j][i] = max(dp1[j][i], sum);
      }
    }
    vector<int> dp2(1 << n, 0);
    REP(j, m) REP(i, 1 << n) {
      int sub = i;
      do {
        dp2[i ^ sub] = max(dp2[i ^ sub], dp2[i] + dp1[j][sub]);
        sub = (sub - 1) & i;
      } while (sub != i);
    }
    cout << dp2[0] << '\n';
  }
  return 0;
}