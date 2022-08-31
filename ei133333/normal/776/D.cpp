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
      int c = color[a];
      if(c < 0) color[a] = 0, color[b] = 1;
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
  cin >> n >> m;
  for(int i = 0; i < n; i++) {
    cin >> r[i];
  }
  for(int i = 0; i < m; i++) {
    int k;
    cin >> k;
    for(int j = 0; j < k; j++) {
      int x;
      cin >> x;
      --x;
      cont[x].push_back(i);
    }
  }

  Bipartite_Graph tree(m);
  for(int i = 0; i < n; i++) {
    if(r[i] == 0) {
      tree.unite(cont[i][0], cont[i][1] + m);
      tree.unite(cont[i][0] + m, cont[i][1]);
    } else {
      tree.unite(cont[i][0], cont[i][1]);
      tree.unite(cont[i][0] + m, cont[i][1] + m);
    }
  }
  if(tree.bipartite_graph_coloring()) cout << "YES" << endl;
  else cout << "NO" << endl;
}