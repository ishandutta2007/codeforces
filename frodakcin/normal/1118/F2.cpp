#include <iostream>
#include <cstdio>

#include <vector>
#include <array>

using namespace std;

const int MN = 3e5 + 100;
const int MK = 3e5 + 100;
const int MNL = 20;
const int M = 998244353;

typedef long long ll;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

void fail() {
  printf("0\n");
  exit(0);
}

typedef array<int, 2> i2;
bool operator < (const i2& a, const i2& b) {return a[0] < b[0] || (!(b[0] < a[0])&&a[1] < b[1]);}
typedef vector<int> vi;
#define pb push_back
#define sz size()
#define bk back()

int L[MN<<1];
void pcpL() {
  for(int i = 0, j = -1;i < MN<<1;i++) {
    if(i>>(j+1)) j++;
    L[i] = j;
  }
}

int N, K;
int c[MN];
vi a[MN], g[MK];
int p[MN], d[MN];
int o[MN][2];
i2 Q[MN<<1][MNL];
void dfs(int n, int * c = new int(0)) {
  Q[o[n][0] = (*c)++][0] = {d[n], n};
  for(const int& x : a[n])
    if(x != p[n])
      p[x] = n, d[x] = d[n]+1, dfs(x, c), Q[o[n][1] = (*c)++][0] = {d[n], n};
}
void pcpQ() {
  for(int i = (N<<1)-2;i >= 0;i--)
    for(int j = 0;i+(1<<(j+1)) < (N<<1)-1;j++)
      Q[i][j+1] = min(Q[i][j], Q[i+(1<<j)][j]);
}
int lca(int a, int b) {
  if(a==b) return a;
  a = o[a][0], b = o[b][0];
  if(b < a) swap(a, b);
  int d = L[b-a];
  return min(Q[a][d], Q[b-(1<<d)][d])[1];
}

void up(int n, int k) {
  if(c[n] == k) return;
  if(c[n]&&c[n]!=k) fail();
  c[n] = k;
  up(p[n], k);
}
void fillC() {
  for(int i = 1;i <= K;i++) {
    int a = g[i][0];
    for(const int& x : g[i])
      a = lca(a, x);
    if(c[a]&&c[a] != i) fail();
    c[a] = i;
    for(const int& x : g[i])
      if(x != a)
        up(p[x], i);
  }
}

int f[MN][2];
void dfsd(int n, bool u = 0) {
  if(c[n]) {
    f[n][0] = 1, f[n][1] = 0;
    for(const int& x : a[n]) {
      if(p[n] == x) continue;
      dfsd(x, 1);
      f[n][0] = ti(tl(f[n][0])*(f[x][0]+f[x][1])%M);
    }
    return;
  }
  f[n][0] = 0;
  vi t(1, 1);
  for(const int& x : a[n]) {
    if(p[n] == x) continue;
    dfsd(x, u);
    t.pb(ti(tl(t.bk)*(f[x][0]+f[x][1])%M));
  }
  f[n][1] = t.bk;
  for(int i = a[n].sz-1, j = t.sz-1, x, q = 1;i >= 0;i--) {
    if((x = a[n][i]) == p[n]) continue;
    f[n][0] = ti((f[n][0] + tl(q)*t[--j]%M*f[x][0])%M);
    q = ti(tl(q)*(f[x][0]+f[x][1])%M);
  }
}

int main() {
  pcpL();
  scanf("%d%d", &N, &K);
  for(int i = 1;i <= N;i++) scanf("%d", c + i), g[c[i]].pb(i);
  for(int i = 0, u, v;i < N-1;i++) scanf("%d%d", &u, &v), a[u].pb(v), a[v].pb(u);
  dfs(1);
  pcpQ();
  fillC();
  dfsd(1);
  printf("%d\n", f[1][0]);
  return 0;
}