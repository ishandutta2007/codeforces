#include <iostream>
#include <cstdio>

#include <vector>
#include <bitset>
#include <stack>

using namespace std;

template<int T> using bs = bitset<T>;
template<class T> bool mn(T& a, const T& b) {return b<a?a=b,1:0;}
template<class T> bool mx(T& a, const T& b) {return a<b?a=b,1:0;}

const int MN = 1e5 + 100;
const int MM = 1e5 + 100;
const int MD = 50 + 10;

using si = stack<int>;
using vi = vector<int>;
#define pb push_back

int N, M, D;
vi a[MN];
int c[MN], C;
vi b[MN];
bs<MN> v, u;
int l[MN], d[MN], t;
si w;
void dfs(int n)
{
  v[n] = u[n] = 1;
  l[n] = d[n] = t++;
  w.push(n);
  for(int x : a[n])
  {
    if(u[x]) mn(l[n], d[x]);
    if(v[x]) continue;
    dfs(x);
    mn(l[n], l[x]);
  }
  if(l[n] == d[n])
  {
    b[C].clear();
    c[n] = C, b[C].pb(n);
    u[n] = 0;
    for(;w.top()!=n;w.pop())
      c[w.top()] = C, b[C].pb(w.top()), u[w.top()] = 0;
    w.pop();
    C++;
  }
}
void scc(void)
{
  v.reset(), u.reset();
  C = 0;
  t = 0;
  for(int i = 1;i <= N;i++)
    if(!v[i])
      dfs(i);
}

using vb = bs<MD>;
vb m[MN];

int g[MN];
int gcd(int a, int b)
{
  if(!a) return b;
  return gcd(b%a, a);
}
void dfs1(int n, int& g)
{
  v[n] = 1;
  for(int x : a[n])
  {
    if(c[x]!=c[n]) continue;
    if(v[x])
      g = gcd(g, abs(d[n]-d[x])+1);
    else
      d[x] = d[n]+1, dfs1(x, g);
  }
}
int q[MN][MD];
void workc(void)
{
  u.reset(), v.reset();
  for(int i = 0;i < C;i++)
  {
    d[b[i][0]] = 0, dfs1(b[i][0], g[i] = D);
    for(int x : b[i])
    {
      for(int j = g[i];j < D;j++) if(m[x][j-g[i]]) m[x][j]=1;
      for(int j = D-g[i]-1;j >= 0;j--) if(m[x][j+g[i]]) m[x][j]=1;
      for(int j = 0;j < D;j++) if(m[x][(j+d[x])%D]) q[i][j]++;
    }
  }
}
int f[MN][MD], F;
void dp(int y)
{
  for(int i = g[y];i < D;i++) mx(f[y][i], f[y][i-g[y]]);
  for(int i = D-g[y]-1;i >= 0;i--) mx(f[y][i], f[y][i+g[y]]);
  for(int i = 0;i < D;i++) f[y][i] += q[y][i];
  for(int n : b[y])
    for(int x : a[n])
      for(int i = 0;i < D;i++)
        mx(f[c[x]][((i+1+d[n]%D-d[x]%D+D)%D)], f[y][i]);
}
const int INF = 1e6;
void dpa(void)
{
  for(int i = 0;i < C;i++)
    for(int j = 0;j < D;j++)
      f[i][j] = -INF;
  f[c[1]][(D-d[1]%D)%D] = 0;
  for(int i = C-1;i >= 0;i--)
    dp(i);
  for(int i = 0;i < C;i++)
    for(int j = 0;j < D;j++)
      mx(F, f[i][j]);
}
int main(void)
{
  scanf("%d%d%d", &N, &M, &D);
  for(int i = 0, u, v;i < M;i++)
    scanf("%d%d", &u, &v), a[u].pb(v);
  for(int i = 1;i <= N;i++)
  {
    char c[MD];
    scanf(" %s", c);
    for(int j = 0;j < D;j++) m[i][j] = c[j]=='1';
  }
  scc();
  workc();
  dpa();
  printf("%d\n", F);
  return 0;
}