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
  vector<pair<int, int> > ab(n);
  vector<int> asort(300001, 0), bsort(300001, 0);
  REP(i, n) {
    cin >> ab[i].first >> ab[i].second;
    ++asort[ab[i].first];
    ++bsort[ab[i].second];
  }
  vector<long long> fact(n + 1);
  fact[0] = 1;
  FOR(i, 1, n + 1) fact[i] = fact[i - 1] * i % MOD;
  long long sna1 = 1, sna2 = 1;
  FOR(i, 1, 300001) {
    (sna1 *= fact[asort[i]]) %= MOD;
    (sna2 *= fact[bsort[i]]) %= MOD;
  }
  long long sna = (sna1 + sna2) % MOD;
  sort(ALL(ab));
  bool ok = true;
  FOR(i, 1, n) {
    if (ab[i - 1].second > ab[i].second) ok = false;
  }
  // cout << (ok ? 1 : 0) << '\n';
  if (ok) {
    map<pair<int, int>, int> mp;
    REP(i, n) {
      ++mp[make_pair(min(ab[i].first, ab[i].second), max(ab[i].first, ab[i].second))];
    }
    long long sna3 = 1;
    for (auto pr : mp) (sna3 *= fact[pr.second]) %= MOD;
    (sna -= sna3) %= MOD;
    if (sna < 0) sna += MOD;
  }
  long long ans = (fact[n] - sna) % MOD;
  if (ans < 0) ans += MOD;
  cout << ans << '\n';
  return 0;
}