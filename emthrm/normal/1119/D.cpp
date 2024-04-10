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
  vector<long long> s(n); REP(i, n) cin >> s[i];
  sort(ALL(s));
  s.erase(unique(ALL(s)), s.end());
  n = s.size();
  vector<long long> diff(n);
  REP(i, n - 1) diff[i] = s[i + 1] - s[i] - 1;
  diff[n - 1] = LINF - s[n - 1];
  sort(ALL(diff));
  vector<long long> sum(n);
  REP(i, n) {
    sum[i] = diff[i];
    if (i > 0) sum[i] += sum[i - 1];
  }
  int q; cin >> q;
  while (q--) {
    long long l, r; cin >> l >> r;
    r -= l;
    int idx = upper_bound(ALL(diff), r) - diff.begin();
    long long ans = n;
    if (idx > 0) ans += sum[idx - 1];
    ans += r * (n - idx);
    cout << ans << (q == 0 ? '\n' : ' ');
  }
  return 0;
}