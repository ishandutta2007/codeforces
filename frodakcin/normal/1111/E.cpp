#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>
#include <array>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)
const int MD = 1e9 + 7;
const int MN = 1e5 + 100;
const int NL = 20;
const int MQ = 1e5 + 100;
const int MM = 3e2 + 10;
using vi = vector<int>;
#define pb push_back
vi a[MN];
int N, Q;
int p[MN], o[MN][2], w[MN], d[MN];
using i2 = array<int, 2>;
bool operator < (const i2& a, const i2& b) {return a[0]<b[0]||(!(b[0]<a[0])&&a[1]<b[1]);}
i2 q[MN<<1][NL];
int l2[MN<<1];
void dfs(int n = 1, int * c = new int(0), int * e = new int(0))
{
  o[n][0] = (*c)++;
  q[w[n] = (*e)++][0] = {d[n], n};
  for(int x : a[n])
    if(p[n]!=x)
      p[x] = n, d[x] = d[n]+1, dfs(x, c, e), q[(*e)++][0] = {d[n], n};
  o[n][1] = *c;
}
bool cmpo(const int& a, const int& b) {return o[a][0] < o[b][0];}
int h[MN];
ll f[MM];
int K, M, R;
int n[MN], u[MN];
vi c[MN];
template<int MS> struct ST
{
  int v[MS], z[MS];
  bool w[MS];
  int s;
  void init(int s) {this->s = s;}
  void res(int n = 1)
  {
    v[n] = z[n] = 0;
    w[n] = 1;
  }
  void adz(int n, int q, int l, int r)
  {
    if(w[n]&&r-l>1) res(n<<1), res(n<<1|1);
    v[n] += q;
    z[n] += q;
    w[n] = 0;
  }
  void down(int n, int l, int r)
  {
    if(r-l>1)
    {
      if(w[n]) 
        res(n<<1), res(n<<1|1), w[n] = 0;
      else if(z[n])
      {
        int m = l + ((r-l)>>1);
        adz(n<<1, z[n], l, m), adz(n<<1|1, z[n], m, r);
        z[n] = 0;
      }
    }
  }
  void up(int n)
  {
    v[n] = max(v[n<<1], v[n<<1|1]);
  }
  void upd(int n, int l, int r, int ql, int qr, int q)
  {
    if(ql <= l&&r <= qr) return adz(n, q, l, r);
    down(n, l, r);
    int m = l + ((r-l)>>1);
    if(ql < m) upd(n<<1, l, m, ql, qr, q);
    if(m < qr) upd(n<<1|1, m, r, ql, qr, q);
    up(n);
  }
  void upd(int ql, int qr, int q) {return upd(1, 0, s, ql, qr, q);}
  int qry(int n, int l, int r, int q)
  {
    if(r-l==1) return v[n];
    down(n, l, r);
    int m = l + ((r-l)>>1);
    if(q < m) return qry(n<<1, l, m, q);
    else return qry(n<<1|1, m, r, q);
  }
  int qry(int q) {return q==-1?0:qry(1, 0, s, q);}
};
ST<MN*3> st;
void pcpL(void)
{
  for(int i = 0, j = -1;i < MN<<1;i++)
    l2[i] = i>>j+1?++j:j;
}
void pcpq(void)
{
  for(int i = (N<<1)-1;i >= 0;i--)
    for(int j = 0;i+(1<<j+1) < (N<<1)-1;j++)
      q[i][j+1] = min(q[i][j], q[i+(1<<j)][j]);
}
int lca(int a, int b)
{
  if(a==b)return a;
  if(w[b] < w[a]) swap(a, b);
  int x = l2[w[b]-w[a]];
  return min(q[w[a]][x], q[w[b]-(1<<x)][x])[1];
}
int t;
bool g[MN];
void AQ(void)
{
  scanf("%d%d%d", &K, &M, &R);
  st.res();
  for(int i = 0;i < K;i++)
    scanf("%d", n + i), st.upd(o[n[i]][0], o[n[i]][1], 1), g[n[i]] = 1;
  for(int i = 0;i < K;i++)
    t = lca(n[i], R), h[n[i]] = st.qry(o[n[i]][0])+st.qry(o[R][0])-(st.qry(o[t][0])<<1) + g[t]-1;
  for(int i = 0;i <= M;i++)
    f[i] = 0LL;
  f[0] = 1LL;
  sort(n, n + K, [](const int& a, const int& b){return h[a]<h[b];});
  for(int i = 0;i < K;i++)
    for(int j = M;j >= 0;j--)
      f[j] = ((j?f[j-1]:0LL)+(j>h[n[i]]?f[j]*(j-h[n[i]]):0LL))%MD;
  ll F = 0;
  for(int i = 0;i <= M;i++)
    F += f[i];
  for(int i = 0;i < K;i++)
    g[n[i]] = 0;
  printf("%d\n", ti(F%MD));
}
int main(void)
{
  pcpL();
  scanf("%d%d", &N, &Q);
  for(int i = 0, u, v;i < N-1;i++)
    scanf("%d%d", &u, &v), a[u].pb(v), a[v].pb(u);
  dfs();
  o[0][0] = o[0][1] = -1;
  pcpq();
  st.init(N);
  for(;Q--;)
    AQ();
  return 0;
}