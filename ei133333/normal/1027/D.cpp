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

const int INF = 1 << 30;

int N, C[200000], A[200000];
int in[200000];
bool v[200000];

int main() {
  cin >> N;
  for(int i = 0; i < N; i++) {
    cin >> C[i];
  }
  UnionFind uf(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    --A[i];
    uf.unite(i, A[i]);
    in[A[i]]++;
  }
  queue< int > que;
  for(int i = 0; i < N; i++) {
    if(in[i] == 0) {
      que.emplace(i);
      v[i] = true;
    }
  }
  while(!que.empty()) {
    int p = que.front();
    que.pop();
    if(--in[A[p]] == 0) {
      que.emplace(A[p]);
      v[A[p]] = true;
    }
  }
  vector< int > sum(N, INF);
  for(int i = 0; i < N; i++) {
    if(in[i] > 0) {
      sum[uf.find(i)] = min(sum[uf.find(i)], C[i]);
    }
  }
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    if(uf.find(i) == i) ret += sum[i];
  }
  cout << ret << endl;
}