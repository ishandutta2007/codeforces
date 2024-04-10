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
const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  map<int, int> mp;
  vector<vector<int> > a(n);
  REP(i, n) {
    int aa; cin >> aa;
    while (aa > 0) {
      a[i].emplace_back(aa % 10);
      aa /= 10;
    }
    ++mp[a[i].size()];
  }
  vector<long long> ten(20, 1);
  FOR(i, 1, 20) ten[i] = ten[i - 1] * 10 % MOD;
  long long ans = 0;
  REP(i, n) {
    for (auto p : mp) if (p.second > 0) {
      long long tmp = 0;
      int idx = 0;
      REP(j, a[i].size()) {
        idx += (j < p.first ? 2 : 1);
        (tmp += a[i][j] * ten[idx - 1] % MOD) %= MOD;
      }
      // cout << tmp << ' ';
      long long tmp2 = a[i][0];
      idx = 1;
      FOR(j, 1, a[i].size()) {
        idx += (j <= p.first ? 2 : 1);
        (tmp2 += a[i][j] * ten[idx - 1] % MOD) %= MOD;
      }
      // cout << tmp2 << '\n';
      (ans += (tmp + tmp2) % MOD * p.second % MOD) %= MOD;
    }
  }
  cout << ans << '\n';
  return 0;
}