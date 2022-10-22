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

struct Lowlink {
  vector<vector<Edge> > graph;
  vector<int> ap;
  vector<Edge> bridge;

  Lowlink(const vector<vector<Edge> > &graph) : graph(graph) {
    int n = graph.size();
    order.assign(n, -1);
    lowlink.resize(n);
    int tm = 0;
    REP(i, n) {
      if (order[i] == -1) dfs(-1, i, tm);
    }
    // sort(ALL(ap));
    // sort(ALL(bridge), [](const Edge &lhs, const Edge &rhs) {
    //   return lhs.src != rhs.src ? lhs.src < rhs.src : lhs.dst != rhs.dst ? lhs.dst < rhs.dst : lhs.cost < rhs.cost;
    // });
  }

  vector<int> order, lowlink;
private:
  void dfs(int par, int ver, int &tm) {
    order[ver] = lowlink[ver] = tm++;
    int cnt = 0;
    bool is_ap = false;
    for (const Edge &e : graph[ver]) {
      if (order[e.dst] == -1) {
        ++cnt;
        dfs(ver, e.dst, tm);
        lowlink[ver] = min(lowlink[ver], lowlink[e.dst]);
        if (order[ver] <= lowlink[e.dst]) {
          is_ap = true;
          if (order[ver] < lowlink[e.dst]) bridge.emplace_back(min(ver, e.dst), max(ver, e.dst), e.cost);
        }
      } else if (e.dst != par) {
        lowlink[ver] = min(lowlink[ver], order[e.dst]);
      }
    }
    if (par == -1) {
      if (cnt >= 2) ap.emplace_back(ver);
    } else {
      if (is_ap) ap.emplace_back(ver);
    }
  }
};

struct TwoEdgeConnectedComponents : Lowlink {
  vector<int> id;
  vector<vector<int> > vertices;
  vector<vector<Edge> > comp;

  TwoEdgeConnectedComponents(const vector<vector<Edge> > &graph) : Lowlink(graph) {
    int n = graph.size();
    id.assign(n, -1);
    int now = 0;
    REP(i, n) {
      if (id[i] == -1) dfs(-1, i, now);
    }
    comp.resize(now);
    for (const Edge &e : this->bridge) {
      int u = id[e.src], v = id[e.dst];
      comp[u].emplace_back(u, v, e.cost);
      comp[v].emplace_back(v, u, e.cost);
    }
    // REP(i, now) sort(ALL(vertices[i]));
  }

private:
  void dfs(int par, int ver, int &now) {
    if (par != -1 && this->order[par] >= this->lowlink[ver]) {
      id[ver] = id[par];
    } else {
      id[ver] = now++;
      vertices.emplace_back();
    }
    vertices[id[ver]].emplace_back(ver);
    for (const Edge &e : this->graph[ver]) {
      if (id[e.dst] == -1) dfs(ver, e.dst, now);
    }
  }
};

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<long long> w(n); REP(i, n) cin >> w[i];
  vector<vector<Edge> > graph(n);
  while (m--) {
    int u, v; cin >> u >> v; --u; --v;
    graph[u].emplace_back(u, v);
    graph[v].emplace_back(v, u);
  }
  TwoEdgeConnectedComponents twcc(graph);
  int sz = twcc.comp.size();
  vector<long long> val(sz, 0);
  REP(i, n) val[twcc.id[i]] += w[i];
  int s; cin >> s; --s;
  s = twcc.id[s];
  vector<long long> subtree(sz, 0), ippon(sz, 0);
  function<bool(int, int)> dfs = [&](int par, int ver) {
    bool res = false;
    for (const Edge &e : twcc.comp[ver]) if (e.dst != par) {
      if (dfs(ver, e.dst)) {
        res = true;
        subtree[ver] += subtree[e.dst];
      } else {
        ippon[ver] = max(ippon[ver], ippon[e.dst]);
      }
    }
    res |= twcc.vertices[ver].size() > 1;
    if (res) {
      ippon[ver] = 0;
      subtree[ver] += val[ver];
    } else {
      ippon[ver] += val[ver];
    }
    return res;
  };
  dfs(-1, s);
  cout << subtree[s] + *max_element(ALL(ippon)) << '\n';
  return 0;
}