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
    int n; long long x; cin >> n >> x;
    vector<long long> d(n), h(n); REP(i, n) cin >> d[i] >> h[i];
    vector<long long> diff(n);
    REP(i, n) diff[i] = d[i] - h[i];
    sort(ALL(diff), greater<long long>());
    sort(ALL(d), greater<long long>());
    if (diff[0] <= 0 && d[0] < x) {
      cout << -1 << '\n';
      continue;
    }
    cout << (x > d[0] ? (x - d[0] + diff[0] - 1) / diff[0] : 0) + 1 << '\n';
  }
  return 0;
}