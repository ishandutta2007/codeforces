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
vector<long long> divisor(long long val) {
  vector<long long> res;
  for (long long i = 1; i * i <= val; ++i) {
    if (val % i == 0) {
      res.emplace_back(i);
      if (i * i != val) res.emplace_back(val / i);
    }
  }
  sort(ALL(res));
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<vector<int> > a(n, vector<int>(n)); REP(i, n) REP(j, n) cin >> a[i][j];
  int g = a[0][1];
  FOR(j, 2, n) g = __gcd(g, a[0][j]);
  vector<long long> d = divisor(g);
  for (int e : d) {
    vector<int> ans(n);
    ans[0] = e;
    bool ok = true;
    FOR(j, 1, n) ans[j] = a[0][j] / e;
    FOR(i, 1, n) {
      FOR(j, i + 1, n) {
        if (a[i][j] != (long long)ans[i] * ans[j]) {
          ok = false;
          break;
        }
      }
      if (!ok) break;
    }
    if (ok) {
      REP(i, n) cout << ans[i] << (i + 1 == n ? '\n' : ' ');
      return 0;
    }
  }
}