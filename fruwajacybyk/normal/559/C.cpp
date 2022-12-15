#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORD(i, a, b) for(int i = (a); i >= (b); --i)
#define VAR(v, i) __typeof(i) v=(i)
#define FORE(i, c) for(VAR(i, (c).begin()); i != (c).end(); ++i)

#define VI vector<int>
#define PII pair<int,int>
#define st first
#define nd second
#define mp make_pair
#define pb push_back
#define lint long long int

#define debug(x) {cerr <<#x <<" = " <<x <<endl; }
#define debug2(x,y) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y <<endl; } 
#define debug3(x,y,z) {cerr <<#x <<" = " <<x << ", "<<#y<<" = "<< y << ", " << #z << " = " << z <<endl; } 
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<endl; }}
#define debugt(t,n) {{cerr <<#t <<" = "; FOR(it,0,(n)) cerr <<t[it] <<", "; cerr <<endl; }}

#define make( x) int (x); scanf("%d",&(x));
#define make2( x, y) int (x), (y); scanf("%d%d",&(x),&(y));
#define make3(x, y, z) int (x), (y), (z); scanf("%d%d%d",&(x),&(y),&(z));
#define make4(x, y, z, t) int (x), (y), (z), (t); scanf("%d%d%d%d",&(x),&(y),&(z),&(t));
#define IOS ios_base::sync_with_stdio(0)
#define HEAP priority_queue

#define read( x) scanf("%d",&(x));
#define read2( x, y) scanf("%d%d",&(x),&(y));
#define read3(x, y, z) scanf("%d%d%d",&(x),&(y),&(z));
#define read4(x, y, z, t) scanf("%d%d%d%d",&(x),&(y),&(z),&(t));

using namespace std;
#define max_n 200005

int mod = 1e9+7;
int fac[max_n];
int inv[max_n];

int powmod(int a,int n){
  if(n==0) return 1;
  int x = powmod(a,n/2);
  int sq = (x*1LL*x)%mod;
  if(n%2==0) return sq;
  else return (sq*1LL*a)%mod;
}

vector<PII> pola;
int dp[2005];

int drogi(int dx,int dy){
  if(dx<0 || dy < 0) return 0;
  int k = dx+dy;
  int ans = (fac[k]*1LL*inv[dx])%mod;
  ans = (ans*1LL*inv[dy])%mod;
  return ans;
}

int main(){
  make3(h,w,n);
  fac[0] = 1; inv[0] = 1;
  FOR(i,1,2e5+2) fac[i] = (i*1LL*fac[i-1])%mod;
  FOR(i,1,2e5+2) inv[i] = (inv[i-1]*1LL*powmod(i,mod-2))%mod;
  
  pola.pb(mp(0,0));

  FOR(i,0,n){
    make2(a,b); a--; b--;
    pola.pb(mp(a,b));
  }
  pola.pb(mp(h-1,w-1));
  sort(pola.begin(),pola.end());
  dp[0] = 1;
  FOR(i,1,n+2){
    dp[i] = drogi(pola[i].st,pola[i].nd);
    FOR(j,1,i){
      int x = drogi(pola[i].st-pola[j].st,pola[i].nd-pola[j].nd);
      x = (x*1LL*dp[j])%mod;
      dp[i] += (mod-x);
      dp[i] %= mod;
    }
  }
  printf("%d\n",dp[n+1]);
  
}