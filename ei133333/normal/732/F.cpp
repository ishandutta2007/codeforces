#include <bits/stdc++.h>

using namespace std;

struct UnionFind
{
  vector< int > data;

  UnionFind(size_t sz)
  {
    data.assign(sz, -1);
  }

  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if(x != y) {
      if(data[x] > data[y]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
    }
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }
};


struct BiconnectedComponents
{
  UnionFind uf;
  vector< vector< int > > g, tree;
  vector< pair< int, int > > edges, bridge;
  vector< int > used, ord, low, comp;

  BiconnectedComponents(size_t v) : uf(v), g(v), used(v, 0), comp(v), ord(v), low(v)
  {
  }

  void add_edge(int x, int y)
  {
    g[x].push_back(y);
    g[y].push_back(x);
    edges.push_back(minmax(x, y));
  }

  void dfs(int idx, int& k, int par = -1)
  {
    used[idx] = true;
    ord[idx] = k++;
    low[idx] = ord[idx];

    for(auto& to : g[idx]) {
      if(!used[to]) {
        dfs(to, k, idx);
        low[idx] = min(low[idx], low[to]);
        if(ord[idx] >= low[to]) uf.unite(idx, to);
      } else if(to != par) {
        low[idx] = min(low[idx], ord[to]);
      }
    }
  }

  int operator[](int k)
  {
    return (comp[k]);
  }

  size_t size()
  {
    return (g.size());
  }

  void build()
  {
    build(tree);
  }

  void build(vector< vector< int > >& t)
  {
    int kk = 0;
    dfs(0, kk);

    int ptr = 0;
    vector< int > cc(g.size());
    for(int i = 0; i < g.size(); i++) {
      if(i == uf.find(i)) cc[i] = ptr++;
    }

    t.resize(ptr);
    for(int i = 0; i < g.size(); i++) {
      comp[i] = cc[uf.find(i)];
    }
    for(auto& e : edges) {
      int x = comp[e.first], y = comp[e.second];
      if(x == y) continue;
      t[x].push_back(y);
      t[y].push_back(x);
    }
  }

  void orr(int, int&, int par = -1);
};

map< pair< int, int >, int > vv;
vector< pair< int, int > > gg;
int v[400000];

void BiconnectedComponents::orr(int idx, int& k, int par)
{
  v[idx] = k++;
  for(int to : g[idx]) {
    if(to == par) continue;
    if((*this)[idx] == (*this)[to]) {
      if(~v[to]) {
        if(v[to] < v[idx]) gg.emplace_back(idx, to);
      } else {
        gg.emplace_back(idx, to);
        orr(to, k, idx);
      }
    } else {
      if(v[to] == -1) {
        gg.emplace_back(to, idx);
        orr(to, k, idx);
      }
    }
  }
}

int main()
{
  int N, M, Q;
  scanf("%d %d", &N, &M);
  BiconnectedComponents bc(N);
  for(int i = 0; i < M; i++) {
    int X, Y;
    scanf("%d %d", &X, &Y);
    bc.add_edge(--X, --Y);
    vv[minmax(X, Y)] = i;
  }

  vector< vector< int > > tree;
  bc.build(tree);
  vector< int > sz(tree.size(), 0), idx(tree.size());
  for(int i = 0; i < N; i++) sz[bc[i]]++;
  int p = *max_element(begin(sz), end(sz));
  memset(v, -1, sizeof(v));
  int k = 0;
  for(int i = 0; i < N; i++) {
    if(sz[bc[i]] == p) {
      bc.orr(i, k);
      break;
    }
  }
  printf("%d\n", p);
  vector< pair< int, int > > ans(M);
  for(auto& e : gg) ans[vv[minmax(e.first, e.second)]] = e;
  for(int i = 0; i < M; i++) {
    printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
  }
}