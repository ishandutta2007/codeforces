#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

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

struct UnionFind2 {
  map< int, int > data;

  UnionFind2() {}

  void init() {
    data.clear();
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(!data.count(k)) return k;
    return data[k] = find(data[k]);
  }
};


int main() {
  int N, M, Q;
  int A[500000], B[500000], C[500000];
  scanf("%d %d", &N, &M);
  vector< int > es[500001];
  for(int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &C[i]);
    --A[i], --B[i];
    es[C[i]].emplace_back(i);
  }
  UnionFind uf(N);
  int latte[500000], malta[500000];
  memset(latte, -1, sizeof(latte));

  for(int i = 0; i <= 500000; i++) {
    vector< int > uq;
    for(auto &p : es[i]) {
      if(uf.find(A[p]) != uf.find(B[p])) {
        uq.emplace_back(uf.find(A[p]));
        uq.emplace_back(uf.find(B[p]));
        latte[p] = uf.find(A[p]);
        malta[p] = uf.find(B[p]);
      }
    }
    for(int j = 1; j < uq.size(); j += 2) {
      // 
      uf.unite(uq[j - 1], uq[j]);
    }
  }
  scanf("%d", &Q);
  UnionFind2 uf2;
  for(int i = 0; i < Q; i++) {
    int k;
    scanf("%d", &k);
    map< int, vector< pair< int, int > > > appear;
    bool flag = true;
    for(int j = 0; j < k; j++) {
      int x;
      scanf("%d", &x);
      --x;
      if(latte[x] == -1) {
        flag = false;
      } else {
        appear[C[x]].emplace_back(latte[x], malta[x]);
      }
    }
    if(!flag) {
      puts("NO");
      continue;
    }
    bool f = true;
    for(auto &v : appear) {
      uf2.init();
      for(auto &p : v.second) f &= uf2.unite(p.first, p.second);
    }
    if(f) puts("YES");
    else puts("NO");
  }

}