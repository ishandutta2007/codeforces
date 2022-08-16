#include<bits/stdc++.h>

using namespace std;

using int64 = long long;
using vi = vector< int >;
const int INF = 1 << 30;
const int mod = 1e9 + 7;

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
  int N, M, V[100000];

  cin >> N >> M;
  for(int i = 0; i < N; i++) {
    cin >> V[i];
  }
  UnionFind uf(N);
  for(int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    uf.unite(a, b);
  }

  vector< int > S(N, INF);
  for(int i = 0; i < N; i++) {
    S[uf.find(i)] = min(S[uf.find(i)], V[i]);
  }
  int64 ret = 0;
  for(int i = 0; i < N; i++) {
    if(uf.find(i) == i) ret += S[i];
  }
  cout << ret << endl;
}