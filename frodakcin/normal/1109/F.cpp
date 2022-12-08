#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)

const int INF = 1e9 + 100;
struct ND {
public:
  int m, c, z;
  ND operator + (const ND& o) const {
    if(o.m == m) return {m, c + o.c, 0};
    if(o.m < m) return {o.m, o.c, 0};
    else return {m, c, 0};
  }
};
template<int MS> struct ST {
public:
  ND v[MS];
  int s;
  void init(int n, int l, int r) {
    v[n] = {0, r-l, 0};
    if(r-l>1) {
      int m = l + ((r-l)>>1);
      init(n<<1, l, m), init(n<<1|1, m, r);
    }
  }
  void init(int S) {
    init(1, 0, s = S);
  }
  void addm(int n, int q) {
    v[n].z += q, v[n].m += q;
  }
  void down(int n, int l, int r) {
    if(!v[n].z) return;
    if(r-l>1)
      addm(n<<1, v[n].z), addm(n<<1|1, v[n].z);
    v[n].z = 0;
  }
  void up(int n, int l, int r) {
    v[n] = v[n<<1] + v[n<<1|1];
  }
  void upd(int n, int l, int r, int ql, int qr, int q) {
    if(ql <= l&&r <= qr) return addm(n, q), down(n, l, r);
    down(n, l, r);
    int m = l + ((r-l)>>1);
    if(ql < m) upd(n<<1, l, m, ql, qr, q);
    if(m < qr) upd(n<<1|1, m, r, ql, qr, q);
    up(n, l, r);
  }
  void upd(int ql, int qr, int q) {return upd(1, 0, s, ql, qr, q);}
  int rmz(int n, int l, int r, int ql, int qr) {
    if(v[n].m > 0) return -1;
    if(r-l==1) return l;
    down(n, l, r);
    int m = l + ((r-l)>>1), f;
    if(m < qr) if((f = rmz(n<<1|1, m, r, ql, qr)) != -1) return f;
    if(ql < m) return rmz(n<<1, l, m, ql, qr);
    return -1;
  }
  int rmz(int ql, int qr) {return rmz(1, 0, s, ql, qr);}
  ND qry(int n, int l, int r, int ql, int qr) {
    if(ql <= l&&r <= qr) return v[n];
    down(n, l, r);
    ND f = {INF, INF, 0};
    int m = l + ((r-l)>>1);
    if(ql < m) f = f + qry(n<<1, l, m, ql, qr);
    if(m < qr) f = f + qry(n<<1|1, m, r, ql, qr);
    return f;
  }
  ND qry(int ql, int qr) {return qry(1, 0, s, ql, qr);}
};

const int MN = 1e3 + 10;
const int MP = 2e5 + 100;

ST<MP<<2> st;

int N, M, g[MN][MN];
bool ib(int x, int y) {return (0 <= x&&x < N)&&(0 <= y&&y < M);}
int w[MP][2], t[MP];
ll F;
const int dx[4] = {1, 0, 0, -1};
const int dy[4] = {0, 1, -1, 0};

