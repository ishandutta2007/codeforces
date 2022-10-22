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

  int t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    long long t1 = 2, t2, s1, s2 = -1;
    for (t2 = 0; (t2 + 1) * (t2 + 2) <= 2 * n; ++t2) {
      long long tmp = (t2 + 1) * (t2 + 2) / 2;
      s2 = n / tmp;
      s1 = n % tmp;
      if (t1 + t2 + s1 + s2 + 1 > 100000) {
        s2 = -1;
        continue;
      }
      break;
    }
    if (s2 == -1) assert(false);
    string ans = "1";
    REP(i, t1) ans += "3";
    REP(i, s1) ans += "7";
    REP(i, t2) ans += "3";
    REP(i, s2) ans += "7";
    // cout << t1 << ' ' << t2 << ' ' << s1 << ' ' << s2 << '\n';
    cout << ans << '\n';
    // cout << ans.size() << '\n';
  }
  return 0;
}