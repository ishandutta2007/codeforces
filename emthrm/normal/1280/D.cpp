#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int dy[] = {1, 0, -1, 0}, dx[] = {0, -1, 0, 1};
// const int dy[] = {1, 1, 0, -1, -1, -1, 0, 1},
//           dx[] = {0, -1, -1, -1, 0, 1, 1, 1};

struct IOSetup {
  IOSetup() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cerr << fixed << setprecision(10);
  }
} iosetup;
/*-------------------------------------------------*/
long long diff[3000];
vector<int> graph[3000];
pair<int, long long> dp[3000][3000], tmp[3000];
int cnt[3000];

void rec(int par, int ver) {
  dp[ver][0] = {0, diff[ver]};
  for (int e : graph[ver]) if (e != par) {
    rec(ver, e);
    REP(j, cnt[ver] + cnt[e]) tmp[j] = {0, -LINF};
    REP(i, cnt[ver]) REP(j, cnt[e]) {
      if (dp[ver][i].second == -LINF || dp[e][j].second == -LINF) continue;
      auto pr = dp[ver][i];
      pr.first += dp[e][j].first;
      pr.second += dp[e][j].second;
      tmp[i + j] = max(tmp[i + j], pr);
      pr.first += dp[e][j].second > 0;
      pr.second = dp[ver][i].second;
      tmp[i + j + 1] = max(tmp[i + j + 1], pr);
    }
    cnt[ver] += cnt[e];
    REP(j, cnt[ver]) dp[ver][j] = tmp[j];
  }
}

void solve() {
  int n, m; cin >> n >> m;
  fill(diff, diff + n, 0);
  REP(i, n) {
    int b; cin >> b;
    diff[i] -= b;
  }
  REP(i, n) {
    int w; cin >> w;
    diff[i] += w;
  }
  REP(i, n) graph[i].clear();
  REP(_, n - 1) {
    int x, y; cin >> x >> y; --x; --y;
    graph[x].emplace_back(y);
    graph[y].emplace_back(x);
  }
  REP(i, n) REP(j, n) dp[i][j] = {0, -LINF};
  fill(cnt, cnt + n, 1);
  rec(-1, 0);
  cout << dp[0][m - 1].first + (dp[0][m - 1].second > 0) << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}