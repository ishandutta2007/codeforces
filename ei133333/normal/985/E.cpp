#include<bits/stdc++.h>

using namespace std;


// 

template< class T >
struct BinaryIndexedTreeReversed {
  vector< T > data;

  BinaryIndexedTreeReversed(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k < data.size(); k += k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k > 0; k -= k & -k) data[k] += x;
  }
};

int main() {
  int N, K, D, A[500001];
  scanf("%d %d %d", &N, &K, &D);
  vector< int > vs(N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &A[i]);
    vs[i] = A[i];
  }
  sort(A, A + N);
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));

  BinaryIndexedTreeReversed< int > bit(vs.size() + 1);
  queue< int > pending;
  pending.emplace(0);
  for(int i = 1; i <= N; i++) {
    while(pending.size() && i - K >= pending.front()) {
      int idx = pending.front();
      pending.pop();
      bit.add(lower_bound(begin(vs), end(vs), A[idx]) - begin(vs), 1);
    }
    auto pos = lower_bound(begin(vs), end(vs), A[i - 1] - D) - begin(vs);
    if(bit.sum(pos) > 0) {
      pending.emplace(i);
      if(i == N) {
        puts("YES");
        return 0;
      }
    }
  }
  puts("NO");
}