//L/C T
struct SPL {
public:
  int v;
  SPL * c[2], * p;
  int s;
  bool f;
  SPL() {
    p = nullptr;
    for(int i:{0,1})c[i]=nullptr;
    s = 1;
    f = 0;
  }
  void upd() {
    s = 1;
    if(c[0]) s += c[0]->s;
    if(c[1]) s += c[1]->s;
  }
  void fix() {
    if(f) {
      if(c[0]) c[0]->f = !c[0]->f;
      if(c[1]) c[1]->f = !c[1]->f;
      swap(c[0], c[1]);
      f = 0;
    }
  }
};
SPL v[MP];
int p[MP];
int son(SPL * n) {return n->p->c[1] == n;}
SPL * rot(SPL * n, int d) {
  n->fix();
  assert(n&&n->c[d]);
  SPL * o = n->c[d];
  o->fix(), p[o->v] = p[n->v];    //down
  n->c[d] = o->c[!d], o->c[!d] = n;
  if(n->c[d]) n->c[d]->p = n;
  if((o->p = n->p)) n->p->c[son(n)] = o;
  n->p = o;
  n->upd(), o->upd();
  return o;
}
void rotup(SPL * n) {
  rot(n->p, son(n));
}
void fixu(SPL * n) {
  if(n->p) fixu(n->p);
  n->fix();
}
void splay(SPL * n) {
  fixu(n);
  for(;n->p;) {
    if(n->p->p) {
      if(son(n)==son(n->p)) rotup(n->p), rotup(n);
      else rotup(n), rotup(n);
    } else {
      rotup(n);
    }
  }
}
void access(int n) {
  splay(&v[n]);
  SPL * o;
  if((o = v[n].c[1])) {
    p[o->v] = n;
    o->p = nullptr, v[n].c[1] = nullptr;
  }
  for(int w, u = n;p[u] != -1;) {
    w = p[u];
    v[w].fix();
    splay(&v[w]);
    if(v[w].c[1]) {
      p[v[w].c[1]->v] = w;
      v[w].c[1]->p = nullptr, v[w].c[1] = nullptr;
    }
    v[w].c[1] = &v[u], v[u].p = &v[w];
    v[w].upd();
    u = w;
  }
  splay(&v[n]);
  assert(!v[n].p);
}
int root(int n) {
  access(n);
  SPL * x = &v[n];
  while(x->c[0]) (x = x->c[0])->fix();
  return x->v;
}
bool connected(int a, int b) {
  bool f = root(a) == root(b);
  //printf("? %d %d: %d\n", a, b, f);
  return f;
}
void link(int a, int b) {
  //printf("L %d %d\n", a, b);
  access(a);
  access(b);
  if(v[b].c[0]) {
    SPL * l = v[b].c[0];
    p[l->v] = b, l->p = nullptr;
    l->f ^= 1;
    v[b].c[0] = nullptr;
    v[b].upd();
  }
  p[b] = a;
}
void cut(int a, int b) {
  //printf("C %d %d\n", a, b);
  access(a), splay(&v[b]);
  if(a != p[b]) {
    swap(a, b);
    access(a), splay(&v[b]);
  }
  assert(a == p[b]);
  p[b] = -1;
}
void init(int x) {
  for(int i = 0;i <= x;i++) v[i].v = i, p[i] = -1;
}

void rem(int l, int r, int q) {
  int x = w[q][0], y = w[q][1], x1, y1;
  for(int i = 0, j;i < 4;i++) {
    if(!ib(x1 = x + dx[i], y1 = y + dy[i])) continue;
    j = g[x1][y1];
    if(l <= j&&j < r) cut(j, q);
  }
}

int main(void) {
  scanf("%d%d", &N, &M);
  for(int i = 0;i < N;i++)
    for(int j = 0;j < M;j++)
      scanf("%d", g[i] + j), w[g[i][j]][0] = i, w[g[i][j]][1] = j;
  st.init(N*M), F = 0LL;
  init(N*M);
  t[0] = 1;
  for(int i = 1, e = N*M, x, y, x1, y1;i <= e;i++) {
    t[i] = t[i-1];
    x = w[i][0], y = w[i][1];
    for(int j = 0, k;j < 4;j++) {
      if(!ib(x1 = x + dx[j], y1 = y + dy[j])) continue;
      k = g[x1][y1];
      for(;t[i] <= k&&k < i&&connected(i, k);t[i]++) rem(t[i], i, t[i]);
      if(t[i] <= k&&k < i) link(i, k);
    }
    //cerr << i << " " << t[i] << "\n";
  }
  for(int i = 1, e = N*M, x, y;i <= e;i++) {
    x = w[i][0], y = w[i][1];
    st.upd(t[i]-1, i, 1);
    for(int j = 0, x2, y2;j<4;j++) {
      x2 = x+dx[j], y2 = y+dy[j];
      if(ib(x2, y2)&&g[x2][y2]<i&&g[x2][y2]>=t[i])
        st.upd(t[i]-1, g[x2][y2], -1);
    }
    F += st.qry(t[i]-1, i).c;
  }
  printf("%lld\n", F);
  return 0;
}