#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

const int MAXN = 3e5 + 100;
const int MAXM = 3e5 + 100;

const int MOD = 998244353;

typedef long long ll;
#define tll(X) static_cast<ll>(X)
#define ti(X) static_cast<int>(X)

int sum(const int& a, const int& b) {return ti((tll(a) + tll(b))%MOD);}
int dif(const int& a, const int& b) {return ti((tll(a) + tll(b) + tll(MOD) * 100LL)%MOD);}
int prd(const int& a, const int& b) {return ti((tll(a) * tll(b))%MOD);}
int pw(int b, int p) {
  int r = 1;
  for(;p;b=prd(b, b), p>>=1) if(p&1) r = prd(r, b);
  return r;
}

int N, M;

typedef vector<int> vi;
#define pb push_back

vi adj[MAXN];
int v[MAXN], c[2];
bool A;
int a;

void dfs(int n, bool C) {
  if(not A) return;
  if(v[n] != -1) {
    if(C != v[n]) A = false;
    return;
  }
  c[v[n] = C]++;
  for(int i = 0;i < adj[n].size();i++)
    dfs(adj[n][i], not C);
}
void solve() {
  scanf("%d%d", &N, &M);
  for(int i = 0;i <= N;i++) v[i] = -1, adj[i].clear();
  
  for(int i = 0, u, v;i < M;i++) {
    scanf("%d%d", &u, &v);
    adj[u].pb(v);
    adj[v].pb(u);
  }
  
  A = true;
  a = 1;
  for(int i = 1;i <= N;i++) {
    if(v[i] == -1) {
      c[0] = c[1] = 0;
      dfs(i, 0);
      if(not A) {printf("0\n"); return;}
      a = prd(a, sum(pw(2, c[0]), pw(2, c[1])));
    }
  }
  
  printf("%d\n", a);
}

int T;
int main() {
  scanf("%d", &T);
  while(T--) solve();
  return 0;
}