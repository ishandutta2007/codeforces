#include<bits/stdc++.h>

using namespace std;

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
  int N, X[1000000], Y[1000000];

  scanf("%d", &N);
  vector< int > xs(N + N);
  for(int i = 0; i < N; i++) {
    scanf("%d %d", &X[i], &Y[i]);
    xs[i] = X[i];
    xs[i + N] = Y[i];
  }
  sort(begin(xs), end(xs));
  xs.erase(unique(begin(xs), end(xs)), end(xs));
  for(int i = 0; i < N; i++) {
    X[i] = lower_bound(begin(xs), end(xs), X[i]) - begin(xs);
    Y[i] = lower_bound(begin(xs), end(xs), Y[i]) - begin(xs);
  }
  int ok = (int) xs.size(), ng = -1;
  auto check = [&](int left) {
    UnionFind uf(left + 1);
    for(int i = 0; i < N; i++) {
      if(left < X[i]) return false;
      if(Y[i] <= left) uf.unite(X[i], Y[i]);
    }
    vector< int > sum(left + 1);
    for(int i = 0; i < N; i++) {
      sum[uf.find(X[i])]++;
    }
    for(int i = 0; i <= left; i++) {
      if(uf.find(i) == i) if(sum[i] > uf.size(i)) return false;
    }
    return true;
  };

  while(ok - ng > 1) {
    int mid = (ok + ng) / 2;
    if(check(mid)) ok = mid;
    else ng = mid;
  }
  if(ok == xs.size()) puts("-1");
  else printf("%d\n", xs[ok]);
}