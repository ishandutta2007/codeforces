#include <bits/stdc++.h>

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

int main()
{
  int N;
  int u[100000], v[100000];
  int color[100000];
  vector< int > g[100000];

  cin >> N;
  for(int i = 0; i < N - 1; i++) {
    cin >> u[i] >> v[i];
    --u[i], --v[i];
    g[u[i]].push_back(v[i]);
    g[v[i]].push_back(u[i]);
  }
  for(int i = 0; i < N; i++) {
    cin >> color[i];
  }

  UnionFind tree(N);
  for(int i = 0; i < N - 1; i++) {
    if(color[u[i]] == color[v[i]]) tree.unite(u[i], v[i]);
  }

  int get = 0;
  for(int i = 0; i < N; i++) get += tree.find(i) == i;

  for(int i = 0; i < N; i++) {
    vector< int > sz;
    sz.push_back(tree.find(i));
    for(auto& to : g[i]) sz.push_back(tree.find(to));
    sort(begin(sz), end(sz));
    sz.erase(unique(begin(sz), end(sz)), end(sz));

    if(sz.size() == get) {
      cout << "YES" << endl;
      cout << i + 1 << endl;
      return(0);
    }
  }

  cout << "NO" << endl;
}