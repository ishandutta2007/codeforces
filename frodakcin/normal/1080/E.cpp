#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 250 + 10;
const int MAXM = 250 + 10;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

int N, M;
int a[MAXN][MAXM];

ll ans;

bool equ(int * a, int * b) {
  for(int i = 0;i < 26;i++) if(a[i] != b[i]) return false;
  return true;
}
int e[MAXN], o[MAXN];

void solve(int (*a)[26], const int& n) {
  for(int i = 0, l = -1, r = -1;i < n;i++) {
    if(r < i) o[i] = 0; else o[i] = min(o[2*l - i], r - i);
    while(not(i < o[i]) and i + o[i] < n and equ(a[i - o[i]], a[i + o[i]])) o[i]++;
    if(i + o[i] > r) l = i, r = i + o[i];
  }
  for(int i = 0, l = -1, r = -1;i < n;i++) {
    if(r < i) e[i] = 0; else e[i] = min(e[2*l - i], r - i);
    while(not(i < e[i] + 1) and i + e[i] < n and equ(a[i - e[i] - 1], a[i + e[i]])) e[i]++;
    if(i + e[i] > r) l = i, r = i + e[i];
  }
  for(int i = 0;i < n;i++) ans += tll(o[i] + e[i]);
}

int v[MAXN];
int p[MAXN][26];
int c[MAXN][26];

int main() {
  scanf("%d%d", &N, &M);
  char sc;
  for(int i = 0;i < N;i++) for(int j = 0;j < M;j++) scanf(" %c", &sc), a[i][j] = static_cast<int>(sc) - 97;
  
  ans = 0LL;
  for(int i = 0;i < M;i++) {
    for(int j = 0;j < N;j++) {
      v[j] = 0;
      for(int k = 0;k < 26;k++) c[j][k] = p[j][k] = 0;
    }
    for(int j = i;j < M;j++) {
      for(int k = 0;k < N;k++) {
        c[k][a[k][j]]++;
        if(p[k][a[k][j]]&1) v[k]--; else v[k]++;
        p[k][a[k][j]]++;
      }
      for(int k = 0, l;k < N;k = l + 1) {
        for(l = k;l < N and not(1 < v[l]);l++);
        solve(p + k, l - k);
      }
    }
  }
  printf("%lld\n", ans);
  
  return 0;
}