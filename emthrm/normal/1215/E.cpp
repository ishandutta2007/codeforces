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

  int n; cin >> n;
  vector<int> a(n), comp(n);
  REP(i, n) {
    cin >> a[i];
    comp[i] = a[i];
  }
  sort(ALL(comp));
  comp.erase(unique(ALL(comp)), comp.end());
  REP(i, n) a[i] = lower_bound(ALL(comp), a[i]) - comp.begin();
  int m = comp.size();
  vector<vector<long long> > memo(m, vector<long long>(1 << m));
  REP(i, m) {
    vector<int> cnt(m, 0);
    vector<long long> cost(m, 0);
    REP(j, n) {
      if (a[j] == i) {
        REP(k, m) cost[k] += cnt[k];
      } else {
        ++cnt[a[j]];
      }
    }
    REP(j, 1 << m) {
      REP(k, m) if (j >> k & 1) memo[i][j] += cost[k];
    }
  }
  vector<long long> dp(1 << m, LINF);
  dp[0] = 0;
  REP(i, 1 << m) {
    REP(j, m) if (!(i >> j & 1)) {
      dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + memo[j][((1 << m) - 1) ^ (i | (1 << j))]);
    }
  }
  cout << dp[(1 << m) - 1] << '\n';
  return 0;
}