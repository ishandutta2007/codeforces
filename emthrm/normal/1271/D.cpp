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
int main() {
  int n, m, k; cin >> n >> m >> k;
  vector<int> a(n), b(n), c(n); REP(i, n) cin >> a[i] >> b[i] >> c[i];
  vector<vector<int> > graph(n);
  vector<int> par(n, -1);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    par[v] = max(par[v], u);
  }
  // REP(i, n) cout << par[i] << ' ';
  // cout << '\n';
  vector<int> yoyu(n);
  if (k < a[0]) {
    cout << -1 << '\n';
    return 0;
  }
  int sum = k + b[0];
  FOR(i, 1, n) {
    yoyu[i - 1] = sum - a[i];
    if (yoyu[i - 1] < 0) {
      cout << -1 << '\n';
      return 0;
    }
    sum += b[i];
  }
  yoyu[n - 1] = sum;
  for (int i = n - 2; i >= 0; --i) yoyu[i] = min(yoyu[i], yoyu[i + 1]);
  // REP(i, n) cout << yoyu[i] << ' ';
  // cout << '\n';
  int cnt = 0;
  vector<vector<int> > dp(n + 1, vector<int>(n + 1, -INF));
  dp[0][0] = 0;
  REP(i, n) {
    vector<int> tmp;
    for (int e : graph[i]) {
      if (par[e] == i) tmp.emplace_back(c[e]);
    }
    if (par[i] == -1) tmp.emplace_back(c[i]);
    sort(ALL(tmp), greater<int>());
    FOR(i, 1, tmp.size()) tmp[i] += tmp[i - 1];
    REP(j, cnt + 1) {
      if (dp[i][j] == -INF) break;
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      REP(l, tmp.size()) {
        if (j + l + 1 > yoyu[i]) break;
        dp[i + 1][j + l + 1] = max(dp[i + 1][j + l + 1], dp[i][j] + tmp[l]);
      }
    }
    cnt += tmp.size();
  }
  cout << *max_element(ALL(dp[n])) << '\n';
  return 0;
}