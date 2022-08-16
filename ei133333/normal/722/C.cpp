#include<bits/stdc++.h>

using namespace std;

#define int long long

typedef long long int64;

int64 sum[100000];

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  void unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x != y) {
      if(data[x] > data[y]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
      sum[x] += sum[y];
    }
  }

  int find(int k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k)
  {
    return (-data[find(k)]);
  }
};

signed main()
{
  int N, A[100000], B[100000], C[100000];

  scanf("%lld", &N);

  for(int i = 0; i < N; ++i) {
    scanf("%lld", &A[i]);
  }

  for(int i = 0; i < N; i++) {
    int K;
    cin >> K;
    --K;
    B[i] = K;
    C[K] = i;
  }

  UnionFind tree(N);
  multiset< int64 > sets;
  sets.insert(0);
  int64 ans[100000];
  for(int i = N - 1; i >= 0; i--) {
    ans[i] = *--sets.end();
    if(B[i] > 0 && C[B[i] - 1] > i) {
      sets.erase(sets.find(sum[tree.find(B[i] - 1)]));
      tree.unite(B[i] - 1, B[i]);
    }
    if(B[i] + 1 < N && C[B[i] + 1] > i) {
      sets.erase(sets.find(sum[tree.find(B[i] + 1)]));
      tree.unite(B[i] + 1, B[i]);
    }
    sum[tree.find(B[i])] += A[B[i]];
    sets.insert(sum[tree.find(B[i])]);
  }

  for(int i = 0; i < N; i++) {
    printf("%lld\n", ans[i]);
  }
}