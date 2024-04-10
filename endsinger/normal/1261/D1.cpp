#include<bits/stdc++.h>
using namespace std;
const int N=2005,mod=998244353,base=2000;
int dp[N][N*2],a[N],n,k;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	if(k==1)
	{
		puts("0");
		return 0;
	}
	dp[0][base]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=base-i;j<=base+i;j++)
		{
			if(a[i]==a[i%n+1])
				dp[i][j]=(long long)dp[i-1][j]*k%mod;
			else
			{
				dp[i][j]=((dp[i-1][j-1]+dp[i-1][j+1])%mod+(long long)dp[i-1][j]*(k-2)%mod)%mod;		
			}		
		} 
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+dp[n][base+i])%mod;
	printf("%d\n",ans);
	return 0;
}