#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

const int MV = 5e5 + 100;
const int MM = 5e5 + 100;

int M, K, N, S, E;
int c[MV];
int a[MM], b[MM];
int g[MM];
int t, T;

void ins(int v) {
  if(g[v])
    t += (g[v] == ++c[v]);
}
void rem(int v) {
  if(g[v])
    t -= (g[v] == c[v]--);
}
bool valid() {
  return t == T;
}

using vi = vector<int>;
#define pb push_back
#define sz size()
vi f;
int ans(int x) {
  f.clear();
  for(int i = 0;i < MV;i++) c[i] = 0;
  for(int j = x*K;f.sz < E&&j < M;j++) {
    if(!g[a[j]]||g[a[j]] <= c[a[j]]++)
      f.pb(j);
  }
  printf("%lu\n", f.sz);
  for(int& y : f)
    printf("%d ", y+1);
  printf("\n");
  return 0;
}

void fail() {
  printf("-1\n");
}

int main() {
  scanf("%d%d%d%d", &M, &K, &N, &S);
  E = M-N*K;
  for(int i = 0;i < M;i++) scanf("%d", a + i);
  for(int i = 0;i < S;i++) {
    scanf("%d", b + i);
    T += (g[b[i]]++ == 0);
  }
  for(int i = 0, j = 0, k;i < N;i++) {
    for(;j < M&&j < i*K+K+E;j++)
      ins(a[j]);
    if(valid()) return ans(i);
    for(k = 0;k < K;k++)
      rem(a[i*K+k]);
  }
  fail();
  
  return 0;
}