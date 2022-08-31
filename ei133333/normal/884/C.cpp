#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

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
  UnionFind tree(N);
  for(int i = 0; i < N; i++) {
    int p;
    cin >> p;
    tree.unite(i, --p);
  }
  vector< int > vs;
  for(int i = 0; i < N; i++) {
    if(tree.find(i) == i) vs.push_back(tree.size(i));
  }
  sort(begin(vs), end(vs));
  if(vs.size() >= 2) {
    int back = vs.back();
    vs.pop_back();
    vs.back() += back;
  }

  int64 ret = 0;
  for(auto& p : vs) {
    ret += 1LL * p * p;
  }
  cout << ret << endl;
}