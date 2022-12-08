#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

#include <iostream>
#include <cstdio>

#include <array>
#include <vector>
#include <algorithm>

#include <cassert>

using namespace std;

template<class T> bool rpl(T& a, const T& b) {return b < a ? a = b, true : false;}
template<class T> bool rph(T& a, const T& b) {return a < b ? a = b, true : false;}

const int MN = 1e5 + 100;
const int MNL = 20;
const int MM = 1e5 + 100;
const int MB = 300;
const int INF = 1e6;

using i2 = array<int, 2>;
using vi = vector<int>;
using vi2 = vector<i2>;
#define pb push_back
#define IT iterator
using vit = vi::IT;
using vi2t = vi2::IT;
bool operator < (const i2& a, const i2& b) {return a[0] < b[0] or (not(b[0] < a[0]) and a[1] < b[1]);}

vi c[MN];
int p[MN], d[MN], s[MN], f[MB], t[MN], b[MN];
int N, M;

int o[MN][2];
i2 Q[MN<<1][MNL];
void dfs(int n = 1, int * t = new int(0)) {
  s[n] = 1, Q[o[n][0] = (*t)++][0] = {d[n], n};
  for(const int& x : c[n]) p[x] = n, d[x] = d[n] + 1, dfs(x, t), s[n] += s[x], Q[(*t)++][0] = {d[n], n};
  o[n][1] = *t;
}

int L[MN<<1];

void pcpR() {
  p[1] = -1, d[1] = 0, dfs();
  assert(o[1][1] == (N<<1) - 1);
  for(int i = (N<<1) - 2;i >= 0;i--) for(int j = 0;i + (1<<j+1) < N<<1;j++) Q[i][j+1] = min(Q[i][j], Q[i+(1<<j)][j]);
}
int lca(int a, int b) {
  if(a == b) return a;
  a = o[a][0], b = o[b][0];
  if(b < a) swap(a, b);
  int z = L[b-a];
  return min(Q[a][z], Q[b-(1<<z)][z])[1];
}
bool h[MN], U[MN], z[MN];
int q[MB], l, v[MN][MB + 2], G;
i2 g[MN];
vi w[MN];
vi2 m[MN];
void init() {
  g[0] = {0, -INF};
  for(int i = 1;i <= N;i++) h[i] = true, U[i] = false, m[i].clear(), b[i] = 0;
}
void dfs2(int n) {
  z[n] = U[n];
  for(const int& x : c[n]) dfs2(x), z[n] |= z[x];
}
void csort(vit s, vit e) {
  vi a[2];
  for(int i : {0, 1}) a[i].clear();
  int I = 0;
  vit it;
  for(it = s;it != e;it++) rph(I, L[*it]);
  for(int i = 0, q;i <= I;i++) {
    for(it = s;it != e;it++) a[*it>>i&1].pb(*it);
    it = s;
    for(int j = 0;j < 2;j++) {
      for(int x : a[j]) *it++ = x;
      a[j].clear();
    }
    assert(it == e);
  }
}
void dfs1(int n, int u) {
  if(U[n]) {
    for(const int& x : c[n]) if(z[x]) {
      dfs1(x, x);
      for(int i = 0;i <= l;i++) v[n][i] += v[x][i];
    }
    vi2t it = m[n].begin();
    for(int i = 0, j = 0, J = h[n] and b[n] > t[n];i < l;i++) {
      if(it != m[n].end() and i == it->at(0)) h[n] = (it++)->at(1) == -1;
      j += v[n][i], f[i] += (h[n] and b[n] + j > t[n]) - J;
    }
    b[n] += v[n][l];
    for(i2& x : m[n]) v[n][x[0]] = x[1], v[n][l] += x[1];
  } else {
    int C = -1;
    for(const int& x : c[n]) if(z[x]) assert(C == -1), dfs1(C = x, u); assert(C != -1);
    if(U[C]) for(int i = 0;i <= l;i++) v[u][i] = v[C][i];
    if(h[n]) w[u].pb(t[n]-b[n]);
    if(n == u) {
      G = 1;
      sort(w[n].begin(), w[n].end());
      int j = 0, k = 0, J;
      for(int i : w[n]) {
        if(i == g[G-1][1]) g[G-1][0]++; else g[G] = {g[G-1][0]+1, i}, G++;
        if(k > i) j = G-1;
      }
      J = g[j][0];
      g[G] = {INF, INF};
      for(int i = 0;i < l;i++) {
        k+=v[n][i];
        if(k <= g[j][1]) j--; else if(g[j+1][1] < k) j++;
        f[i] += g[j][0] - J;
      }
    }
    b[n] += v[u][l];
  }
}
void solve() {
  for(int i = 0;i < l;i++) m[abs(q[i])].pb({i, q[i]>0?1:-1});
  for(int i = 0;i < l;i++) for(int j = i;j < l;j++) U[lca(abs(q[i]), abs(q[j]))] = true;
  dfs2(1);
  for(int i = 1;i < l;i++) f[i] = f[0];
  dfs1(1, 1);
  for(int i = 1;i <= N;i++) if(U[i] or i == 1 or (z[i] and U[p[i]])) for(int j = 0;j <= l;j++) v[i][j] = 0;
  for(int i = 1;i <= N;i++) m[i].clear(), w[i].clear(), z[i] = false, U[i] = false;
}
int main() {
  for(int i = 0, j = -1;i < MN<<1;i++) {
    if(i>>(j+1)) j++;
    L[i] = j;
  }
  
  scanf("%d%d", &N, &M);
  for(int i = 2;i <= N;i++) scanf("%d", p + i), c[p[i]].pb(i);
  pcpR();
  for(int i = 1;i <= N;i++) scanf("%d", t + i);
  init();
  for(int i = 0, j;i < M;i+=j) {
    for(j = 0;j < MB and i + j < M;j++) scanf("%d", q + j);
    l = j, solve();
    for(int k = 0;k < j;k++) printf("%d ", f[k]);
    f[0] = f[j-1];
  }
  printf("\n");
  
  return 0;
}