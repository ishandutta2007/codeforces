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
long long calc(long long n) {
  return n * (n - 1) / 2;
}

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
  cin.tie(0); ios::sync_with_stdio(false);
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<Edge> edges;
  REP(_, n - 1) {
    int u, v, w; cin >> u >> v >> w; --u; --v;
    edges.emplace_back(u, v, w);
  }
  sort(ALL(edges));
  vector<pair<int, int> > q(m);
  REP(i, m) {
    cin >> q[i].first;
    q[i].second = i;
  }
  sort(ALL(q));
  vector<long long> ans(m);
  long long now = 0;
  int pos = 0;
  UnionFind uf(n);
  REP(i, m) {
    int lim = q[i].first;
    // cout << lim << '\n';
    while (pos < n - 1 && edges[pos].cost <= lim) {
      int s = edges[pos].src, d = edges[pos].dst;
      if (!uf.same(s, d)) {
        now -= calc(uf.size(s));
        now -= calc(uf.size(d));
        uf.unite(s, d);
        now += calc(uf.size(s));
      }
      ++pos;
    }
    // cout << pos << '\n';
    ans[q[i].second] = now;
  }
  REP(i, m) cout << ans[i] << (i + 1 == m ? '\n' : ' ');
  return 0;
}