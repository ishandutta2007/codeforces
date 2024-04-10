#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define Debug(...) fprintf(stderr, __VA_ARGS__)

typedef long long LL;
typedef long double LD;
typedef unsigned int uint;
typedef pair <int, int> pii;
typedef unsigned long long uLL;

template <typename T> inline void Read(T &x) {
  char c = getchar();
  bool f = false;
  for (x = 0; !isdigit(c); c = getchar()) {
    if (c == '-') {
      f = true;
    }
  }
  for (; isdigit(c); c = getchar()) {
    x = x * 10 + c - '0';
  }
  if (f) {
    x = -x;
  }
}



const int N = 1000010;

int n, lst, cnt, f[N], g[N], h[N], anc[N], par[N], dif[N], len[N], nxt[N][26];
char s[N], p[N], q[N];

inline void Extend(int w, int n) {
  int p;
  for (p = lst; s[n] != s[n - len[p] - 1]; p = par[p]);
  if (!nxt[p][w]) {
    int x = ++cnt, k = par[p];
    for (; s[n] != s[n - len[k] - 1]; k = par[k]);
    len[x] = len[p] + 2, par[x] = nxt[k][w], nxt[p][w] = x, dif[x] = len[x] - len[par[x]], anc[x] = dif[x] == dif[par[x]] ? anc[par[x]] : par[x];
  }
  lst = nxt[p][w];
}

int main()
{
    int i,j;
    scanf("%s",p+1);
    n=strlen(p+1);
    for(i=1;i<=n;i++)
      if(i&1)
        s[i]=p[i/2+1];
      else
        s[i]=p[n-i/2+1];
  //memset(f, 0x3f, sizeof f);
  lst = cnt = 1, par[0] = 1, par[1] = 0, len[1] = -1, f[0] = 1;
  s[0]=-1;
  for (int i = 1; i <= n; ++i) {
    Extend(s[i] - 'a', i);
    for (int x = lst; x; x = anc[x]) {
      g[x] = f[i - len[anc[x]] - dif[x]];
      if (anc[x] != par[x]) {
        g[x] = (g[x]+g[par[x]])%mod;
      }
      if (!(i & 1)) {
        f[i] = (f[i]+g[x])%mod;
      }
    }
    }
  printf("%d\n",f[n]);
  return 0;
}