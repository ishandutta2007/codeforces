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
int n;
int64 s,t[20];
const int MOD=1000000000+7;
long long power(long long x,long long k,long long mod){
  long long ans=1;
  while(k){
    if(k%2)ans=ans*x%MOD;
    x=x*x%MOD;
    k/=2;
  }
  return ans;
}
int main(){
  cin>>n>>s;
  for(int i=0;i<n;i++)cin>>t[i];
  int ans=0;
  long long inv=1;
  for(int i=1;i<=n-1;i++)inv=inv*i%MOD;
  inv=power(inv,MOD-2,MOD);
  for(int take=0;take<(1<<n);take++){
    long long cnt=__builtin_popcount(take)%2?MOD-1:1;
    long long left=s;
    for(int i=0;i<n;i++)if(take&1<<i)left-=t[i]+1;
    if(left<0)continue;
    long long tmp=cnt;
    for(int i=0;i<n-1;i++)tmp=(left+n-1-i)%MOD*tmp%MOD;
    tmp=tmp*inv%MOD;
    ans=(ans+tmp)%MOD;
  }
  printf("%d\n",ans);
  return 0;
}