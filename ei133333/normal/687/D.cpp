#include<bits/stdc++.h>
using namespace std;
struct UnionFind
{
  vector< int > data;
  UnionFind(int sz): data(sz, -1) {}
  int find(int k)
  {
    return(data[k] < 0 ? k : (data[k] = find(data[k])));
  }
  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(data[x] < data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
  }
};

int main()
{
  int N, M, Q, U[1000 * 999 / 2], V[1000 * 999 / 2], W[1000 * 999 / 2];
  
  scanf("%d %d %d", &N, &M, &Q);
  vector< int > idx(M);
  for(int i = 0; i < M; i++) {
    scanf("%d %d %d", U + i, V + i, W + i);
    idx[i] = i;
    --U[i];
    --V[i];
  }
  sort(begin(idx), end(idx), [&](const int& a, const int& b) {
    return(W[a] > W[b]);
  });
  while(Q--) {
    int L, R;
    scanf("%d %d", &L, &R);
    --L;
    --R;
    
    UnionFind tree(N + N);
    int ret = -1;
    for(int i : idx) {
      if(L <= i && i <= R) {
        int x = U[i], y = V[i];
        if(tree.find(x) == tree.find(N + y)) continue;
        tree.unite(x, N + y);
        tree.unite(y, N + x);
        if(tree.find(x) == tree.find(y)) {
          ret = W[i];
          break;
        }
      }
    }
    printf("%d\n", ret);
  }
}