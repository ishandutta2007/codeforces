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

  int n; long long r; cin >> n >> r;
  vector<pair<int, int> > plus;
  vector<int> a, b;
  while (n--) {
    int ai, bi; cin >> ai >> bi;
    if (bi >= 0) {
      plus.emplace_back(ai, bi);
    } else {
      a.emplace_back(ai);
      b.emplace_back(bi);
    }
  }
  sort(ALL(plus));
  int ans = 0;
  REP(i, plus.size()) {
    if (plus[i].first > r) break;
    ++ans;
    r += plus[i].second;
  }
  n = a.size();
  vector<int> idx(n);
  iota(ALL(idx), 0);
  sort(ALL(idx), [&](int x, int y) {
    return a[x] + b[x] == a[y] + b[y] ? a[x] < a[y] : a[x] + b[x] < a[y] + b[y];
  });
  vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, LINF));
  dp[0][0] = 0;
  REP(i, n) REP(j, i + 1) {
    dp[i + 1][j + 1] = min(dp[i + 1][j + 1], max(dp[i][j] - b[idx[i]], (long long)a[idx[i]]));
    dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
  }
  for (int j = n; j >= 0; --j) {
    if (dp[n][j] <= r) {
      ans += j;
      break;
    }
  }
  cout << ans << '\n';
  return 0;
}