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

  long long k; cin >> k;
  // FOR(k, 1, 22) {
  int cnt = 1;
  long long l = 1, r = 9, sum = 0;
  while (true) {
    if (sum + (r - l + 1) * cnt >= k) break;
    sum += (r - l + 1) * cnt;
    ++cnt;
    l *= 10;
    r = r * 10 + 9;
  }
  l += (k - sum) / cnt;
  sum += (k - sum) / cnt * cnt;
  if (k == sum) {
    string ans = to_string(l - 1);
    cout << ans.back() << '\n';
  } else {
    string ans = to_string(l);
    cout << ans[k - sum - 1] << '\n';
  }
  // }
  return 0;
}