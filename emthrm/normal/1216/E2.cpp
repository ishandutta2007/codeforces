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
long long f(long long mid) {
  if (mid == 0) return 0;
  int len = to_string(mid).length();
  long long res = 0, a1 = 1;
  FOR(i, 1, len + 1) {
    long long cnt = 9;
    if (i == len) {
      long long hiku = 1;
      int tmp = 0;
      while (tmp < 18 && hiku * 10 <= mid) {
        ++tmp;
        hiku *= 10;
      }
      cnt = mid - hiku + 1;
    } else {
      REP(j, i - 1) cnt *= 10;
    }
    if (cnt & 1) {
      res += cnt * (a1 + (cnt - 1) / 2 * i);
    } else {
      res += cnt / 2 * (2 * a1 + (cnt - 1) * i);
    }
    if (i < len) {
      a1 += (cnt - 1) * i;
      a1 += i + 1;
    }
  }
  return res;
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  while (q--) {
    long long k; cin >> k;
    long long lb = 0, ub = 1000000000;
    while (ub - lb > 1) {
      long long mid = (lb + ub) / 2;
      (f(mid) < k ? lb : ub) = mid;
    }
    k -= f(lb);
    for (int i = 1; ; ++i) {
      long long cnt = 9;
      REP(j, i - 1) cnt *= 10;
      if (k - cnt * i <= 0) {
        long long start = 1;
        REP(j, i - 1) start *= 10;
        long long tmp = k / i;
        if (k % i == 0) --tmp;
        start += tmp;
        k -= tmp * i;
        cout << to_string(start)[k - 1] << '\n';
        break;
      } else {
        k -= cnt * i;
      }
    }
  }
  return 0;
}