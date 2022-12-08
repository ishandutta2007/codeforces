#include <iostream>
#include <cstdio>

#include <vector>
#include <algorithm>

#include <cassert>

using namespace std;

using ll = long long;
#define tl(X) static_cast<ll>(X)
using vi = vector<int>;
#define pb push_back
#define sz size()
const int MN = 2e5 + 100;
int N;
int c[MN], p[MN], v[MN];
vi a[MN];
ll F;
void add(vi& u, int& q, int v, int n) {
  if(q < v)
    u.clear(), q = v;
  if(q == v)
    u.pb(n);
}
vi u[MN], f;
int q[MN], b[MN], t[MN];
bool w[MN];

void dfs(int n = 1) {
  q[n] = -1, v[n] = c[n];
  for(int x : a[n])
    if(p[n] != x)
      p[x] = n, dfs(x), add(u[n], q[n], v[x], x);
  if(q[n] != -1)
    if(q[n] < c[n])
      v[n] = q[n], b[n] = 1;
    else
      F += c[n] - q[n];
  else
    F += c[n];
}
void dfs2(int n = 1, int d = -1) {
  if(!b[n]&&!(d!=-1&&c[n] > d))
    f.pb(n);
  if(d == -1||d >= c[n]) d = c[n];
  if(u[n].sz > 1) d = -1;
  else t[n] = t[p[n]];
  int i = 0;
  for(int x : a[n]) {
    if(x == p[n]) continue;
    if(i<u[n].sz&&u[n][i]==x) {
      i++;
      dfs2(x, d);
    } else
      dfs2(x);
  }
}

int main() {
  scanf("%d", &N);
  for(int i = 1;i <= N;i++) scanf("%d", c + i), t[i] = i;
  for(int i = 0, u, v;i < N-1;i++)
    scanf("%d%d", &u, &v), a[u].pb(v), a[v].pb(u);
  dfs();
  dfs2();
  int c = 0;
  printf("%lld %lu\n", F, f.sz);
  sort(f.begin(), f.end());
  for(int i : f) printf("%d ", i);
  printf("\n");
  return 0;
}