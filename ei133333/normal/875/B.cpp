#include<bits/stdc++.h>

using namespace std;

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

int main()
{
  int N, P[300000];

  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> P[i];
    --P[i];
  }

  cout << 1 << " ";
  UnionFind uf(N);
  bool kill[300000] = {};
  int sz = 0;

  for(int i = 0; i < N; i++) {
    ++sz;
    kill[P[i]] = true;
    if(P[i] > 0 && kill[P[i] - 1]) uf.unite(P[i] - 1, P[i]);
    if(P[i] + 1 < N && kill[P[i] + 1]) uf.unite(P[i] + 1, P[i]);
    int ret = sz;
    if(kill[N - 1]) ret -= uf.size(N - 1);
    cout << ret + 1 << " ";
  }
  cout << endl;
}