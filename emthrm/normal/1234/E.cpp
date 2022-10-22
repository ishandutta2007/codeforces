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
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<int> x(m); REP(i, m) cin >> x[i];
  vector<vector<int> > idx(n + 1);
  REP(i, m) idx[x[i]].emplace_back(i);
  vector<int> a(x);
  long long ans = 0;
  REP(i, m - 1) ans += abs(a[i] - a[i + 1]);
  cout << ans << ' ';
  FOR(i, 1, n) {
    for (int e : idx[i]) {
      if (e - 1 >= 0) ans -= abs(a[e - 1] - a[e]);
      if (e + 1 < m) ans -= abs(a[e] - a[e + 1]);
      a[e] = i + 1;
      if (e - 1 >= 0) ans += abs(a[e - 1] - a[e]);
      if (e + 1 < m) ans += abs(a[e] - a[e + 1]);
      // cout << ans << '\n';
    }
    for (int e : idx[i + 1]) {
      if (e - 1 >= 0) ans -= abs(a[e - 1] - a[e]);
      if (e + 1 < m) ans -= abs(a[e] - a[e + 1]);
      a[e] = 1;
      if (e - 1 >= 0) ans += abs(a[e - 1] - a[e]);
      if (e + 1 < m) ans += abs(a[e] - a[e + 1]);
      // cout << ans << '\n';
    }
    cout << ans << (i + 1 == n ? '\n' : ' ');
  }
  return 0;
}