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

struct SCC {
  vector<int> id;
  vector<vector<int> > vertices;
  vector<vector<Edge> > comp;

  SCC(const vector<vector<Edge> > &graph) : graph(graph) {
    n = graph.size();
    rev_graph.resize(n);
    REP(i, n) for (const Edge &e : graph[i]) {
      rev_graph[e.dst].emplace_back(e.dst, e.src, e.cost);
    }
    used.assign(n, false);
    id.assign(n, -1);
    REP(i, n) {
      if (!used[i]) dfs(i);
    }
    int now = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (id[order[i]] == -1) {
        vertices.emplace_back();
        rev_dfs(order[i], now++);
      }
    }
    comp.resize(now);
    REP(i, n) for (const Edge &e : graph[i]) {
      if (id[i] != id[e.dst]) comp[id[i]].emplace_back(id[i], id[e.dst], e.cost);
    }
    // REP(i, now) sort(ALL(vertices[i]));
  }

private:
  int n;
  vector<vector<Edge> > graph, rev_graph;
  vector<bool> used;
  vector<int> order;

  void dfs(int ver) {
    used[ver] = true;
    for (const Edge &e : graph[ver]) {
      if (!used[e.dst]) dfs(e.dst);
    }
    order.emplace_back(ver);
  }

  void rev_dfs(int ver, int now) {
    id[ver] = now;
    vertices[now].emplace_back(ver);
    for (Edge &e : rev_graph[ver]) {
      if (id[e.dst] == -1) rev_dfs(e.dst, now);
    }
  }
};

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m; cin >> n >> m;
    vector<vector<Edge> > graph(n * 2);
    vector<vector<int> > fri(n);
    while (m--) {
      int a, b; cin >> a >> b; --a; --b;
      if (a == b) {
        graph[n + b].emplace_back(n + b, a);
      } else {
        graph[a].emplace_back(a, n + b);
      }
      fri[b].emplace_back(a);
    }
    SCC scc(graph);
    if (n == 1 || scc.comp.size() == 1) {
      cout << "No\n";
      continue;
    }
    vector<int> jury, cat;
    for (const vector<int> &vec : scc.vertices) {
      vector<int> neko;
      for (int e : vec) {
        if (e >= n) neko.emplace_back(e - n);
      }
      if (neko.empty()) continue;
      set<int> shinpan;
      for (int e : neko) {
        for (int el : fri[e]) shinpan.emplace(e);
      }
      if ((int)neko.size() + n - shinpan.size() < n) continue;
      cat = neko;
      for (int i = 0; i < n && jury.size() + cat.size() < n; ++i) {
        if (shinpan.count(i) == 0) jury.emplace_back(i);
      }
      break;
    }
    assert(!jury.empty() && !cat.empty());
    cout << "Yes\n" << jury.size() << ' ' << cat.size() << '\n';
    REP(i, jury.size()) cout << jury[i] + 1 << (i + 1 == jury.size() ? '\n' : ' ');
    REP(i, cat.size()) cout << cat[i] + 1 << (i + 1 == cat.size() ? '\n' : ' ');
  }
  return 0;
}