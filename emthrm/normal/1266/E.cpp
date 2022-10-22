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
  int n; cin >> n;
  vector<long long> a(n); REP(i, n) cin >> a[i];
  long long sum = accumulate(ALL(a), 0LL);
  vector<long long> cnt(n, 0);
  long long ans = 0;
  map<pair<int, int>, int> mp;
  int q; cin >> q;
  while (q--) {
    int s, t, u; cin >> s >> t >> u; --s;
    if (mp.count({s, t}) == 1) {
      int dst = mp[{s, t}];
      ans -= min(cnt[dst], a[dst]);
      --cnt[dst];
      ans += min(cnt[dst], a[dst]);
      mp.erase({s, t});
    }
    if (u != 0) {
      --u;
      ans -= min(cnt[u], a[u]);
      ++cnt[u];
      ans += min(cnt[u], a[u]);
      mp[{s, t}] = u;
    }
    cout << sum - ans << '\n';
  }
  return 0;
}