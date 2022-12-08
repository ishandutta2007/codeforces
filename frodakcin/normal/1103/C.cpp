#include <iostream>
#include <cstdio>

#include <vector>

#include <cassert>

using namespace std;

int N, M, K;

const int MN = 2.5e5 + 1000;
const int MK = 2.5e5 + 1000;
const int MM = 5e5 + 1000;

using vi = vector<int>;
#define pb push_back
vi a[MN];

int p[MN], d[MN];

void path(int n) {
  printf("PATH\n%d\n", d[n]);
  for(;n != -1;n=p[n]) printf("%d\n", n);
  exit(0);
}

bool v[MN];
void dfs(int n) {
  v[n] = true;
  if(d[n]*K >= N) path(n);
  for(int& x : a[n]) if(not v[x]) p[x] = n, d[x] = d[n] + 1, dfs(x);
}

void out(int n, int g) {
  printf("%d ", n);
  if(n != g) out(p[n], g);
}

int k;
void dfs2(int n) {
  bool c = true;
  vi b(0, -1);
  for(int& x : a[n]) if(p[x] == n) dfs2(x), c = false; else if(p[n] != x) b.pb(x);
  if(c) {
    assert(b.size() > 1);
    
    if((d[n] - d[b[0]] + 1)%3) {
      printf("%d\n", d[n] - d[b[0]] + 1);
      out(n, b[0]);
      printf("\n");
    } else if((d[n] - d[b[1]] + 1)%3) {
      printf("%d\n", d[n] - d[b[1]] + 1);
      out(n, b[1]);
      printf("\n");
    } else {
      if(d[b[0]] < d[b[1]]) swap(b[0], b[1]);
      printf("%d\n", d[b[0]] - d[b[1]] + 2);
      printf("%d ", n);
      out(b[0], b[1]);
      printf("\n");
    }
    
    if(--k == 0) exit(0);
  }
}

int main() {
  scanf("%d%d%d", &N, &M, &K);
  
  for(int i = 0, u, v;i < M;i++) scanf("%d%d", &u, &v), a[u].pb(v), a[v].pb(u);
  for(int i = 0;i <= N;i++) v[i] = false;
  
  d[1] = 1, p[1] = -1, dfs(1);
  printf("CYCLES\n");
  k = K;
  dfs2(1);
  
  return 0;
}