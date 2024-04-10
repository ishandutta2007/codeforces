#include <cstdio>
#define mod 1000000007
long long dp[10000005];
int n;
int main(){
long long a=1,b=1,c=1;
dp[1]=0;
  for(int i=2;i<=10000000;i++){
    dp[i]=(a+b+c)%mod;
    long long d=(dp[i-1]+b+c)%mod;
    long long e=(dp[i-1]+a+c)%mod;
    long long f=(dp[i-1]+b+a)%mod;
	a=d; b=e; c=f;
  }
  scanf("%d\n",&n);
  printf("%lld\n",dp[n]);
  return 0;
}