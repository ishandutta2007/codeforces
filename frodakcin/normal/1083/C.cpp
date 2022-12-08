#include <iostream>
#include <cstdio>

#include <vector>

#include <cassert>

using namespace std;

const int MAXN = 2e5 + 100;
const int NL2 = 50;

typedef vector<int> vi;
#define pb push_back

vi adj[MAXN];

int p[MAXN][NL2];
int d[MAXN];

void dfs(int n) {
  for(int i = 0;;i++) if(p[n][i] != -1 and p[p[n][i]][i] != -1) p[n][i+1] = p[p[n][i]][i]; else break;
  for(int i = 0;i < adj[n].size();i++) {
    p[adj[n][i]][0] = n, d[adj[n][i]] = d[n] + 1;
    dfs(adj[n][i]);
  }
}

int l2(int n) {
  int r = 1;
  while(n>>=1)r++;
  return r;
}

int mu(int n, int l) {
  assert(not(d[n] < l));
  for(int i = l2(d[n] - l);i >= 0;i--) if(not (d[n] - (1<<i) < l)) assert((n = p[n][i]) != -1);
  return n;
}

bool isa(int n, int t) {
  if(d[t] < d[n]) return false;
  return mu(t, d[n]) == n;
}

int lca(int a, int b) {
  if(d[a] > d[b]) swap(a, b);
  b = mu(b, d[a]);
  if(a == b) return a;
  for(int i = l2(d[a]);i >= 0;i--) if(not (d[a] < 1 << i) and p[a][i] != p[b][i]) a = p[a][i], b = p[b][i];
  assert(p[a][0] != -1 and p[a][0] == p[b][0]);
  return p[a][0];
}

struct DAT {
public:
  int e[2];
  DAT() {e[0] = e[1] = -1;}
  DAT(int a, int b) {e[0] = a, e[1] = b;}
  DAT operator + (const DAT& o) const {
    if(e[0] == -1 or o.e[0] == -1) return DAT();
    int a = o.e[0], b = o.e[1], x, t;
    for(int i = 0;i < 2;i++) {
      x = lca(a, b);
      if(d[a] < d[b]) swap(a, b);
      if(x == b) {
        if(isa(a, e[i])) a = e[i];
        else if(d[t = lca(a, e[i])] > d[b] and t != e[i]) return DAT();
        else if(not(d[t] > d[b])) b = e[i];
      } else {
        if(d[e[i]] < d[x]) return DAT();
        if(isa(a, e[i])) a = e[i];
        else if(isa(e[i], a)) continue;
        else if(isa(b, e[i])) b = e[i];
        else if(isa(e[i], b)) continue;
        else return DAT();
      }
    }
    return DAT(a, b);
  }
};
ostream& operator << (ostream& os, const DAT& d) {
  return os << "(" << d.e[0] << ", " << d.e[1] << ")";
}

int l[MAXN];

struct ST {
public:
  DAT v[4 * MAXN];
  size_t s;
  ST(const size_t& s = 0) : s(s) {}
  void build(int n, int nl, int nr) {
    if(nr - nl > 1) {
      int m = nl + ((nr - nl)>>1);
      build(n<<1, nl, m);
      build(n<<1|1, m, nr);
      v[n] = v[n<<1] + v[n<<1|1];
    } else
      v[n] = DAT(l[nl], l[nl]);
  }
  void build() {
    build(1, 0, s);
  }
  void upd(int g, int n, int nl, int nr) {
    if(nr - nl == 1) {
      assert(nl == g);
      v[n] = DAT(l[nl], l[nl]);
    } else {
      int m = nl + ((nr - nl)>>1);
      if(g < m) upd(g, n<<1, nl, m);
      else upd(g, n<<1|1, m, nr);
      v[n] = v[n<<1] + v[n<<1|1];
    }
  }
  void upd(int g) {return upd(g, 1, 0, s);}
  int qry(const DAT& d, int n, int nl, int nr) {
    if((d + v[n]).e[0] != -1) return nr;
    if(nr - nl == 1) return nl;
    else {
      int m = nl + ((nr - nl)>>1);
      if(d.e[0] == -1) {
        if(v[n<<1].e[0] == -1) return qry(d, n<<1, nl, m);
        else return qry(v[n<<1], n<<1|1, m, nr);
      } else {
        DAT f;
        if((f = d + v[n<<1]).e[0] == -1) return qry(d, n<<1, nl, m);
        else return qry(f, n<<1|1, m, nr);
      }
    }
  }
  int qry() {return qry(DAT(), 1, 0, s);}
};

int N, Q;
int v[MAXN];

int main() {
  scanf("%d", &N);
  
  ST T(N);
  
  for(int i = 0;i < N;i++) scanf("%d", v + i), l[v[i]] = i;
  for(int i = 1, v;i < N;i++) scanf("%d", &v), adj[--v].pb(i);
  
  for(int i = 0;i < N;i++) for(int j = 0;j < NL2;j++) p[i][j] = -1;
  
  d[0] = 0;
  dfs(0);
  
  T.build();
  
  scanf("%d", &Q);
  for(int i = 0, t, w[2];i < Q;i++) {
    scanf("%d", &t);
    if(t == 1) {
      scanf("%d%d", w, w + 1);
      swap(v[--w[0]], v[--w[1]]);
      swap(l[v[w[0]]], l[v[w[1]]]);
      T.upd(v[w[0]]);
      T.upd(v[w[1]]);
    } else {
      printf("%d\n", T.qry());
    }
  }
  
  return 0;
}