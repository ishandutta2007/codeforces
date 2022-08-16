#include<bits/stdc++.h>

using namespace std;

int n, m;
int r[100000];
vector< int > cont[100000];

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
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

struct Bipartite_Graph : UnionFind
{
  vector< int > color;

  Bipartite_Graph(int v) : color(v + v, -1), UnionFind(v + v) {}

  bool bipartite_graph_coloring()
  {
    for(int i = 0; i < color.size() / 2; i++) {
      int a = find(i);
      int b = find(i + color.size() / 2);
      if(a == b) return (false);
      if(color[a] < 0) color[a] = 0, color[b] = 1;
    }
    return (true);
  }

  bool operator[](int k)
  {
    return (bool(color[find(k)]));
  }
};


int main()
{
  int N, A[100000], B[100000];
  cin >> N;

  int sz = N * 2;
  Bipartite_Graph uf(sz);
  for(int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    --A[i], --B[i];
    uf.unite(A[i], B[i] + sz);
    uf.unite(A[i] + sz, B[i]);
    uf.unite(i * 2, i * 2 + 1 + sz);
    uf.unite(i * 2 + sz, i * 2 + 1);
  }
  uf.bipartite_graph_coloring();
  for(int i = 0; i < N; i++) {
    cout << uf[A[i]] + 1 << " " << uf[B[i]] + 1 << endl;
  }
}