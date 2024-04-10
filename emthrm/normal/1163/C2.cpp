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

  int n; cin >> n;
  vector<int> x(n), y(n); REP(i, n) cin >> x[i] >> y[i];
  long long ans = 0;
  int line = 0;
  using P = pair<int, int>;
  map<P, int> mp;
  set<pair<P, P> > slope;
  REP(i, n) {
    FOR(j, i + 1, n) {
      int ka_bunshi = y[j] - y[i], ka_bunbo = x[j] - x[i];
      if (ka_bunbo == 0) {
        ka_bunshi = ka_bunbo = INF;
      } else {
        if (ka_bunshi < 0) {
          ka_bunshi *= -1;
          ka_bunbo *= -1;
        }
        int yaku = __gcd(ka_bunshi, ka_bunbo);
        ka_bunshi /= yaku;
        ka_bunbo /= yaku;
      }
      P ka = {ka_bunshi, ka_bunbo};
      int se_bunshi, se_bunbo;
      if (ka_bunshi == INF) {
        se_bunshi = se_bunbo = x[i];
      } else {
        se_bunshi = ka_bunbo * y[i] - ka_bunshi * x[i];
        se_bunbo = ka_bunbo;
        if (se_bunshi < 0) {
          se_bunshi *= -1;
          se_bunbo *= -1;
        }
        int yaku = __gcd(se_bunshi, se_bunbo);
        se_bunshi /= yaku;
        se_bunbo /= yaku;
      }
      P se = {se_bunshi, se_bunbo};
      if (slope.count({ka, se}) > 0) continue;
      slope.insert({ka, se});
      ans += line - mp[ka];
      ++mp[ka];
      ++line;
    }
  }
  cout << ans << '\n';
  return 0;
}