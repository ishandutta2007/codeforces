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
#include <iostream>
#include <iomanip>
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
  const int K = 200;
  int n, k; cin >> n >> k;
  vector<int> a(n); REP(i, n) cin >> a[i];
  vector<vector<int> > graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  vector<vector<int> > dp(n, vector<int>(K + 1, 0));
  function<void(int, int)> dfs = [&](int par, int ver) {
    dp[ver][0] = a[ver];
    for (int e : graph[ver]) if (e != par) {
      dfs(ver, e);
      dp[ver][0] += dp[e][k];
    }
    FOR(i, 1, K + 1) {
      for (int e : graph[ver]) if (e != par) {
        int tmp = dp[e][i - 1];
        for (int f : graph[ver]) if (f != par && f != e) {
          tmp += dp[f][max(i - 1, k + 1 - (i + 1))];
        }
        dp[ver][i] = max(dp[ver][i], tmp);
      }
    }
    for (int i = K - 1; i >= 0; --i) dp[ver][i] = max(dp[ver][i], dp[ver][i + 1]);
  };
  dfs(-1, 0);
  cout << dp[0][0] << '\n';
  return 0;
}