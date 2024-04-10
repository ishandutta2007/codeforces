#include <iostream>
#include <cstdio>

const int MAXN = 1e6 + 100;

int N, M, k, d;
char s[MAXN], ans[MAXN];

int f[MAXN];
int p[MAXN], c[MAXN], c1[MAXN];

int temp1[MAXN];
int * work(int * o, const int * n, bool equ = false) {
  if(equ) {
    for(int i = 0;i < N;i++) temp1[i] = n[i];
    for(int i = 0;i < N;i++) o[i] = temp1[o[i]];
  }
  else for(int i = 0;i < N;i++) o[i] = n[o[i]];
  return o;
}
int temp[MAXN];
int * poww(int * b, int p) {
  for(int i = 0;i < N;i++) temp[i] = b[i];
  for(int i = 0;i < N;i++) b[i] = i;
  for(;p;p>>=1, work(temp, temp, true)) if(p&1) work(b, temp);
  return b;
}

int main() {
  scanf(" %s%d", s, &M);
  for(N = 0;s[N] != '\0';N++) f[N] = N;
  for(int i = 1;i < N;i++) c[i] = i - 1;
  c[0] = N - 1;
  
  while(M--) {
    scanf("%d%d", &k, &d);
    for(int i = 0, t = 0;i < d;i++) for(int j = 0;j*d + i < k;j++) p[j*d+i] = t++;
    for(int i = k;i < N;i++) p[i] = i;
    for(int i = 0;i < N;i++) c1[i] = c[i];
    
    work(p, c);
    poww(p, N-k+1);poww(c1, k-1);work(f, p);work(f, c1);
    
    for(int i = 0;i < N;i++) ans[f[i]] = s[i];
    printf("%s\n", ans);
  }
  return 0;
}