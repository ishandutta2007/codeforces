#include <bits/stdc++.h>

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

struct Namori
{
  vector< vector< int > > g;
  vector< int > in;

  Namori(int n) : g(n), in(n, 0) {}

  void add_edge(int x, int y)
  {
    g[x].push_back(y);
    g[y].push_back(x);
    ++in[x];
    ++in[y];
  }

  void decomposition(vector< int > &loop, vector< vector< int > > &forest)
  {
    int N = (int) in.size();
    forest.resize(N);
    queue< int > que;
    vector< bool > v(N, 0);
    for(int i = 0; i < N; i++) {
      if(in[i] == 1) {
        que.emplace(i);
        v[i] = true;
      }
    }
    while(!que.empty()) {
      int idx = que.front();
      que.pop();
      for(auto &to : g[idx]) {
        if(v[to]) continue;
        --in[to];
        forest[to].push_back(idx);
        forest[idx].push_back(to);
        if(in[to] > 1) continue;
        que.emplace(to);
        v[to] = true;
      }
    }

    function< void(int) > dfs = [&](int idx)
    {
      loop.push_back(idx);
      for(auto &to : g[idx]) {
        if(v[to]) continue;
        v[to] = true;
        dfs(to);
      }
    };
    for(int i = 0; i < N; i++) {
      if(v[i]) continue;
      v[i] = true;
      dfs(i);
      break;
    }
  }
};

using int64 = long long;
const int mod = 1e9 + 7;

int main()
{
  int N, X[100000], Y[100000];

  cin >> N;
  UnionFind uf(2 * N);
  for(int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
    --X[i], --Y[i];
    uf.unite(X[i], Y[i]);
  }

  map< int, int > sz;
  vector< int > vs[200000], idx[200000];
  for(int i = 0; i < N; i++) {
    ++sz[uf.find(X[i])];
    vs[uf.find(X[i])].emplace_back(X[i]);
    vs[uf.find(Y[i])].emplace_back(Y[i]);
    idx[uf.find(X[i])].emplace_back(i);
  }
  for(int i = 0; i < 2 * N; i++) {
    sort(begin(vs[i]), end(vs[i]));
    vs[i].erase(unique(begin(vs[i]), end(vs[i])), end(vs[i]));
    for(auto j : idx[i]) {
      X[j] = lower_bound(begin(vs[i]), end(vs[i]), X[j]) - begin(vs[i]);
      Y[j] = lower_bound(begin(vs[i]), end(vs[i]), Y[j]) - begin(vs[i]);
    }
  }

  for(auto &p : sz) {
    if(uf.size(p.first) < p.second) {
      cout << 0 << endl;
      return (0);
    }
  }

  int64 ret = 1;
  for(auto &p : sz) {
    if(uf.size(p.first) != p.second) {
      (ret *= uf.size(p.first)) %= mod;
    } else if(uf.size(p.first) == 1) {
      continue;
    } else {
      Namori namori(uf.size(p.first));
      for(auto& s : idx[p.first]) namori.add_edge(X[s], Y[s]);
      vector< int > loop;
      vector< vector< int > > subtree;
      namori.decomposition(loop, subtree);
      if(loop.size() > 1) (ret *= 2) %= mod;
    }
  }

  cout << ret << endl;
}