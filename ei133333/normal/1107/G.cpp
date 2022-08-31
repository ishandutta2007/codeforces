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
    // if(data[x] > data[y]) swap(x, y);
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
  int64 N, A, D[300000], C[300000];
  cin >> N >> A;
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    cin >> D[i] >> C[i];
    ret = max(ret, A - C[i]);
  }
  int64 S[300001] = {};
  for(int i = 0; i < N; i++) {
    S[i + 1] = C[i];
    S[i + 1] += S[i];
  }
  //[i,j] := -S[j+1]+S[i]+j*A-i*A+A

  vector< pair< int64, int > > gap;


  for(int i = 0; i + 1 < N; i++) {
    gap.emplace_back(1LL * (D[i + 1] - D[i]) * (D[i + 1] - D[i]), i);
  }
  sort(gap.begin(), gap.end());
  UnionFind uf(N);
  vector< int64 > pre(N), suf(N);
  for(int i = 0; i < N; i++) pre[i] = S[i] - 1LL * i * A;
  for(int i = 0; i < N; i++) suf[i] = -S[i + 1] + 1LL * i * A;

  for(auto &p : gap) {
    int u = uf.find(p.second), v = uf.find(p.second + 1);
    uf.unite(u, v);
    ret = max(ret, suf[v] + pre[u] - p.first + A);
    pre[u] = max(pre[u], pre[v]);
    suf[u] = max(suf[u], suf[v]);
  }
  cout << ret << endl;
}