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

  int q; cin >> q;
  while (q--) {
    long long a, b, m; cin >> a >> b >> m;
    if (a == b) {
      cout << 1 << ' ' << a << '\n';
      continue;
    }
    int k = 0;
    long long base = a, keisu = 1, memo;
    bool exist = true;
    while (true) {
      ++k;
      if (b < base + keisu) {
        exist = false;
        break;
      }
      if (b <= base + keisu * m) {
        memo = b - base;
        break;
      }
      base *= 2;
      keisu *= 2;
    }
    if (!exist) {
      cout << -1 << '\n';
      continue;
    }
    vector<long long> kake(k, 1);
    FOR(i, 1, k) {
      REP(j, i - 1) kake[i] *= 2;
    }
    reverse(ALL(kake));
    vector<long long> x(k, 1);
    REP(i, k) memo -= kake[i] * x[i];
    REP(i, k) {
      long long tmp = memo / kake[i];
      if (tmp >= m) {
        x[i] += m - 1;
        memo -= (m - 1) * kake[i];
      } else {
        x[i] += tmp;
        memo -= tmp * kake[i];
      }
    }
    if (memo > 0) assert(false);
    vector<long long> ans(k + 1);
    ans[0] = a;
    long long sum = a;
    FOR(i, 1, k + 1) {
      ans[i] = sum + x[i - 1];
      sum += ans[i];
    }
    if (ans[k] != b) assert(false);
    cout << k + 1 << ' ';
    REP(i, k + 1) cout << ans[i] << (i == k ? '\n' : ' ');
  }
  return 0;
}