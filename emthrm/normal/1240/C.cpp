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
using CostType = long long;
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &rhs) const {
    return cost != rhs.cost ? cost < rhs.cost : dst != rhs.dst ? dst < rhs.dst : src < rhs.src;
  }
  inline bool operator<=(const Edge &rhs) const { return cost <= rhs.cost; }
  inline bool operator>(const Edge &rhs) const {
    return cost != rhs.cost ? cost > rhs.cost : dst != rhs.dst ? dst > rhs.dst : src > rhs.src;
  }
  inline bool operator>=(const Edge &rhs) const { return cost >= rhs.cost; }
};

int k;
vector<Edge> graph[500000];
long long dp[500000][2] = {};
void dfs(int par, int ver) {
  vector<long long> tmp;
  long long sum = 0;
  for (const Edge &e : graph[ver]) if (e.dst != par) {
    dfs(ver, e.dst);
    sum += dp[e.dst][1];
    tmp.emplace_back(dp[e.dst][0] + e.cost - dp[e.dst][1]);
  }
  sort(ALL(tmp), greater<long long>());
  dp[ver][0] = sum;
  REP(i, k - 1) {
    if (i >= tmp.size()) break;
    if (tmp[i] >= 0) dp[ver][0] += tmp[i];
  }
  dp[ver][1] = dp[ver][0];
  if (k - 1 < tmp.size() && tmp[k - 1] >= 0) dp[ver][1] += tmp[k - 1];
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int q; cin >> q;
  while (q--) {
    int n; cin >> n >> k;
    REP(i, n) graph[i].clear();
    REP(i, n) dp[i][0] = dp[i][1] = 0;
    REP(_, n - 1) {
      int u, v, w; cin >> u >> v >> w; --u; --v;
      graph[u].emplace_back(u, v, w);
      graph[v].emplace_back(v, u, w);
    }
    dfs(-1, 0);
    cout << dp[0][1] << '\n';
  }
  return 0;
}