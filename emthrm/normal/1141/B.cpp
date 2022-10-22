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
  vector<int> a(2*n); REP(i, n) cin >> a[i];
  FOR(i, n, 2*n) a[i] = a[i-n];
  int ans = 0;
  REP(i, 2*n) {
    if (a[i] == 1) {
      int tmp = 1;
      while (i+1 < 2*n && a[i+1] == 1) {
        ++tmp;
        ++i;
      }
      ans = max(ans, tmp);
    }
  }
  cout << ans << '\n';
  return 0;
}