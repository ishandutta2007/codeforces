#include<bits/stdc++.h>

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

struct Bipartite_Graph : UnionFind {
  vector< int > color;

  Bipartite_Graph(int v) : color(v + v, -1), UnionFind(v + v) {}

  bool bipartite_graph_coloring() {
    for(int i = 0; i < color.size() / 2; i++) {
      int a = find(i);
      int b = find(i + (int) color.size() / 2);
      if(a == b) return (false);
      if(color[a] < 0) color[a] = 0, color[b] = 1;
    }
    return (true);
  }

  bool operator[](int k) {
    return (bool(color[find(k)]));
  }
};


const int mod = 998244353;

int64 mod_pow(int64 x, int64 n) {

  int64 ret = 1;
  while(n > 0) {
    if(n & 1) (ret *= x) %= mod;
    (x *= x) %= mod;
    n >>= 1;
  }
  return ret;
}

int main() {
  int T;
  int N, M, X[300000], Y[300000];

  scanf("%d", &T);
  while(T--) {
    scanf("%d %d", &N, &M);
    Bipartite_Graph g(N);
    UnionFind h(N);
    for(int i = 0; i < M; i++) {
      scanf("%d %d", &X[i], &Y[i]);
      --X[i], --Y[i];
      g.unite(X[i], Y[i] + N);
      g.unite(Y[i], X[i] + N);
      h.unite(X[i], Y[i]);
    }
    if(g.bipartite_graph_coloring()) {

      vector< int > latte(N);
      vector< int > rots;
      for(int i = 0; i < N; i++) {
        if(h.find(i) == i) rots.emplace_back(i);
      }
      for(int i = 0; i < N; i++) {
        latte[h.find(i)] += g[i];
      }

      int64 ret = 1;
      for(auto &p : rots) {
        int64 add = 0;
        if(h.size(p) == 1) {
          add = 3;
        } else {
          add += mod_pow(2, latte[p]);
          latte[p] = h.size(p) - latte[p];
          add += mod_pow(2, latte[p]);
          add %= mod;
        }
        (ret *= add) %= mod;
      }

      cout << ret << endl;

    } else {
      cout << 0 << endl;
    }
  }
}