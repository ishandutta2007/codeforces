#include <bits/stdc++.h>
using namespace std;

#define FOR(i,m,n) for(int i=(m);i<(n);++i)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()

struct Edge {
  int src, dst;
  long long cost;
  Edge(int a, int b, long long c) : src(a), dst(b), cost(c) {}
  bool operator<(const Edge &rhs) const { return cost < rhs.cost; }
};

struct UnionFind {
  vector<int> data;

  UnionFind(int n) : data(n, -1) {}

  int root(int ver) {
    return data[ver] < 0 ? ver : data[ver] = root(data[ver]);
  }

  void unite(int v, int u) {
    v = root(v);
    u = root(u);
    if (v != u) {
      if (data[v] > data[u]) swap(v, u);
      data[v] += data[u];
      data[u] = v;
    }
  }

  bool same(int u, int v) {
    return root(u) == root(v);
  }

  int size(int ver) {
    return -data[root(ver)];
  }
};

int main() {
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  Edge fst(-1, -1, 0); cin >> fst.src >> fst.dst >> fst.cost;
  --fst.src;
  --fst.dst;
  vector<Edge> edges;
  while (--m) {
    int a, b, e; cin >> a >> b >> e; --a; --b;
    edges.emplace_back(Edge(a, b, e));
  }
  sort(ALL(edges));
  UnionFind uf(n);
  for (Edge e : edges) {
    uf.unite(e.src, e.dst);
    if (uf.same(fst.src, fst.dst)) {
      cout << e.cost << '\n';
      return 0;
    }
  }
  cout << (int)1e9 << '\n';
  return 0;
}