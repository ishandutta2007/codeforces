#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e5 + 100;
const int MAXK = 100 + 10;
const int MOD = 998244353;

typedef long long ll;
#define tll(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

int sum(int a, int b) {return ti((tll(a) + tll(b))%MOD);}
int dif(int a, int b) {return ti((tll(a) - tll(b) + tll(MOD) * 100LL)%MOD);}
int prd(int a, int b) {return ti((tll(a) * tll(b))%MOD);}

int N, K, L;

int d[MAXN][MAXK], p[MAXN][MAXK], a[MAXN], l[MAXN][2];

int q(int l, int r, int k) {
  if(l == 0) return dif(p[r][0], p[r][k]);
  else return dif(dif(p[r][0], p[l-1][0]), dif(p[r][k], p[l-1][k]));
}
int g(int i, int k) {
  int v;
  if(a[l[i][0]] == k) v = l[i][1]; else v = l[i][0];
  if(v < i - L + 1) v = i - L + 1;
  return q(v, i-1, k);
}

int main() {
  scanf("%d%d%d", &N, &K, &L);
  
  if(L == 1) {printf("0\n"); return 0;}
  
  for(int i = 0;i <= N;i++) for(int j = 0;j <= K;j++) d[i][j] = p[i][j] = 0;
  for(int i = 1;i <= N;i++) scanf("%d", a + i);
  a[0] = -1;
  
  l[1][0] = l[1][1] = 0;
  for(int i = 1;i <= N;i++) {
    if(a[i] == -1) l[i+1][0] = l[i][0], l[i+1][1] = l[i][1];
    else if (a[i] == a[l[i][0]]) l[i+1][0] = i, l[i+1][1] = l[i][1];
    else l[i+1][1] = l[i][0], l[i+1][0] = i;
  }
  
  p[0][0] = d[0][0] = 1;
  
  for(int i = 1;i <= N;i++) {
    if(a[i] != -1) {
      d[i][a[i]] = g(i, a[i]);
    } else {
      for(int k = 1;k <= K;k++)
        d[i][k] = g(i, k);
    }
    for(int k = 1;k <= K;k++) d[i][0] = sum(d[i][0], d[i][k]);
    for(int k = 0;k <= K;k++) p[i][k] = sum(p[i-1][k], d[i][k]);
    //for(int k = 1;k <= K;k++) printf("dp[%d][%d] = %d\n", i, k, d[i][k]);
  }
  
  printf("%d\n", d[N][0]);
  
  return 0;
}