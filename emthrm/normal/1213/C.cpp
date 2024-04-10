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
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  while (q--) {
    long long n, m; cin >> n >> m;
    if (n < m) {
      cout << 0 << '\n';
      continue;
    }
    long long tm = n / m;
    vector<int> last;
    long long test = 0;
    while (test + m <= n) {
      test += m;
      if (find(ALL(last), test % 10) != last.end()) break;
      last.emplace_back(test % 10);
    }
    long long sum = 0;
    for (int e : last) sum += e;
    long long ans = 0;
    tm /= (int)last.size();
    ans += sum * tm;
    long long sim = m * tm * (int)last.size();
    while (sim + m <= n) {
      sim += m;
      ans += sim % 10;
    }
    cout << ans << '\n';
  }
  return 0;
}