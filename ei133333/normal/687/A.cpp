#include<bits/stdc++.h>
using namespace std;
struct UnionFind
{
  vector< int > data;
  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }
  int find(int k)
  {
    return(data[k] < 0 ? k : data[k] = find(data[k]));
  }
  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
  }
};

int main()
{
  int N, M;
  cin >> N >> M;
  UnionFind tree(N + N);
  while(M--) {
    int A, B;
    cin >> A >> B;
    --A, --B;
    tree.unite(A, N + B);
    tree.unite(B, N + A);
    if(tree.find(A) == tree.find(B)) {
      cout << -1 << endl;
      return(0);
    }
  }

  vector< int > used(N + N, 0);
  for(int i = 0; i < N; i++) {
    if(used[tree.find(i)]) continue;
    used[tree.find(i)] = 1;
    used[tree.find(N + i)] = -1;
  }

  vector< int > a, b;
  for(int i = 0; i < N; i++) {
    if(used[tree.find(i)] == 1) a.push_back(i);
    else                        b.push_back(i);
  }
  cout << a.size() << endl;
  for(int k : a) cout << k + 1 << " ";
  cout << endl;
  cout << b.size() << endl;
  for(int k : b) cout << k + 1 << " ";
}