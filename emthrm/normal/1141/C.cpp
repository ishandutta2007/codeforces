#include <algorithm>
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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f, MOD = 1000000007;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*-----------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<long long> q(n, 0); FOR(i, 1, n) cin >> q[i];
  long long mn = 0;
  FOR(i, 1, n) {
    q[i] += q[i - 1];
    mn = min(mn, q[i]);
  }
  mn *= -1;
  ++mn;
  vector<bool> p(n + 1, false);
  REP(i, n) {
    q[i] += mn;
    if (q[i] < 1 || n < q[i] || p[q[i]]) {
      cout << -1 << '\n';
      return 0;
    }
    p[q[i]] = true;
  }
  REP(i, n) cout << q[i] << (i == n - 1 ? '\n' : ' ');
  return 0;
}