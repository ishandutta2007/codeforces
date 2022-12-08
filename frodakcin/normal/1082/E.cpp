#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 5e5 + 1000;
const int MAXV = 5e5 + 1000;

int N, C, a[MAXN];
int L[MAXN], l[MAXV], c[MAXN], v[MAXN], p[MAXN];
int ini, ans;

int main() {
  scanf("%d%d", &N, &C);
  ans = ini = 0;
  for(int i = 1;i <= N;i++) scanf("%d", a + i), ini += a[i] == C;
  
  for(int i = 0;i < N;i++) L[i] = 0, c[i] = 0, v[i] = 0;
  for(int i = 0;i < MAXV;i++) l[i] = 0;
  
  p[0] = p[1] = 0;
  for(int i = 1;i <= N;i++) {
    L[i] = l[a[i]];
    c[i] = c[L[i]] + 1;
    l[a[i]] = i;
    if(a[i] == C) p[i+1] = p[i] + 1; else p[i+1] = p[i];
  }
  
  for(int i = 1;i <= N;i++) {
    if(a[i] == C) continue;
    v[i] = v[L[i]] - (p[i+1] - p[L[i]]) + 1;
    if(v[i] < 1) v[i] = 1;
    if(v[i] > ans) ans = v[i];
  }
  
  printf("%d\n", ini + ans);
  
  return 0;
}