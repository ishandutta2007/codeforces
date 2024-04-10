#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

typedef long long ll;
#define tll(X) static_cast<ll>(X)
inline void rph(ll& a, const ll& b) {if(a < b) a = b;}

const int MAXN = 2e5 + 100;

typedef vector<int> vi;
#define pb push_back
vi a[MAXN];

ll s[MAXN];
ll f;

ll dfs1(int n = 1, int p = -1, int d = 0) {
  f += s[n] * d;
  for(int u : a[n]) if(u != p) s[n] += dfs1(u, n, d + 1);
  return s[n];
}
void dfs2(ll v, int n = 1, int p = -1) {
  rph(f, v);
  for(int u : a[n]) if(u != p) dfs2(v + s[1] - (s[u]<<1), u, n);
}

int N;

int main() {
  scanf("%d", &N);
  for(int i = 1, w;i <= N;i++) scanf("%d", &w), s[i] = tll(w);
  for(int i = 0, u, v;i < N - 1;i++) scanf("%d%d", &u, &v), a[u].pb(v), a[v].pb(u);
  
  f = 0LL;
  dfs1();
  dfs2(f);    //need to use another answer variable if negative weights existed
  
  printf("%lld\n", f);
  
  return 0;
}