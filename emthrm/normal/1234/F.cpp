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
const int MOD = 1000000007; // 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
/*-------------------------------------------------*/
int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  string s; cin >> s;
  int n = s.length();
  vector<int> a(n);
  REP(i, n) a[i] = s[i] - 'a';
  vector<int> left(1 << 20, INF);
  vector<vector<int> > right(1 << 20, vector<int>(21, -INF));
  left[0] = -1;
  REP(i, 1 << 20) right[i][0] = n;
  REP(i, n) {
    int bit = 0;
    for (int j = i; j > i - 20; --j) {
      if (j < 0 || (bit >> a[j] & 1)) break;
      bit |= 1 << a[j];
      if (left[bit] == INF) left[bit] = i;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    int bit = 0;
    FOR(j, i, i + 20) {
      if (j >= n || (bit >> a[j] & 1)) break;
      bit |= 1 << a[j];
      if (right[bit][__builtin_popcount(bit)] == -INF) right[bit][__builtin_popcount(bit)] = i;
    }
  }
  REP(i, 1 << 20) {
    int cnt = __builtin_popcount(i);
    REP(j, cnt + 1) {
      REP(k, 20) if (!(i >> k & 1)) right[i | (1 << k)][j] = max(right[i | (1 << k)][j], right[i][j]);
    }
  }
  int ans = 0;
  REP(i, 1 << 20) if (left[i] != INF) {
    int rem = ((1 << 20) - 1) ^ i;
    for (int j = __builtin_popcount(rem); j >= 0; --j) {
      if (left[i] < right[rem][j]) {
        ans = max(ans, __builtin_popcount(i) + j);
        break;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}