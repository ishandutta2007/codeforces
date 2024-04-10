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

  int a1, a2, k1, k2, n; cin >> a1 >> a2 >> k1 >> k2 >> n;
  int tmp = n;
  tmp -= a1 * (k1 - 1);
  tmp -= a2 * (k2 - 1);
  cout << max(tmp, 0) << ' ';
  if (k1 > k2) {
    swap(a1, a2);
    swap(k1, k2);
  }
  int ans = 0;
  if (a1 * k1 < n) {
    ans += a1;
    n -= a1 * k1;
    ans += n / k2;
  } else {
    ans += n / k1;
  }
  cout << ans << '\n';
  return 0;
}