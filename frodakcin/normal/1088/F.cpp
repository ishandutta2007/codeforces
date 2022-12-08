#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

static int log2(int v) {    //ceil(log2 v)
  int r = 0;
  --v;
  while(v) r++, v>>=1;
  return r;
}

const int MAXN = 5e5 + 1000;
const int L2N = 30;

int N, a[MAXN], R;

typedef vector<int> vi;
#define pb push_back
vi adj[MAXN];

int p[MAXN][L2N];

typedef long long ll;
#define tll(x) static_cast<ll>(x)

ll ans;

void rpl(ll& a, const ll& b) {
  if(b < a) a = b;
}

void dfs(int n, int q = -1, int d = 0) {
  p[n][0] = q;
  for(int i = 0;;i++) if(p[n][i] != -1 and p[p[n][i]][i] != -1) p[n][i+1] = p[p[n][i]][i]; else break;
  if(d) {
    ll b = tll(a[R]) * (1LL + log2(d));
    for(int i = 0;;i++) if(p[n][i] != -1) rpl(b, tll(a[p[n][i]]) * tll(1 + i)); else break;
    ans += b + tll(a[n]);
  }
  for(int i = 0;i < adj[n].size();i++) if(adj[n][i] != q) dfs(adj[n][i], n, d + 1);
}

int main() {
  R = 1;
  scanf("%d", &N);
  for(int i = 1;i <= N;i++) scanf("%d", a + i);
  for(int i = 2;i <= N;i++) if(a[i] < a[R]) R = i;
  
  for(int i = 0, u, v;i < N - 1;i++) {
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  for(int i = 0;i <= N;i++) for(int j = 0;j < L2N;j++) p[i][j] = -1;
  
  ans = 0LL;
  dfs(R);
  
  printf("%lld\n", ans);
  
  return 0;
}