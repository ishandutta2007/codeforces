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

struct DoubleSweep {
  using Pci = pair<CostType, int>;

  int s = -1, t;
  CostType diameter;
  vector<int> path;

  DoubleSweep(const vector<vector<Edge> > &graph) : graph(graph) {
    Pci tmp1 = dfs1(-1, 0);
    s = tmp1.second;
    Pci tmp2 = dfs1(-1, tmp1.second);
    t = tmp2.second;
    diameter = tmp2.first;
  }

  void build_path() {
    if (s != -1) {
      path.emplace_back(s);
      dfs2(-1, s);
    }
  }

private:
  const vector<vector<Edge> > graph;

  Pci dfs1(int par, int ver) {
    Pci res = {0, ver};
    for (const Edge &e : graph[ver]) if (e.dst != par) {
      Pci result = dfs1(ver, e.dst);
      result.first += e.cost;
      if (result.first > res.first) res = result;
    }
    return res;
  }

  bool dfs2(int par, int ver) {
    if (ver == t) return true;
    for (const Edge &e : graph[ver]) if (e.dst != par) {
      path.emplace_back(e.dst);
      if (dfs2(ver, e.dst)) return true;
      path.pop_back();
    }
    return false;
  }
};

int N;

int solve(int root, int len, const vector<vector<Edge> > &graph) {
  vector<int> subtree(N, 1);
  function<void(int, int)> dfs1 = [&](int par, int ver) {
    for (const Edge &e : graph[ver]) if (e.dst != par) {
      dfs1(ver, e.dst);
      subtree[ver] += subtree[e.dst];
    }
  };
  dfs1(-1, root);
  bool ok = true;
  int ans = -1;
  function<void(int, int, int)> dfs2 = [&](int par, int ver, int depth) {
    if (ver == root) {
      if (graph[ver].size() == 3) {
        ans = root;
        vector<pair<int, int> > tmp;
        for (const Edge &e : graph[ver]) {
          if (e.dst != par) tmp.emplace_back(subtree[e.dst], e.dst);
        }
        sort(ALL(tmp));
        dfs2(ver, tmp[0].second, depth - 2);
        dfs2(ver, tmp[1].second, depth - 2);
        dfs2(ver, tmp[2].second, depth - 1);
      } else if (graph[ver].size() == 2) {
        for (const Edge &e : graph[ver]) {
          if (e.dst != par) dfs2(ver, e.dst, depth - 1);
        }
      } else {
        ok = false;
        ans = -1;
      }
    } else if (graph[ver].size() == 2) {
      if (ans != -1) {
        ok = false;
        ans = -1;
      } else {
        ans = ver;
        for (const Edge &e : graph[ver]) {
          if (e.dst != par) dfs2(ver, e.dst, depth - 1);
        }
      }
    } else if (graph[ver].size() == 3) {
      for (const Edge &e : graph[ver]) {
        if (e.dst != par) dfs2(ver, e.dst, depth - 1);
      }
    } else if (graph[ver].size() == 4) {
      if (ans != -1) {
        ok = false;
        ans = -1;
      } else {
        ans = ver;
        vector<pair<int, int> > tmp;
        for (const Edge &e : graph[ver]) {
          if (e.dst != par) tmp.emplace_back(subtree[e.dst], e.dst);
        }
        sort(ALL(tmp));
        dfs2(ver, tmp[0].second, depth - 2);
        dfs2(ver, tmp[1].second, depth - 2);
        dfs2(ver, tmp[2].second, depth - 1);
      }
    } else if (graph[ver].size() == 1) {
      if (depth != 0) {
        ok = false;
        ans = -1;
      }
    } else {
      ok = false;
      ans = -1;
    }
  };
  dfs2(-1, root, len);
  return (ok && ans != -1 ? ans : -1);
}

int main() {
  cin.tie(nullptr); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n; cin >> n;
  N = (1 << n) - 1;
  if (n == 2) {
    int a, b; cin >> a >> b;
    if (a > b) swap(a, b);
    cout << 2 << '\n' << a << ' ' << b << '\n';
    return 0;
  }
  vector<vector<Edge> > graph(N);
  REP(i, (1 << n) - 3) {
    int a, b; cin >> a >> b; --a; --b;
    graph[a].emplace_back(a, b, 1);
    graph[b].emplace_back(b, a, 1);
  }
  vector<vector<int> > deg(5);
  REP(i, N) {
    if (graph[i].size() >= 5) {
      cout << 0 << '\n';
      return 0;
    }
    deg[graph[i].size()].emplace_back(i);
  }
  if (deg[1].size() != (1 << (n - 1)) && deg[1].size() != (1 << (n - 1)) - 1) {
    cout << 0 << '\n';
    return 0;
  }
  DoubleSweep ds(graph);
  int dia = (ds.diameter + 1) / 2;
  if (deg[1].size() == (1 << (n - 1)) - 1) {
    // remove leaf
    if (deg[2].size() != 2 && deg[3].size() != (1 << (n - 1)) - 3) {
      cout << 0 << '\n';
      return 0;
    }
    vector<int> ans;
    int u = deg[2][0], v = deg[2][1];
    if (solve(u, dia, graph) == v) ans.emplace_back(v);
    if (solve(v, dia, graph) == u) ans.emplace_back(u);
    sort(ALL(ans));
    int sz = ans.size();
    cout << sz << '\n';
    REP(i, sz) cout << ans[i] + 1 << (i + 1 == sz ? '\n' : ' ');
    return 0;
  } else if (deg[1].size() == (1 << (n - 1))) {
    if (deg[2].empty()) {
      // remove child of root
      if (deg[3].size() != (1 << (n - 1)) - 2) {
        cout << 0 << '\n';
        return 0;
      }
      ds.build_path();
      vector<int> root;
      int sz = ds.path.size();
      if (sz % 2 == 0) {
        root.emplace_back(ds.path[sz / 2 - 1]);
        root.emplace_back(ds.path[sz / 2]);
      } else {
        root.emplace_back(ds.path[sz / 2]);
      }
      vector<int> ans;
      for (int e : root) {
        if (solve(e, dia, graph) == e) ans.emplace_back(e);
      }
      sort(ALL(ans));
      sz = ans.size();
      cout << sz << '\n';
      REP(i, sz) cout << ans[i] + 1 << (i + 1 == sz ? '\n' : ' ');
      return 0;
    } else if (deg[2].size() == 1) {
      // otherwise
      if (deg[3].size() != (1 << (n - 1)) - 4 && deg[4].size() != 1) {
        cout << 0 << '\n';
        return 0;
      }
      int root = deg[2][0];
      if (solve(root, dia, graph) == deg[4][0]) {
        cout << 1 << '\n' << deg[4][0] + 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
      return 0;
    }
  }
  cout << 0 << '\n';
  return 0;
}