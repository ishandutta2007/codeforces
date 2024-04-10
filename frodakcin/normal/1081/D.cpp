#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 100;
const int MAXM = 1e5 + 100;

struct E {
  int u, v, w;
  bool operator < (const E& o) const {return w < o.w;}
} e[MAXM];

int R;
int dsup[MAXN], dsur[MAXN];
bool q[MAXN];
void dsui(int n) {
  for(int i = 0;i <= n;i++) dsup[i] = i, dsur[i] = 0, q[i] = false;
}
int dsuf(int n) {
  if(dsup[n] == n) return n;
  return dsup[n] = dsuf(dsup[n]);
}
bool dsum(int a, int b) {
  a = dsuf(a), b = dsuf(b);
  if(a == b) return false;
  if(dsur[a] < dsur[b]) swap(a, b);
  if(q[a] and q[b]) --R;
  q[a] |= q[b], dsur[a]++, dsur[b] = 0, dsup[b] = a;
  return true;
}

int N, M, K, F;

int main() {
  F = 0;
  scanf("%d%d%d", &N, &M, &K);
  R = K;
  dsui(N);
  for(int i = 0, u;i < K;i++) scanf("%d", &u), q[u] = true;
  for(int i = 0;i < M;i++) scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
  sort(e, e + M);
  for(int i = 0;i < M;i++) {
    dsum(e[i].u, e[i].v);
    if(R == 1) {F = e[i].w; break;}
  }
  for(int i = 0;i < K;i++) printf("%d ", F);
  printf("\n");
  return 0;
}