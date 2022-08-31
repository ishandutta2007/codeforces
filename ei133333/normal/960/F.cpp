#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 29;

template< class T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, -INF);
  }

  T sum(int k) {
    T ret = -INF;
    for(++k; k > 0; k -= k & -k) ret = max(ret, data[k]);
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] = max(data[k], x);
  }
};

int main() {
  int N, M, A[100000], B[100000], W[100000];
  cin >> N >> M;
  vector< int > ev[100000];
  for(int i = 0; i < M; i++) {
    scanf("%d %d %d", &A[i], &B[i], &W[i]);
    --A[i], --B[i];
    ev[B[i]].emplace_back(W[i]);
  }
  vector< BinaryIndexedTree< int > > bits;
  for(int i = 0; i < N; i++) {
    sort(begin(ev[i]), end(ev[i]));
    ev[i].erase(unique(begin(ev[i]), end(ev[i])), end(ev[i]));
    bits.emplace_back(BinaryIndexedTree< int >(ev[i].size()));
  }
  int ret = 0;
  for(int i = 0; i < M; i++) {
    int p = lower_bound(begin(ev[A[i]]), end(ev[A[i]]), W[i]) - begin(ev[A[i]]);
    int curr = max(1, bits[A[i]].sum(p - 1) + 1);
    int q = lower_bound(begin(ev[B[i]]), end(ev[B[i]]), W[i]) - begin(ev[B[i]]);
    ret = max(ret, curr);
    bits[B[i]].add(q, curr);
  }
  cout << ret << endl;
}