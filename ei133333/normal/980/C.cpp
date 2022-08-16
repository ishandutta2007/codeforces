#include <bits/stdc++.h>

using namespace std;

using int64 = long long;
const int mod = 1e9 + 7;

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
    if(x == y) return(false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return(true);
  }

  int find(int k)
  {
    if(data[k] < 0) return(k);
    return(data[k] = find(data[k]));
  }

  int size(int k)
  {
    return(-data[find(k)]);
  }
};

int main() {
  int N, K, P[100000];

  cin >> N >> K;
  for(int i = 0; i < N; i++) {
    cin >> P[i];
  }

  UnionFind uf(256);
  for(int i = 0; i < N; i++) {
    for(int j = 1; ; j++) {
      int real = P[i] - j;
      if(real < 0) break;
      if(uf.find(P[i]) != uf.find(real) && uf.size(real) + uf.size(P[i]) > K) {
        break;
      }
      uf.unite(P[i], real);
    }
  }
  int sm[256];
  fill_n(sm, 256, 256);
  for(int i = 0; i < 256; i++) {
    sm[uf.find(i)] = min(sm[uf.find(i)], i);
  }
  for(int i = 0; i < N; i++) {
    cout << sm[uf.find(P[i])] << " ";
  }
  cout << endl;

}