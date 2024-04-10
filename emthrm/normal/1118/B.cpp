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
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
/*----------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<long long> odd(n, 0), even(n, 0);
  even[0] = a[0];
  FOR(i, 1, n) {
    even[i] = even[i-1] + (i & 1 ? 0 : a[i]);
    odd[i] = odd[i-1] + (i & 1 ? a[i] : 0);
  }
  // REP(i, n) cout << even[i] << ' ' << odd[i] << '\n';
  int ans = 0;
  REP(i, n) {
    long long ev = (i==0?0:even[i-1]) + odd[n-1] - odd[i], od = (i==0?0:odd[i-1]) + even[n-1] - even[i];
    if (ev == od) ++ans;
  }
  cout << ans << '\n';
  return 0;
}