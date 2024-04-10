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

  int q; cin >> q;
  while (q--) {
    int n; cin >> n;
    vector<long long> a(n), b(n); REP(i, n) cin >> a[i] >> b[i];
    vector<vector<long long> > dp(n, vector<long long>(4, LINF));
    REP(j, 4) dp[0][j] = b[0] * j;
    FOR(i, 1, n) {
      REP(j, 4) REP(k, 4) {
        if (a[i - 1] + j != a[i] + k) dp[i][k] = min(dp[i][k], dp[i - 1][j] + b[i] * k);
      }
    }
    cout << *min_element(ALL(dp[n - 1])) << '\n';
  }
  return 0;
}