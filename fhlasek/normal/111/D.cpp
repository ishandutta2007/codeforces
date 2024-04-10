/* Writen by Filip Hlasek 2011 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>

#define FOR(i,n) for(i=0;i<n;i++)
#define MOD 1000000007

using namespace std;

int N,M,K;
long long dp[2222], fact[1111111], ifact[1111111];

long long p(int b,int po){
  long long res=1,m=b;
  int i;
  FOR(i,31){
    if(po&(1<<i)) res=(res*m)%MOD;
    m=(m*m)%MOD;
  }
  return res;
}

long long c(int a,int b){
  if(b>a) return -1;
  return (((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD;
}

int main(int argc, char *argv[]){
  scanf("%d%d%d",&N,&M,&K); 
  int i,j;
  fact[0]=1;
  FOR(i,1000002){
    fact[i+1]=(fact[i]*(i+1))%MOD;
    ifact[i]=p(fact[i],MOD-2);
  }
  dp[1]=1;
  for(i=2;i<N+1;i++){
    dp[i]=p(i,N);
    for(j=1;j<i;j++) dp[i]=(dp[i]-(dp[j]*c(i,j))%MOD+MOD)%MOD;
  }
  int barev,shoduje;
  long long sum=0,cur;
  if(M==1){
    cout << p(K,N) << endl;
    return 0;
  }
  for(barev=1;barev<=min(N,K);barev++) for(shoduje=0;shoduje<=barev;shoduje++) if((shoduje>0||M==2)&&2*barev-shoduje<=K){
    cur=(c(K,shoduje)*c(K-shoduje,barev-shoduje))%MOD;
    cur=(cur*c(K-barev,barev-shoduje))%MOD;
    cur=(cur*dp[barev])%MOD;
    cur=(cur*dp[barev])%MOD;
    cur=(cur*p(shoduje,N*(M-2)))%MOD;
    sum=(sum+cur)%MOD;
//    printf("barva:%d shoduje:%d cur:%lld sum:%lld\n",barev,shoduje,cur,sum);
  }
  cout << sum << endl;
  return 0;
}