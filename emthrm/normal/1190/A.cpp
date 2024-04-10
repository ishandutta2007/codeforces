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
#define int long long

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  long long n; int m, k; cin >> n >> m >> k;
  if (m == 1) {
    cout << 1 << '\n';
    return 0;
  }
  if (k == 1) {
    cout << m << '\n';
    return 0;
  }
  vector<long long> p(m);
  REP(i, m) {
    cin >> p[i]; --p[i];
  }
  long long page = p.front() / k * k, nx = page + k;
  int idx = 0, ans = 0;
  while (idx < m) {
    ++ans;
    int tmp = lower_bound(ALL(p), nx) - p.begin();
    // cout << tmp << ' ' << page << ' ' << nx << '\n';
    nx += tmp - idx;
    idx = tmp;
    if (idx < m) {
      if (p[idx] < nx) continue;
      page = nx;
      page += (p[idx] - page) / k * k;
      nx = page + k;
    }
  }
  cout << ans << '\n';
  return 0;
}