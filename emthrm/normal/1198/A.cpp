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

#define int long long
#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const double EPS = 1e-8;
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
signed main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, I; cin >> n >> I;
  if (I >= 3600000) {
    cout << 0 << '\n';
    return 0;
  }
  int k;
  for (k = 2; k <= n; ++k) {
    long long tmp = ceil(log2(k));
    if (n * tmp > 8 * I) break;
  }
  --k;
  vector<int> a(n), pre;
  REP(i, n) {
    cin >> a[i];
    pre.emplace_back(a[i]);
  }
  sort(ALL(pre));
  pre.erase(unique(ALL(pre)), pre.end());
  if (pre.size() <= k) {
    cout << 0 << '\n';
    return 0;
  }
  int sz = pre.size();
  vector<int> rui(sz + 1, 0);
  REP(i, n) ++rui[(lower_bound(ALL(pre), a[i]) - pre.begin()) + 1];
  FOR(i, 1, sz + 1) rui[i] += rui[i - 1];
  int ans = n;
  REP(i, sz - k + 1) ans = min(ans, n - (rui[i + k] - rui[i]));
  cout << ans << '\n';
  return 0;
}