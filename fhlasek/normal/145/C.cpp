/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)
#define MOD 1000000007

using namespace std;

int lucky[1111],L=0,U=0;
int cnt[1111],seq[1111],S=0;
map<int,int> l;

int N,K,a[111111];
int dp[1111][1111];

void gen_lucky(int x){
  if(x) lucky[L++] = x;
  if(x<100000000){
    gen_lucky(10*x+4);
    gen_lucky(10*x+7);
  }
}

int get(int k){
  if(k>S) return 0;
  return dp[S][k];
}

int fac[111111],ifac[111111];

int power(int a,int p){
  int res=1,m=a;
  REP(i,31){
    if(p&(1<<i)) res=((long long)res*m)%MOD;
    m=((long long)m*m)%MOD;
  }
  return res;
}

int c(int n,int k){ return (((long long)fac[n]*ifac[k])%MOD*ifac[n-k])%MOD; }

int main(int argc, char *argv[]){
  gen_lucky(0);
  REP(i,L) l[lucky[i]]=i;
  scanf("%d%d",&N,&K);
  fac[0]=1;
  REP(i,111111){
    fac[i+1]=((long long)fac[i]*(i+1))%MOD;
    ifac[i]=power(fac[i],MOD-2);
  }
  REP(i,N){
    scanf("%d",a+i);
    if(l.count(a[i])) cnt[l[a[i]]]++;
    else U++;
  }
  REP(i,L) if(cnt[i]) seq[S++] = cnt[i]; 
  dp[0][0] = 1;
  FOR(i,1,S) REP(j,S+1){
    dp[i][j] = dp[i-1][j];
    if(j) dp[i][j] = (dp[i][j]+(long long)dp[i-1][j-1]*seq[i-1])%MOD;
  }
  int res = 0;
  REP(i,min(U,K)+1) res=(res+(long long)get(K-i)*c(U,i))%MOD;
  printf("%d\n",res); 
  return 0;
}