#include <iostream>
#include <cstdio>

#include <vector>
#include <stack>
#include <bitset>

using namespace std;

using vi = vector<int>;
using si = stack<int>;

#define pb push_back

template<class T> void rpl(T& a, const T& b) {if(b < a) a = b;}
template<class T> void rph(T& a, const T& b) {if(a < b) a = b;}

const int MN = 1e5 + 100;
const int MNL = 20;
const int MM = 1e4 + 100;

template<int MS = 10000000> struct SCC {
public:
  vi a[MS];
  si p;
  int d[MS], l[MS], c[MS], cc, cd;
  bitset<MS> v, u;
  void adde(int x, int y) {
    a[x].pb(y);
  }
  void dfs(int n) {
    v[n] = u[n] = true;
    d[n] = l[n] = cd++;
    p.push(n);
    for(int& x : a[n]) {
      if(u[x]) rpl(l[n], d[x]);
      if(v[x]) continue;
      dfs(x);
      rpl(l[n], l[x]);
    }
    if(l[n] == d[n]) {
      for(;p.top() != n;) u[p.top()] = false, c[p.top()] = cc, p.pop();
      u[n] = false, c[n] = cc++, p.pop();
    }
  }
  void scc(int fr = 0, int to = MS - 1) {
    for(int i = 0;i < MS;i++) d[i] = l[i] = c[i] = -1;
    v.reset(), u.reset(), cc = 1, cd = 1;
    while(not p.empty()) p.pop();
    for(int i = fr;i <= to;i++) if(not v[i]) dfs(i);
  }
  int operator [] (const int& q) const {return c[q];}
};
SCC<> scc;

int X;

using vvi = vector<vi>;

int build(const vi& q, int p = -1) {
  if(q.empty()) return p;
  int i = 0;
  if(p == -1) i++, p = q[0];
  for(int j;i < q.size();i++, p = j) {
    j = X++;
    scc.adde(p<<1|1, q[i]<<1), scc.adde(q[i]<<1|1, p<<1);
    scc.adde(p<<1|1, j<<1|1), scc.adde(j<<1, p<<1);
    scc.adde(q[i]<<1|1, j<<1|1), scc.adde(j<<1, q[i]<<1);
  }
  return p;
}
int cmb(int a, int b) {
  if(a == -1 and b == -1) return -1;
  if(a == -1) return b;
  if(b == -1) return a;
  int j = X++;
  scc.adde(a<<1|1, j<<1|1), scc.adde(j<<1, a<<1);
  scc.adde(b<<1|1, j<<1|1), scc.adde(j<<1, b<<1);
  return j;
}

struct ST {
  vvi v;
  int s;
  void init(int z) {
    s = z;
    v.assign(s<<2, vi());
  }
  void upd(int n, int l, int r, int gl, int gr, int q) {
    if(gl <= l and r <= gr) v[n].pb(q);
    else {
      int m = l + ((r-l)>>1);
      if(gl < m) upd(n<<1, l, m, gl, gr, q);
      if(m < gr) upd(n<<1|1, m, r, gl, gr, q);
    }
  }
  void upd(int gl, int gr, int q) {upd(1, 0, s, gl, gr, q);}
  int sbuild(int n, int l, int r) {
    if(r - l == 1) return build(v[n]);
    int m = l + ((r-l)>>1);
    int a = sbuild(n<<1, l, m), b = sbuild(n<<1|1, m, r);
    return build(v[n], cmb(a, b));
  }
  void sbuild() {sbuild(1, 0, s);}
};

vi a[MN];
ST H[MN];
vi L[MN];
int s[MN], d[MN], p[MN][MNL], t[MN], c[MN], l[MN];
int l2[MN];

void dfs(int n) {
  for(int i = 0;;i++) if(p[n][i] != -1 and p[p[n][i]][i] != -1) p[n][i+1] = p[p[n][i]][i]; else break;
  for(const int& x : a[n]) {
    if(x == p[n][0]) continue;
    p[x][0] = n, d[x] = d[n] + 1, dfs(x), s[n] += s[x];
  }
}
void hdfs(int n) {
  for(const int& x : a[n]) {
    if(x == p[n][0]) continue;
    if(s[x]<<1 >= s[n]) {
      if(t[n] == -1) t[n] = n, l[n] = 0;
      c[n] = x, t[x] = t[n], l[x] = l[n] + 1;
    }
    hdfs(x);
  }
  if(t[n] != -1 and c[n] == -1) H[t[n]].init(l[n]);
}
void upd(int n, int f, int q) {
  for(;n != f;) {
    if(t[n] != -1 and t[n] != n) {
      if(t[n] == t[f]) return H[t[n]].upd(l[f], l[n], q);
      H[t[n]].upd(0, l[n], q);
      n = t[n];
    } else {
      L[n].pb(q);
      n = p[n][0];
    }
  }
}
int mu(int n, int f) {
  for(;d[n] > f;) n = p[n][l2[d[n]-f]];
  return n;
}
int lca(int a, int b) {
  if(d[a] < d[b]) swap(a, b);
  if(d[a] != d[b]) a = mu(a, d[b]);
  if(a == b) return a;
  for(int i = l2[d[a]];i >= 0;i--) if(p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
  return p[a][0];
}

void bdfs(int n) {
  for(const int& x : a[n]) {
    if(x == p[n][0]) continue;
    bdfs(x);
  }
  if(t[n] == -1 or t[n] == n) build(L[n]);
  if(t[n] != -1 and t[n] != n and c[n] == -1) H[t[n]].sbuild();
}

int N, M;

int main() {
  for(int i = 0, j = -1;i < MN;i++) {
    if(i>>(j+1)) j++;
    l2[i] = j;
  }
  for(int i = 0;i < MN;i++) {
    s[i] = 1, d[i] = t[i] = c[i] = l[i] = -1;
    for(int j = 0;j < MNL;j++) p[i][j] = -1;
  }
  
  d[0] = 0;
  
  scanf("%d", &N);
  for(int i = 0, y, z;i < N - 1;i++) scanf("%d%d", &y, &z), a[y].pb(z), a[z].pb(y);
  dfs(1);
  hdfs(1);
  
  scanf("%d", &M);
  for(int i = 0, y, z;i < M<<1;i++) {
    scanf("%d%d", &y, &z);
    int r = lca(y, z);
    upd(y, r, i), upd(z, r, i);
  }
  
  X = M<<1;
  bdfs(1);
  
  for(int i = 0;i < M;i++) scc.adde(i<<2, i<<2|3), scc.adde(i<<2|2, i<<2|1);
  
  scc.scc(0, M<<2);
  
  for(int i = 0;i < M<<1;i++) if(scc[i<<1] == scc[i<<1|1]) return printf("NO\n"), 0;
  printf("YES\n");
  
  for(int i = 0;i < M;i++) if(scc[i<<2|1] > scc[i<<2]) printf("2\n"); else printf("1\n");
  
  return 0;
}