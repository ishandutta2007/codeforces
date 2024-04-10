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
#include <iostream>
#include <iomanip>
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
  long long n, p; cin >> n >> p;
  if (1 + p > n) {
    cout << -1 << '\n';
    return 0;
  }
  for (int ans = 1; ; ++ans) {
    long long tmp = n - p * ans;
    if (tmp <= 0) {
      cout << -1 << '\n';
      return 0;
    }
    long long cnt = 0;
    REP(i, 64) {
      if (tmp >> i & 1) cnt += i + 1;
    }
    if (__builtin_popcount(tmp) <= ans && cnt >= ans) {
      cout << ans << '\n';
      return 0;
    }
  }
}