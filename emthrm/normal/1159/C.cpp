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
  vector<int> b(n), g(m);
  REP(i, n) cin >> b[i];
  REP(i, m) cin >> g[i];
  sort(ALL(b));
  sort(ALL(g));
  if (b.back() > g.front()) {
    cout << -1 << '\n';
    return 0;
  }
  long long ans = 0;
  if (b[n - 1] == g[0]) {
    REP(i, n - 1) ans += (long long)m * b[i];
    REP(i, m) ans += g[i];
  } else {
    REP(i, n - 2) ans += (long long)m * b[i];
    ans += (long long)(m - 1) * b[n - 2];
    ans += g[0];
    ans += b[n - 1];
    FOR(i, 1, m) ans += g[i];
  }
  cout << ans << '\n';
  return 0;
}