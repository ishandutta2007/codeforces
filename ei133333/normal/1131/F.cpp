#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

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


int main() {
  int N;
  vector< int > g[150000];

  cin >> N;

  UnionFind uf(N);
  for(int i = 0; i < N; i++) g[i].emplace_back(i);

  for(int i = 1; i < N; i++) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    x = uf.find(x);
    y = uf.find(y);
    uf.unite(x, y);
    int p = uf.find(x);
    for(auto t : g[p ^ x ^ y]) g[p].emplace_back(t);
    g[p ^ x ^ y].clear();
  }
  for(auto k : g[uf.find(0)]) cout << k+1 << " ";
  cout << endl;
}