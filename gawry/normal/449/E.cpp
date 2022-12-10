#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
int t,n,m;
const int MOD=1000000000+7;
const int MAX=1000001;
long long f[MAX],f2[MAX],f3[MAX],phi[MAX],g[MAX],g1[MAX],g2[MAX],g3[MAX];
vector<int> d[MAX];
bool p[MAX];
int main(){
  scanf("%d",&t);
  for(int i=1;i<MAX;i++){
    phi[i]=i;
    p[i]=true;
  }
  for(int i=2;i<MAX;i++)if(p[i]){
    for(int j=i;j<MAX;j+=i){
      p[j]=false;
      assert(phi[j]%i==0);
      phi[j]=phi[j]/i*(i-1);
    }
  }
  for(int i=1;i<MAX;i++)for(int j=2*i;j<MAX;j+=i){
    g[j]+=i*phi[j/i];
  }
  for(int i=1;i<MAX;i++)g[i]*=2;
  for(long long side=1;side<MAX;side++){
    long long tmp=0;
    long long z[3]={side,side-1,2*side-1},pos=0;
    while(z[pos]%3)++pos;
    z[pos]/=3;
    tmp+=(z[0]*z[1]%MOD*z[2]%MOD)*side%MOD*side%MOD;
    tmp-=(side*side%MOD-2*side)*side%MOD*side%MOD;
    f[side]=(f[side-1]+tmp%MOD+MOD)%MOD;
  
    tmp=0;
    tmp-=(z[0]*z[1]%MOD*z[2]%MOD)*side%MOD;
    tmp+=(side*side%MOD-2*side)*side%MOD;
    f2[side]=(f2[side-1]+tmp%MOD+MOD)%MOD;
  
    tmp=0;
    tmp+=(z[0]*z[1]%MOD*z[2]%MOD);
    tmp-=(side*side%MOD-2*side);
    f3[side]=(f3[side-1]+tmp%MOD+MOD)%MOD;
  
    g1[side]=(g1[side-1]+g[side])%MOD;
    g2[side]=(g2[side-1]+g[side]*side)%MOD;
    g3[side]=(g3[side-1]+g[side]*side%MOD*side)%MOD;
  }
  while(t--){
    scanf("%d%d",&n,&m);
    long long ans=(f[min(n,m)]+f2[min(n,m)]*(n+m+2)%MOD+f3[min(n,m)]*(n+1)%MOD*(m+1)%MOD)%MOD;

    ans=(ans+g1[min(n,m)]*(n+1)%MOD*(m+1))%MOD;
    ans=(ans-g2[min(n,m)]*(n+m+2))%MOD;
    ans=(ans+g3[min(n,m)])%MOD;

//    for(int side=1;side<=min(n,m);side++){
//      ans+=(side*(side-1)*(2*side-1)/3)*side*side;
//      ans-=(side*side-2*side)*side*side;

//      ans-=(side*(side-1)*(2*side-1)/3)*side*(n+m+2);
//      ans+=(side*side-2*side)*side*(n+m+2);

//      ans+=(side*(side-1)*(2*side-1)/3)*(n+1)*(m+1);
//      ans-=(side*side-2*side)*(n+1)*(m+1);

//      ans-=(side*side-2*side)*(n+1-side)*(m+1-side);
//      ans+=(side*(side-1)*(2*side-1)/3)*(n+1-side)*(m+1-side);
      
  //    ans+=g[side]%MOD*(n+1-side)%MOD*(m+1-side)%MOD;
      //for(int x=1;x<side;x++)ans+=2*__gcd(x,side)*(n+1-side)*(m+1-side)%MOD;
    //}
    ans=(ans%MOD+MOD)%MOD;
//    ans%=MOD;
    printf("%d\n",(int)ans);
  }
  return 0;
}