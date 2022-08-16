#include <bits/stdc++.h>

using namespace std;

using int64 = long long;


template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};


template< typename G >
struct LowLink {
  const G &g;
  UnionFind uf;
  vector< int > used, ord, low, parent;

  LowLink(const G &g) : g(g), uf(g.size()), used(g.size()), ord(g.size()), low(g.size()), parent(g.size(), -1) {}

  void dfs(int idx, int &k, int par = -1) {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];

    for(auto &to : g[idx]) {
      if(!used[to]) {
        dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        parent[to] = idx;
        if(ord[idx] >= low[to]) uf.unite(idx, to);
      } else if(to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
  }

  void dfs() {
    int k = 0;
    dfs(0, k);
  }
};

template< typename G >
struct BiConnectedComponents : LowLink< G > {
  using LL = LowLink< G >;

  vector< int > comp;

  BiConnectedComponents(const G &g) : LL(g), comp(g.size()) {}

  int operator[](int k) {
    return (comp[k]);
  }

  vector< pair< int, int > > build(UnWeightedGraph &t) {
    LL::dfs();
    int ptr = 0;
    vector< int > cc(LL::g.size());
    for(int i = 0; i < LL::g.size(); i++) {
      if(i == LL::uf.find(i)) cc[i] = ptr++;
    }

    t.resize(ptr);
    for(int i = 0; i < LL::g.size(); i++) {
      comp[i] = cc[LL::uf.find(i)];
    }

    vector< pair< int, int > > edges;
    for(int i = 0; i < LL::g.size(); i++) {
      for(auto &to : LL::g[i]) edges.emplace_back(minmax(i, to));
    }
    sort(begin(edges), end(edges));
    edges.erase(unique(begin(edges), end(edges)), end(edges));
    vector< pair< int, int > > vs;
    for(auto &e : edges) {
      int x = comp[e.first], y = comp[e.second];
      if(x == y) continue;
      vs.emplace_back(e.first, e.second);
      t[x].push_back(y);
      t[y].push_back(x);
    }
    sort(begin(vs), end(vs));
    return (vs);
  }
};

pair< int, int > dfs(const UnWeightedGraph &g, int idx, int par) {
  pair< int, int > ret(0, idx);
  for(auto &e : g[idx]) {
    if(e == par) continue;
    auto cost = dfs(g, e, idx);
    cost.first += 1;
    ret = max(ret, cost);
  }
  return ret;
}

int tree_diameter(const UnWeightedGraph &g) {
  auto p = dfs(g, 0, -1);
  auto q = dfs(g, p.second, -1);
  return (q.first);
}


int main() {
  int N, M;
  cin >> N >> M;
  UnWeightedGraph g(N);
  for(int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  auto beet = BiConnectedComponents< UnWeightedGraph >(g);
  UnWeightedGraph t;
  beet.build(t);
  cout << tree_diameter(t) << endl;
}