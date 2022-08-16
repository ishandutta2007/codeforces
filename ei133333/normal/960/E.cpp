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

const int mod = 1e9 + 7;


int N, V[200000];
int latte[200000]; // 
int malta[200000]; // 
int ret;

void rec(int idx, int par, const UnWeightedGraph &g) {
  for(auto &to : g[idx]) {
    if(to == par) continue;
    rec(to, idx, g);
    latte[idx] += malta[to];
    malta[idx] += latte[to];
  }
  ++latte[idx];
}

// X: (0,2,4)
// Y: (1,3,5)
void rec2(int idx, int par, int X, int Y, const UnWeightedGraph &g) {
  // 
  int all = latte[idx] + malta[idx];

  int64 add = 1LL * X * V[idx] % mod;
  (add *= all) %= mod;
  int64 sub = 1LL * Y * V[idx];
  (sub *= all) %= mod;

  (add += 1LL * V[idx] * N % mod) %= mod;

  for(auto &to : g[idx]) {
    if(to == par) continue;
    all = N - (latte[to] + malta[to]);

    int64 add2 = 1LL * malta[to] * V[idx] % mod;
    (add2 *= all) %= mod;
    int64 del2 = 1LL * latte[to] * V[idx] % mod;
    (del2 *= all) %= mod;
    (add += add2) %= mod;
    (sub += del2) %= mod;
  }
  X += latte[idx];
  Y += malta[idx];
  for(auto &to : g[idx]) {
    if(to == par) continue;
    rec2(to, idx, Y - latte[to], X - malta[to], g);
  }

  (ret += add) %= mod;
  (ret += mod - sub) %= mod;
}

int main() {

  scanf("%d", &N);
  for(int i = 0; i < N; i++) {
    scanf("%d", &V[i]);
    V[i] += mod;
    V[i] %= mod;
  }

  UnWeightedGraph g(N);
  for(int i = 1; i < N; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    --u, --v;
    g[u].emplace_back(v);
    g[v].emplace_back(u);
  }

  rec(0, -1, g);
  rec2(0, -1, 0, 0, g);

  printf("%d\n", ret);
}