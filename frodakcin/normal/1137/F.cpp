#include <iostream>
#include <cstdio>

#include <vector>
#include <queue>
#include <functional>

#include <cassert>

using namespace std;

const int MN = 2e5 + 100;
const int NL = 20;

int c[MN][2], p[MN];
int s[MN];
bool r[MN], g[MN];
int f[MN][2];

int gs(int n){return n?s[n]:0;}
void upd(int n)
{
  s[n] = 1 + gs(c[n][0]) + gs(c[n][1]);
}
bool son(int n)
{
  //assert(p[n]);
  return c[p[n]][1]==n;
}
void sc(int a, bool x, int b)
{
  c[a][x] = b;
  if(b) p[b] = a;
}
void rp(int a, int b)
{
  p[b] = p[a];
  if(p[a]) c[p[a]][son(a)]=b;
}
void rot(int n, bool d)
{
  //assert(n&&c[n][d]);
  int o = c[n][d];
  //upd(o);
  rp(n, o), sc(n, d, c[o][!d]), sc(o, !d, n);
  upd(n), upd(o);
}
void rotup(int n)
{
  rot(p[n], son(n));
}
void down(int n)
{
  if(g[n])
  {
    for(int i:{0,1})
      if(c[n][i])
        f[c[n][i]][0] = f[n][0], f[c[n][i]][1] = f[n][1], g[c[n][i]] = 1;
    g[n] = 0;
  }
  if(r[n])
  {
    swap(c[n][0], c[n][1]);
    for(int i:{0,1}) if(c[n][i]) r[c[n][i]] ^= 1;
    r[n] = 0;
  }
}
void propup(int n)
{
  if(p[n]) propup(p[n]);
  down(n);
}
void splay(int n)
{
  propup(n);
  for(;p[n];)
  {
    if(p[p[n]])
    {
      if(son(n)==son(p[n]))
        rotup(p[n]);
      else
        rotup(n);
    }
    rotup(n);
  }
}

using vi = vector<int>;
#define pb push_back
using pq = priority_queue<int, vi, greater<int> >;
#define sz size()
#define tp top()
vi a[MN];
int z[MN];
int N, Q, m;

int u[MN][NL], d[MN], o[MN][2];
void dfs(int n = 1, int * c = new int(0))
{
  o[n][0] = (*c)++;
  for(int i = 0;;i++)
    if(u[n][i]&&u[u[n][i]][i])
      u[n][i+1] = u[u[n][i]][i];
    else break;
  for(int x : a[n])
    if(x != u[n][0])
      u[x][0] = n, d[x] = d[n]+1, dfs(x, c);
  o[n][1] = *c;
}
int l[MN];
void pcpl()
{
  for(int i = 0, j = -1;i < MN;i++)
  {
    if(i>>j+1) j++;
    l[i] = j;
  }
}
int mu(int n, int x)
{
  //assert(d[n] >= x);
  for(;d[n]>x;)
    n = u[n][l[d[n]-x]];
  return n;
}

void greedy(void)
{
  m = 0;
  pq q = pq();
  for(int i = 1;i <= N;i++)
    if((z[i] = a[i].sz)==1)
      q.push(i);
  for(int x;!q.empty();)
  {
    x = q.tp;
    q.pop();
    sc(x, 0, m);
    f[x][0] = f[x][1] = x;
    upd(m = x);
    for(int y : a[x])
      if(--z[y]==1)
        q.push(y);
  }
  //assert(m==N);
}
int when(int n)
{
  splay(n);
  return 1+gs(c[n][0]);
}
int splayd(int n, int d = 0)
{
  //assert(n);
  down(n);
  for(;c[n][d];)
  {
    down(c[n][d]);
    rot(n, d);
    n = p[n];
  }
  return n;
}
int merge(int a, int b)
{
  if(!b) return a;
  if(!a) return b;
  a = splayd(a, 1);
  //splay(b);
  //assert(!c[a][1]);
  c[a][1] = b;
  p[b] = a;
  upd(a);
  return a;
}
void out(int n, bool F = 1)
{
  down(n);
  if(c[n][0]) out(c[n][0], 0);
  printf("%d(%d, %d) ", n, f[n][0], f[n][1]);
  if(c[n][1]) out(c[n][1], 0);
  if(F) printf("\n");
}
void up(int v)
{
  if(v==m) return;
  int a = 0, b = 0;
  for(int i = v, j, k;;)
  {
    splay(i);
    if(c[i][0])
    {
      j = c[i][0];
      p[j] = 0, c[i][0] = 0, upd(i);
      j = splayd(j, 1);
      if(f[j][1] != j)
      {
        k = j;
        splay(j = f[j][0]);
        if(c[j][0])
          p[c[j][0]] = 0, a = merge(a, c[j][0]), c[j][0] = 0, upd(j);
        f[j][1] = k, g[j] = 1;
      }
      a = merge(a, j);
    }
    splay(i = f[i][1]);
    if(c[i][1])
      p[c[i][1]] = 0, c[i][1] = 0, upd(i);
    b = merge(b, i);
    if(i==m) break;
    if(o[i][0] <= o[m][0]&&o[m][1] <= o[i][1])
      i = mu(m, d[i]+1);
    else
      i = u[i][0];
  }
  m = v;
  b = splayd(b, 1);
  g[b] = 1, f[b][1] = v, f[b][0] = b;
  r[b] ^= 1;
  merge(a, b);
}
char h[10];
int x, y;
void AQ(void)
{
  scanf(" %s%d", h, &x);
  if(h[0]=='u') up(x);
  if(h[0]=='w') printf("%d\n", when(x));
  if(h[0]=='c') scanf("%d", &y), printf("%d\n", when(y)<when(x)?y:x);
}
int main(void)
{
  pcpl();
  scanf("%d%d", &N, &Q);
  for(int i = 0, u, v;i < N-1;i++)
    scanf("%d%d", &u, &v), a[u].pb(v), a[v].pb(u);
  greedy();
  dfs();
  for(;Q--;)
    AQ();
  return 0;
}