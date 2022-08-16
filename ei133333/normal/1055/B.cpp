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
  int N, M, L;
  int64 A[100000];
  scanf("%d %d %d", &N, &M, &L);
  for(int i = 0; i < N; i++) {
    scanf("%lld", &A[i]);
  }

  int ret = 0;
  for(int i = 0; i < N; i++) {
    if(A[i] > L) ++ret;
    if(i > 0 && A[i - 1] > L && A[i] > L) --ret;
  }

  while(M--) {
    int T;
    scanf("%d", &T);
    if(T == 0) {
      printf("%d\n", ret);
    } else {
      int P, D;
      scanf("%d %d", &P, &D);
      --P;
      if(A[P] <= L) {
        A[P] += D;
        if(A[P] > L) {
          ++ret;
          if(P > 0 && A[P - 1] > L) --ret;
          if(P + 1 < N && A[P + 1] > L) --ret;
        }
      }
    }
  }
}