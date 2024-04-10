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

struct Lowlink {
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

private:
  vector<vector<Edge> > graph;
  vector<int> order, lowlink;

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

struct UnionFind {
  UnionFind(int n) : data(n, -1) {}

  int root(int ver) { return data[ver] < 0 ? ver : data[ver] = root(data[ver]); }

  void unite(int ver1, int ver2) {
    ver1 = root(ver1);
    ver2 = root(ver2);
    if (ver1 != ver2) {
      if (data[ver1] > data[ver2]) swap(ver1, ver2);
      data[ver1] += data[ver2];
      data[ver2] = ver1;
    }
  }

  bool same(int ver1, int ver2) { return root(ver1) == root(ver2); }

  int size(int ver) { return -data[root(ver)]; }

private:
  vector<int> data;
};

int main() {
  int t; cin >> t;
  while (t--) {
    int n, m, a, b; cin >> n >> m >> a >> b; --a; --b;
    if (a > b) swap(a, b);
    UnionFind uf(n);
    vector<int> a_edge, b_edge;
    while (m--) {
      int u, v; cin >> u >> v; --u; --v;
      if (u > v) swap(u, v);
      if (u == a || v == a) {
        if (v == b) continue;
        a_edge.emplace_back(u == a ? v : u);
      } else if (u == b || v == b) {
        b_edge.emplace_back(u == b ? v : u);
      } else {
        uf.unite(u, v);
      }
    }
    // for (int e : a_edge) cout << e << ' ';
    // cout << '\n';
    // for (int e : b_edge) cout << e << ' ';
    // cout << '\n';
    vector<long long> cnt(n, 0);
    REP(i, n) {
      if (i == a || i == b) continue;
      ++cnt[uf.root(i)];
    }
    long long ans = 0;
    REP(i, n) ans += cnt[i] * (cnt[i] - 1) / 2;
    for (int &e : a_edge) e = uf.root(e);
    sort(ALL(a_edge));
    a_edge.erase(unique(ALL(a_edge)), a_edge.end());
    for (int &e : b_edge) e = uf.root(e);
    sort(ALL(b_edge));
    b_edge.erase(unique(ALL(b_edge)), b_edge.end());
    vector<bool> boolean(n, false);
    vector<int> sz;
    for (int e : a_edge) {
      boolean[e] = true;
      sz.emplace_back(uf.size(e));
    }
    long long sum = accumulate(ALL(sz), 0LL);
    for (int e : sz) {
      sum -= e;
      ans += sum * e;
    }
    sz.clear();
    long long tokubetsu = 0;
    for (int e : b_edge) {
      if (boolean[e]) {
        tokubetsu += uf.size(e);
      } else {
        sz.emplace_back(uf.size(e));
      }
    }
    sz.emplace_back(tokubetsu);
    sum = accumulate(ALL(sz), 0LL);
    for (int e : sz) {
      sum -= e;
      ans += sum * e;
    }
    cout << 1LL * (n - 2) * (n - 3) / 2 - ans << '\n';

    // vector<vector<Edge> > graph(n);
    // while (m--) {
    //   int u, v; cin >> u >> v; --u; --v;
    //   graph[u].emplace_back(u, v);
    //   graph[v].emplace_back(v, u);
    // }
    // Lowlink ll(graph);
    // if (find(ALL(ll.ap), a) == ll.ap.end() || find(ALL(ll.ap), b) == ll.ap.end()) {
    //   cout << 0 << '\n';
    //   continue;
    // }
    // vector<bool> visited(n, false);
    // visited[a] = visited[b] = true;
    // long long x = 0, y = 0;
    // function<bool(int, int&)> dfs = [&](int ver, int &cnt) {
    //   bool res = false;
    //   for (const Edge &e : graph[ver]) {
    //     if (visited[e.dst]) {
    //       res |= e.dst == b;
    //     } else {
    //       ++cnt;
    //       visited[e.dst] = true;
    //       dfs(e.dst, cnt);
    //     }
    //   }
    //   return res;
    // };
    // for (const Edge &e : graph[a]) {
    //   if (!visited[e.dst]) {
    //     int cnt = 1;
    //     visited[e.dst] = true;
    //     (dfs(e.dst, cnt) ? y : x) += cnt;
    //   }
    // }
    // long long z = n - 2 - (x + y);
    // // cout << x << ' ' << y << ' ' << z << '\n';
    // long long ans = 1LL * (n - 2) * (n - 3) / 2;
    // ans -= (x + y) * (x + y - 1) / 2;
    // ans -= (y + z) * (y + z - 1) / 2;
    // ans += y * (y - 1) / 2;
    // cout << ans << '\n';
  }
  return 0;
}