#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

template< class T >
struct BinaryIndexedTree {
  vector< T > data;

  BinaryIndexedTree(int sz) {
    data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};

const int64 INF = 1LL << 60;

int main() {
  int N, M;
  vector< int > g[300000];
  int64 X[300000], Y[300000];
  scanf("%d %d", &N, &M);
  for(int i = 0; i < N; i++) {
    scanf("%lld %lld", &X[i], &Y[i]);
  }
  for(int i = 0; i < M; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }
  int64 ans[300000] = {};
  map< int64, vector< int > > que;
  int64 all = 0;
  for(int i = 0; i < N; i++) {
    ans[i] += 1LL * X[i] * N;
    all += X[i];
    g[i].push_back(i);
    for(auto &p : g[i]) ans[i] -= min(X[i] + Y[p], X[p] + Y[i]);
    que[Y[i] - X[i]].emplace_back(i);
  }
  int64 propagate = -INF;
  //vs.first
  vector< pair< int64, int64 > > s;
  for(int i = 0; i < N; i++) {
    s.emplace_back(Y[i] - X[i], 0);
  }
  s.emplace_back(INF, 0);
  sort(begin(s), end(s));
  int64 sum = 0;
  for(int i = 0; i <= N; i++) {
    s[i].second = sum;
    sum += s[i].first;
  }

  for(auto &vs : que) {
    int64 curr = 0;
    auto it = upper_bound(begin(s), end(s), make_pair(vs.first,INF)) - begin(s);//vs.first
    curr += 1LL * (N - it) * vs.first;
    curr += s[it].second;
    curr += all;
    for(auto &p : vs.second) ans[p] += curr;
  }
  for(int i = 0; i < N; i++) printf("%lld ", ans[i]);
  puts("");
}