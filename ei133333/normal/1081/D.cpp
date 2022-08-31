#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;

struct UnionFind {
  vector< int > data;

  UnionFind(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }
};

WeightedGraph< int > t;
int most[100000];
int suf[100000];
int ans[100000];

int dfs(int idx, int par) {
  most[idx] = suf[idx] == -1 ? -1 : 0;
  for(auto &to : t[idx]) {
    if(to == par) continue;
    int ret = dfs(to, idx);
    if(ret == -1) continue;
    most[idx] = max(most[idx], max(ret, to.cost));
  }
  return most[idx];
}

void dfs2(int idx, int par, int par2) {
  vector< pair< int, int > > dist;
  dist.emplace_back(par2, par);
  if(~suf[idx]) {
    dist.emplace_back(0, idx);
  }
  for(auto &to : t[idx]) {
    if(to == par) continue;
    if(most[to] == -1) dist.emplace_back(most[to], to);
    else dist.emplace_back(max(to.cost, most[to]), to);
  }
  sort(dist.rbegin(), dist.rend());
  if(~suf[idx]) {
    ans[suf[idx]] = dist[0].first;
  }
  for(auto &to : t[idx]) {
    if(to == par) continue;
    int dd = dist[dist[0].second == to].first;
    if(dd == -1) dfs2(to, idx, -1);
    else dfs2(to, idx, max(dd, to.cost));
  }
}


int main() {
  int N, M, K;
  cin >> N >> M >> K;
  memset(suf, -1, sizeof(suf));
  for(int i = 0; i < K; i++) {
    int x;
    cin >> x;
    --x;
    suf[x] = i;
  }
  Edges< int > e;
  for(int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    --a, --b;
    e.emplace_back(a, b, c);
  }
  sort(begin(e), end(e), [&](auto p, auto q) {
    return p.cost < q.cost;
  });
  UnionFind uf(N);
  t.resize(N);
  for(auto &p : e) {
    if(uf.unite(p.src, p.to)) {
      t[p.src].emplace_back(p.to, p.cost);
      t[p.to].emplace_back(p.src, p.cost);
    }
  }
  dfs(0, -1);
  dfs2(0, -1, -1);
  for(int i = 0; i < K; i++) {
    cout << ans[i] << " ";
  }
  cout << endl;
}