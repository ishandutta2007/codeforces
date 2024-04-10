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

  int n; cin >> n;
  vector<vector<int> > c(3, vector<int>(n)); REP(i, 3) REP(j, n) cin >> c[i][j];
  vector<vector<int> > graph(n);
  REP(_, n - 1) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(v);
    graph[v].emplace_back(u);
  }
  int leaf;
  REP(i, n) {
    if (graph[i].size() >= 3) {
      cout << -1 << '\n';
      return 0;
    }
    if (graph[i].size() == 1) leaf = i;
  }
  vector<int> vs{leaf};
  function<void(int, int)> dfs = [&](int par, int ver) {
    for (int e : graph[ver]) {
      if (e != par) {
        vs.emplace_back(e);
        dfs(ver, e);
      }
    }
  };
  dfs(-1, leaf);
  vector<int> per{1, 2, 3};
  long long ans = LINF;
  vector<int> color(n, -1);
  do {
    long long tmp = 0;
    REP(i, n) tmp += c[per[i % 3] - 1][vs[i]];
    if (tmp < ans) {
      ans = tmp;
      REP(i, n) color[vs[i]] = per[i % 3];
    }
  } while (next_permutation(ALL(per)));
  cout << ans << '\n';
  REP(i, n) cout << color[i] << (i + 1 == n ? '\n' : ' ');
  return 0;
}