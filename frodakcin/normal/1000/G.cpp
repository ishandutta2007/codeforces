#include <iostream>
#include <cstdio>

#include <vector>

#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

const int MN = 3e5 + 1000;
const int NL2 = 30;

using vl = vector<ll>;

ll pf[MN];

struct EDG {
public:
  int n;
  ll w;
};

using ve = vector<EDG>;
#define pb push_back

ll a[MN];

ve c[MN];
int s[MN], p[MN][NL2], d[MN];
ll L[MN];

void tdfs(int n = 1) {
  for(int i = 0;;i++) if(p[n][i] != -1 and p[p[n][i]][i] != -1) p[n][i+1] = p[p[n][i]][i]; else break;
  for(const EDG& e : c[n]) {
    if(e.n == p[n][0]) continue;
    p[e.n][0] = n, L[e.n] = a[e.n] - e.w, d[e.n] = d[n] + 1, tdfs(e.n), s[n] += s[e.n];
  }
}

int h[MN], t[MN], u[MN];
int v[MN], CV;

void hdfs(int n = 1) {
  for(const EDG& e : c[n]) {
    if(p[n][0] == e.n) continue;
    if(s[e.n]<<1 >= s[n]) {
      h[n] = e.n;
      if(t[n] == -1) t[n] = n, u[n] = 0;
      t[e.n] = t[n], u[e.n] = u[n] + 1;
    }
    hdfs(e.n);
  }
  if(h[n] == -1 and t[n] != -1) v[t[n]] = CV, CV += u[n];
}

int N, Q;

ll tt[MN];
vl ind[MN];
int fr[MN];
void dpdfs(int n = 1) {
  ind[n].assign(c[n].size(), 0LL);
  tt[n] = 0LL;
  for(int i = 0;i < c[n].size();i++) {
    if(p[n][0] == c[n][i].n) continue;
    fr[c[n][i].n] = i;
    dpdfs(c[n][i].n);
    ll pot = tt[c[n][i].n] + a[c[n][i].n] - 2LL * c[n][i].w;
    if(pot > 0) {
      ind[n][i] = pot;
      tt[n] += pot;
    }
  }
}

ll uv[MN];
void dpdfs2(int n = 1) {
  if(t[n] != -1 and h[n] != -1)
    pf[v[t[n]] + u[n]] = (t[n] != n ? pf[v[t[n]] + u[n] - 1] : 0LL) + (tt[n] - ind[n][fr[h[n]]] + L[n]);
  for(int i = 0;i < c[n].size();i++) {
    if(c[n][i].n == p[n][0]) continue;
    ll pot = tt[n] - ind[n][i];
    pot += uv[n];
    pot += a[n] - 2LL * c[n][i].w;
    uv[c[n][i].n] = pot > 0LL ? pot : 0LL;
    dpdfs2(c[n][i].n);
  }
}

int l2[MN];
int mu(int n, int l) {
  assert(d[n] >= l);
  while(d[n] > l) n = p[n][l2[d[n] - l]];
  return n;
}

int lca(int& a, int& b) {
  bool sw = false;
  if(d[a] < d[b]) swap(a, b), sw = true;
  if(d[a] != d[b]) a = mu(a, d[b]);
  if(a == b) return a;
  for(int i = l2[d[a]];i >= 0;i--) if(p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
  if(sw) swap(a, b);
  return p[a][0];
}

ll raw(int n, int c) {
  return tt[n] - ind[n][fr[c]];
}
ll get(int n, int y, int f) {
  if(n == f) return 0LL;
  if(h[n] == y) {
    if(t[f] == t[n]) return pf[v[t[n]] + u[n]] - pf[v[t[n]] + u[f]];
    else return pf[v[t[n]] + u[n]] + get(p[t[n]][0], t[n], f);
  }
  return raw(n, y) + L[n] + get(p[n][0], n, f);
}
ll bel(int n) {return tt[n];}
ll abo(int n, int c1) {return uv[n] + tt[n] - ind[n][fr[c1]];}
ll abo(int n, int c1, int c2) {return uv[n] + tt[n] - ind[n][fr[c1]] - ind[n][fr[c2]];}

void ansq() {
  int x, y;
  scanf("%d%d", &x, &y);
  if(x == y) {printf("%lld\n", uv[x] + tt[x] + a[x]); return;}
  if(d[x] < d[y]) swap(x, y);
  
  int xb = x, yb = y;
  int f = lca(xb, yb);
  ll F = 0LL;
  
  if(f == y) {
    printf("%lld\n", a[y] + L[x] + abo(y, mu(x, d[y]+1)) + get(p[x][0], x, y) + bel(x));
  } else {
    printf("%lld\n", a[f] + L[x] + L[y] + abo(f, xb, yb) + get(p[x][0], x, f) + get(p[y][0], y, f) + bel(x) + bel(y));
  }
}

int main() {
  for(int i = 0;i < MN;i++) {
    for(int j = 0;j < NL2;j++) p[i][j] = -1;
    h[i] = t[i] = u[i] = -1;
    s[i] = 1, d[i] = -1;
  }
  d[1] = 0;
  uv[1] = 0LL, fr[1] = -1;
  
  l2[0] = -1;
  for(int i = 1, j = 0;i < MN;i++) {
    if(i>>(j+1)) j++;
    l2[i] = j;
  }
  
  for(int i = 0;i < MN;i++) pf[i] = 0LL;
  
  CV = 0;
  
  scanf("%d%d", &N, &Q);
  
  for(int i = 1;i <= N;i++) scanf("%lld", a + i);
  for(int i, n[3];i < N - 1;i++) {
    scanf("%d%d%d", n, n + 1, n + 2);
    c[n[0]].pb({n[1], tl(n[2])});
    c[n[1]].pb({n[0], tl(n[2])});
  }
  
  tdfs();
  hdfs();
  dpdfs();
  dpdfs2();
  
  while(Q--) ansq();
  
  return 0;
}