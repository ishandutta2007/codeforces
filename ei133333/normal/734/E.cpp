#include<bits/stdc++.h>

using namespace std;


struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  void unite(int x, int y)
  {
    x = find(x), y = find(y);
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

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

typedef vector< vector< int > > Graph;

pair< int, int > dfs(const Graph &graph, int idx, int prev)
{
  pair< int, int > ret = make_pair(0, idx);
  for(int i = 0; i < graph[idx].size(); i++) {
    if(graph[idx][i] != prev) {
      pair< int, int > cost = dfs(graph, graph[idx][i], idx);
      cost.first += 1;
      ret = max(ret, cost);
    }
  }
  return (ret);
}

int Diameter(Graph &tree)
{
  pair< int, int > p = dfs(tree, 0, -1);
  pair< int, int > q = dfs(tree, p.second, -1);
  return (q.first);
}

int main()
{
  int N;
  int Color[200000];

  scanf("%d", &N);

  for(int i = 0; i < N; i++) {
    scanf("%d", &Color[i]);
  }

  Graph prevv(N);
  UnionFind tree(N);
  for(int i = 0; i < N - 1; i++) {
    int U, V;
    scanf("%d %d", &U, &V);
    --U, --V;
    if(Color[U] == Color[V]) tree.unite(U, V);
    prevv[U].push_back(V);
    prevv[V].push_back(U);
  }
  map< int, int > par;
  for(int i = 0; i < N; i++) {
    if(i == tree.find(i)) par[i] = par.size() - 1;
  }
  Graph graph(par.size());
  for(int i = 0; i < N; i++) {
    for(auto &e : prevv[i]) {
      if(tree.find(i) != tree.find(e)) {
        graph[par[tree.find(i)]].push_back(par[tree.find(e)]);
      }
    }
  }
  for(int i = 0; i < graph.size(); i++) {
    sort(begin(graph[i]), end(graph[i]));
    graph[i].erase(unique(begin(graph[i]), end(graph[i])), end(graph[i]));

  }
  printf("%d\n", (Diameter(graph) + 1) >> 1);
}