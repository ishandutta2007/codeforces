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
vector<Edge> graph[1000];

vector<int> u, v;
vector<long long> x;
void add(int ver, int leaf, long long val, int dir) {
  if (graph[ver].size() == 1) {
    u.emplace_back(ver);
    v.emplace_back(leaf);
    x.emplace_back(val);
    return;
  }
  vector<int> ha(2);
  int idx = 0;
  REP(i, 3) if (graph[ver][i].dst != dir) {
    int le = graph[ver][i].dst, par = ver;
    while (graph[le].size() >= 2) {
      for (Edge ee : graph[le]) if (ee.dst != par) {
        par = le;
        le = ee.dst;
        break;
      }
    }
    if (le != leaf) {
      ha[idx] = le;
      ++idx;
      if (idx == 3) break;
    }
  }
  u.emplace_back(leaf); v.emplace_back(ha[0]); x.emplace_back(val / 2);
  u.emplace_back(leaf); v.emplace_back(ha[1]); x.emplace_back(val / 2);
  u.emplace_back(ha[0]); v.emplace_back(ha[1]); x.emplace_back(-val / 2);
}

int main() {
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  vector<Edge> edges;
  REP(i, n - 1) {
    int u, v, val; cin >> u >> v >> val; --u; --v;
    graph[u].emplace_back(Edge(u, v, val));
    graph[v].emplace_back(Edge(v, u, val));
    edges.emplace_back(Edge(u, v, val));
  }
  REP(i, n) {
    if (graph[i].size() == 2) {
      cout << "NO\n";
      return 0;;
    }
  }
  cout << "YES\n";
  REP(i, n - 1) {
    Edge e = edges[i];
    if (graph[e.src].size() == 1) {
      add(e.dst, e.src, e.cost, e.src);
    } else if (graph[e.dst].size() == 1) {
      add(e.src, e.dst, e.cost, e.dst);
    } else {
      int leaf = e.src, par = e.dst, dir = -1;
      while (graph[leaf].size() >= 2) {
        for (Edge ee : graph[leaf]) if (ee.dst != par) {
          par = leaf;
          leaf = ee.dst;
          if (dir == -1) dir = leaf;
          break;
        }
      }
      add(e.dst, leaf, e.cost, e.src);
      add(e.src, leaf, -e.cost, dir);
    }
  }
  int sz = u.size();
  cout << sz << '\n';
  REP(i, sz) cout << u[i] + 1 << ' ' << v[i] + 1 << ' ' << x[i] << '\n';
  return 0;
}