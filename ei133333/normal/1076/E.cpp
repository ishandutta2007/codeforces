#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

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

vector< int > g[300000];
vector< pair< int, int > > ev[300000];
BinaryIndexedTreeReversed< int64 > bit(300005);
int64 ans[300000];

void dfs(int idx, int par, int depth) {
  for(auto &p : ev[idx]) bit.add(min(300004, depth + p.first), p.second);
  ans[idx] = bit.sum(depth);
  for(auto &to : g[idx]) {
    if(to == par) continue;
    dfs(to, idx, depth + 1);
  }
  for(auto &p : ev[idx]) bit.add(min(300004, depth + p.first), -p.second);
}


int main() {
  int N, Q;
  scanf("%d", &N);
  for(int i = 1; i < N; i++) {
    int A, B;
    scanf("%d %d", &A, &B);
    --A, --B;
    g[A].emplace_back(B);
    g[B].emplace_back(A);
  }
  scanf("%d", &Q);
  for(int i = 0; i < Q; i++) {
    int v, d, x;
    scanf("%d %d %d", &v, &d, &x);
    --v;
    ev[v].emplace_back(d, x);
  }
  dfs(0, -1, 0);
  for(int i = 0; i < N; i++) {
    printf("%lld ", ans[i]);
  }
  puts("");
}