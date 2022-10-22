#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
int main() {
  long long n, k; cin >> n >> k;
  if (k == 1) {
    cout << n << '\n';
    return 0;
  }
  long long odd_lb = 0, odd_ub = (n + 1) / 2;
  while (odd_ub - odd_lb > 1) {
    long long mid = (odd_lb + odd_ub) / 2, now = mid * 2 + 1;
    if (now > n) {
      odd_ub = mid;
      continue;
    }
    long long need = now, sum = 1, len = 1;
    while (sum < k) {
      len *= 2;
      if (sum + len >= k) {
        if (log10(len) + log10(now) < 18.5) {
          need = len * now + (k - sum - 1);
        } else {
          need = LINF;
        }
        break;
      } else {
        sum += len;
      }
    }
    (need <= n ? odd_lb : odd_ub) = mid;
  }
  long long even_lb = 0, even_ub = (n + 1) / 2;
  while (even_ub - even_lb > 1) {
    long long mid = (even_lb + even_ub) / 2, now = mid * 2;
    if (now > n) {
      even_ub = mid;
      continue;
    }
    long long need = now + 1, sum = 2, len = 2;
    while (sum < k) {
      len *= 2;
      if (sum + len >= k) {
        if (log10(len / 2) + log10(now) < 18.5) {
          need = len / 2 * now + (k - sum - 1);
        } else {
          need = LINF;
        }
        break;
      } else {
        sum += len;
      }
    }
    (need <= n ? even_lb : even_ub) = mid;
  }
  cout << max(odd_lb * 2 + 1, even_lb * 2) << '\n';
  return 0;
}