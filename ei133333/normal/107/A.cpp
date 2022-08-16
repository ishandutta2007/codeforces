#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

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
  int N, P;
  bool in[1000] = {}, out[1000] = {};
  int a[1000], b[1000], c[1000];

  cin >> N >> P;
  UnionFind tree(N);
  for(int i = 0; i < P; i++) {
    cin >> a[i] >> b[i] >> c[i];
    --a[i], --b[i];
    tree.unite(a[i], b[i]);
    out[a[i]] = true;
    in[b[i]] = true;
  }

  int ret[1000];
  int latte[1000], malta[1000];
  fill_n(ret, 1000, INF);
  memset(latte, -1, sizeof(latte));
  memset(malta, -1, sizeof(malta));
  for(int i = 0; i < N; i++) {
    if(in[i] && !out[i]) latte[tree.find(i)] = i;
    if(out[i] && !in[i]) malta[tree.find(i)] = i;
  }
  for(int i = 0; i < P; i++) {
    int k = tree.find(a[i]);
    ret[k] = min(ret[k], c[i]);
  }
  vector< tuple< int, int, int > > vs;
  for(int i = 0; i < N; i++) {
    if(tree.find(i) == i) {
      if(~latte[i] && ~malta[i]) {
        vs.emplace_back(malta[i], latte[i], ret[i]);
      }
    }
  }

  cout << vs.size() << endl;
  sort(begin(vs), end(vs));
  for(auto &p : vs) {
    int x, y, z;
    tie(x, y, z) = p;
    cout << x + 1 << " " << y + 1 << " " << z << endl;
  }

}