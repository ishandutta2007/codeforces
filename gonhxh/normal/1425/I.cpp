#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native") 

#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define per(i, a, b) for(int i = b-1; i>=a ; i--)
#define trav(a, x) for(auto& a : x)
#define allin(a , x) for(auto a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vl;
typedef vector<pii> vpi;
typedef pair<ll,ll> pll;
typedef vector<string> vs;
typedef vector<pll> vpl;
typedef vector<int> vi;


int readint(){
  char c;
  int a = 0;
  bool k = false;
  while(!(c >= '0' && c <= '9') && !(c == '-')){
    c = getchar();
  }
  if(c == '-'){
    k = true;
    c = getchar();
  }
  while(c >= '0' && c <= '9'){
    a = 10*a + (c-'0');
    c = getchar();
  }
  return a *(k ? -1 : 1);
}
const int N = 50100;
int h[N],tin[N],tout[N],last[N],a[N];
int t=0;
vi g[N];
int rev[N];
int A[N];
void dfs(int v,int d =0){
  tin[v]=++t;
  A[t] = a[v];
  h[t] = d;
  for(int to : g[v]){
    dfs(to,d + 1);
  }
  tout[v]=t;
}
int X[N];
int32_t main(){
  int n,q;
  scanf("%d %d",&n,&q);
  for(int i=1;i<=n;i++)scanf("%d",&a[i]);

  for(int i=2;i<=n;i++){
    int p;
    scanf("%d",&p);
    g[p].push_back(i);
  }
  dfs(1);
  for(int i=1;i<=q;i++)scanf("%d",&X[i]);
  for(int ti=1;ti<=q;ti++){
    int x = X[ti];
    int r1=0,r2=0;
    for(int i=tin[x];i<=tout[x];i++){
      bool pega = (last[i]<=ti);
      r2+=pega;
      r1+=pega*h[i];
      last[i] = (pega ? ti + A[i] : last[i]);
    }
    r1-=r2 * h[tin[x]];
    printf("%d %d\n",r1,r2);
  }

}