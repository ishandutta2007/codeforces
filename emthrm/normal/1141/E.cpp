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

  long long h; int n; cin >> h >> n;
  vector<int> d(n); REP(i, n) cin >> d[i];
  vector<long long> utsuru(n);
  long long mn = LINF;
  int idx;
  REP(i, n) {
    utsuru[i] = d[i];
    if (i > 0) utsuru[i] += utsuru[i - 1];
    if (utsuru[i] < mn) {
      mn = utsuru[i];
      idx = i;
    }
  }
  if (h + mn > 0 && utsuru.back() >= 0) {
    cout << -1 << '\n';
    return 0;
  }
  long long rou = h + mn, ans = 0;
  if (rou > 0) {
    ans = ((rou - utsuru.back() - 1) / -utsuru.back()) * n;
    h += utsuru.back() * (ans / n);
  }
  REP(i, n) {
    ++ans;
    h += d[i];
    if (h <= 0) break;
  }
  cout << ans << '\n';
  return 0;
}