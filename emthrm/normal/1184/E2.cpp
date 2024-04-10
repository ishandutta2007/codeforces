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
  vector<int> data, last;
  vector<vector<pair<int, int> > > history;

  UnionFind(int n) : data(n, -1), last(n, -1), history(n, vector<pair<int, int> >(1, {-1, -1})) {}

  int root(int t, int ver) {
    if (last[ver] == -1 || t < last[ver]) return ver;
    return root(t, data[ver]);
  }

  void unite(int t, int v, int u) {
    v = root(t, v);
    u = root(t, u);
    if (v != u) {
      if (data[v] > data[u]) swap(v, u);
      data[v] += data[u];
      data[u] = v;
      last[u] = t;
      history[v].emplace_back(t, data[v]);
    }
  }

  bool same(int t, int u, int v) {
    return root(t, u) == root(t, v);
  }
};

int main() {
  // freopen("input.txt", "r", stdin);

  int n, m; cin >> n >> m;
  vector<pair<Edge, int> > edges;
  REP(i, m) {
    int a, b, e; cin >> a >> b >> e; --a; --b;
    edges.emplace_back(Edge(a, b, e), i);
  }
  sort(ALL(edges));
  UnionFind uf(n);
  vector<int> idx;
  REP(i, m) {
    Edge e = edges[i].first;
    if (!uf.same(i, e.src, e.dst)) {
      uf.unite(i, e.src, e.dst);
    } else {
      idx.emplace_back(i);
    }
  }
  vector<int> ans(m, -1);
  for (int i : idx) {
    int lb = -1, ub = m - 1;
    while (ub - lb > 1) {
      int mid = (ub + lb) / 2;
      (uf.same(mid, edges[i].first.src, edges[i].first.dst) ? ub : lb) = mid;
    }
    ans[edges[i].second] = edges[ub].first.cost;
  }
  REP(i, m) if (ans[i] != -1) {
    cout << ans[i] << '\n';
  }
  return 0;
}