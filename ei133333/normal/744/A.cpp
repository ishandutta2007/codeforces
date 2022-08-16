#include <bits/stdc++.h>

using namespace std;

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

int main()
{
  int N, M, K, A[1000];
  cin >> N >> M >> K;
  UnionFind tree(N);
  for(int i = 0; i < K; i++) {
    cin >> A[i];
    --A[i];
  }
  for(int i = 0; i < M; i++) {
    int U, V;
    cin >> U >> V;
    tree.unite(--U, --V);
  }

  bool isroot[1000] = {};
  vector< int > szz;
  for(int i = 0; i < K; i++) {
    isroot[tree.find(A[i])] = true;
    szz.push_back(tree.size(A[i]));
  }
  sort(begin(szz), end(szz));
  reverse(begin(szz), end(szz));
  for(int i = 0; i < N; i++) {
    if(!isroot[tree.find(i)]) {
      szz.front()++;
    }
  }

  long long ret = 0;
  for(int k : szz) {
    ret += 1LL * (k - 1) * k / 2;
  }

  cout << ret - M << endl;
}