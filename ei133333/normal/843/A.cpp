#include<bits/stdc++.h>

using namespace std;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  bool unite(int x, int y)
  {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
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
  int N;
  cin >> N;
  vector< int > A(N), vs(N);
  for(int i = 0; i < N; i++) {
    cin >> A[i];
    vs[i] = A[i];
  }
  sort(begin(vs), end(vs));
  vs.erase(unique(begin(vs), end(vs)), end(vs));
  for(int i = 0; i < N; i++) {
    A[i] = lower_bound(begin(vs), end(vs), A[i]) - begin(vs);
  }

  UnionFind tree(N);
  for(int i = 0; i < N; i++) {
    tree.unite(A[i], i);
  }
  vector< int > beet[100000];
  int ret = 0;
  for(int i = 0; i < N; i++) {
    beet[tree.find(i)].push_back(i);
    ret += tree.find(i) == i;
  }
  cout << ret << endl;
  for(int i = 0; i < N; i++) {
    if(beet[i].size()) {
      cout << beet[i].size();
      for(int j : beet[i]) cout << " " << j + 1;
      cout << endl;
    }
  }
}