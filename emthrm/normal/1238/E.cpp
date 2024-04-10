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

  int n, m; cin >> n >> m;
  string str; cin >> str;
  vector<int> s(n);
  REP(i, n) s[i] = str[i] - 'a';
  vector<vector<int> > type(m, vector<int>(m, 0));
  FOR(i, 1, n) ++type[s[i - 1]][s[i]];
  vector<long long> dp(1 << m, LINF);
  dp[0] = 0;
  REP(i, 1 << m) {
    vector<int> left, right;
    REP(j, m) (i >> j & 1 ? left : right).emplace_back(j);
    long long slow = 0;
    for (int l : left) {
      for (int r : right) {
        slow += type[l][r];
        slow += type[r][l];
      }
    }
    for (int e : right) dp[i | (1 << e)] = min(dp[i | (1 << e)], dp[i] + slow);
  }
  cout << dp[(1 << m) - 1] << '\n';
  return 0;

  // vector<int> per(m);
  // iota(ALL(per), 0);
  // do {
  //   int ans = 0;
  //   vector<int> idx(m);
  //   REP(i, m) idx[per[i]] = i;
  //   FOR(i, 1, n) ans += abs(idx[s[i]] - idx[s[i - 1]]);
  //   REP(i, m) cout << per[i];
  //   cout << ' ' << ans << '\n';
  // } while (next_permutation(ALL(per)));
}