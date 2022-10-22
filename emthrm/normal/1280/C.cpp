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
using CostType = long long;
struct Edge {
  int src, dst; CostType cost;
  Edge(int src, int dst, CostType cost = 0) : src(src), dst(dst), cost(cost) {}
  inline bool operator<(const Edge &rhs) const {
    return cost != rhs.cost ? cost < rhs.cost : dst != rhs.dst ? dst < rhs.dst : src < rhs.src;
  }
  inline bool operator<=(const Edge &rhs) const { return !(rhs < *this); }
  inline bool operator>(const Edge &rhs) const { return rhs < *this; }
  inline bool operator>=(const Edge &rhs) const { return !(*this < rhs); }
};

void solve() {
  int k; cin >> k;
  k <<= 1;
  vector<vector<Edge> > graph(k);
  REP(_, k - 1) {
    int a, b, t; cin >> a >> b >> t; --a; --b;
    graph[a].emplace_back(a, b, t);
    graph[b].emplace_back(b, a, t);
  }
  vector<int> subtree(k, 1);
  long long g = 0, b = 0;
  function<void(int, int)> dfs = [&](int par, int ver) {
    for (const Edge &e : graph[ver]) {
      if (e.dst != par) {
        dfs(ver, e.dst);
        subtree[ver] += subtree[e.dst];
        if (subtree[e.dst] & 1) g += e.cost;
        b += e.cost * min(subtree[e.dst], k - subtree[e.dst]);
      }
    }
  };
  dfs(-1, 0);
  cout << g << ' ' << b << '\n';
}

int main() {
  int t; cin >> t;
  while (t--) solve();
  return 0;
}