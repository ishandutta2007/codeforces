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

  int n; cin >> n;
  vector<long long> a(n); REP(i, n) cin >> a[i];
  sort(ALL(a));
  long long ans = 0;
  REP(i, n) {
    if (a[i] < 0) {
      int idx = upper_bound(a.begin() + i, a.end(), (a[i] - 1) / 2) - a.begin();
      ans += idx - i - 1;
      int idx1 = lower_bound(a.begin() + i, a.end(), (-a[i] + 1) / 2) - a.begin();
      int idx2 = upper_bound(a.begin() + i, a.end(), -2 * a[i]) - a.begin();
      ans += idx2 - idx1;
    } else {
      int idx = upper_bound(a.begin() + i, a.end(), 2 * a[i]) - a.begin();
      ans += idx - i - 1;
    }
  }
  cout << ans << '\n';
  return 0;
}