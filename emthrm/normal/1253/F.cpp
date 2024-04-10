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
  inline bool operator<=(const Edge &rhs) const { return cost <= rhs.cost; }
  inline bool operator>(const Edge &rhs) const {
    return cost != rhs.cost ? cost > rhs.cost : dst != rhs.dst ? dst > rhs.dst : src > rhs.src;
  }
  inline bool operator>=(const Edge &rhs) const { return cost >= rhs.cost; }
};

struct PartiallyPersistentUnionFind {
  PartiallyPersistentUnionFind(int n) : data(n, -1), last(n, -1), history(n, vector<pair<int, int> >(1, {-1, -1})) {}

  int root(int t, int ver) {
    if (last[ver] == -1 || t < last[ver]) return ver;
    return root(t, data[ver]);
  }

  void unite(int t, int ver1, int ver2) {
    ver1 = root(t, ver1);
    ver2 = root(t, ver2);
    if (ver1 != ver2) {
      if (data[ver1] > data[ver2]) swap(ver1, ver2);
      data[ver1] += data[ver2];
      data[ver2] = ver1;
      last[ver2] = t;
      history[ver1].emplace_back(t, data[ver1]);
    }
  }

  bool same(int t, int ver1, int ver2) { return root(t, ver1) == root(t, ver2); }

  int size(int t, int ver) {
    ver = root(t, ver);
    return -prev(lower_bound(ALL(history[ver]), make_pair(t, 0)))->second;
  }

private:
  vector<int> data, last;
  vector<vector<pair<int, int> > > history;
};

int main() {
  int n, m, k, q; cin >> n >> m >> k >> q;
  vector<int> u(m), v(m), w(m);
  vector<vector<Edge> > graph(n);
  REP(i, m) {
    cin >> u[i] >> v[i] >> w[i]; --u[i]; --v[i];
    graph[u[i]].emplace_back(u[i], v[i], w[i]);
    graph[v[i]].emplace_back(v[i], u[i], w[i]);
  }
  vector<long long> dist(n, LINF);
  using P = pair<long long, int>;
  priority_queue<P, vector<P>, greater<P> > que;
  REP(i, k) {
    dist[i] = 0;
    que.emplace(dist[i], i);
  }
  while (!que.empty()) {
    P pr = que.top(); que.pop();
    int ver = pr.second;
    if (dist[ver] < pr.first) continue;
    for (const Edge &e : graph[ver]) {
      if (dist[e.dst] > dist[ver] + e.cost) {
        dist[e.dst] = dist[ver] + e.cost;
        que.emplace(dist[e.dst], e.dst);
      }
    }
  }
  vector<Edge> edges;
  REP(i, m) edges.emplace_back(u[i], v[i], dist[u[i]] + dist[v[i]] + w[i]);
  sort(ALL(edges));
  PartiallyPersistentUnionFind uf(n);
  REP(i, m) uf.unite(i, edges[i].src, edges[i].dst);
  while (q--) {
    int a, b; cin >> a >> b; --a; --b;
    int lb = -1, ub = m - 1;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      (uf.same(mid, a, b) ? ub : lb) = mid;
    }
    cout << edges[ub].cost << '\n';
  }
  return 0;
}