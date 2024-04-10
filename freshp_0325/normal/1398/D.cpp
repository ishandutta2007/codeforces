#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
/*
 f[i][j][k]  i  j  k 
*/
LL dp[205][205][205],a[205],b[205],c[205],suma[205],sumb[205],sumc[205];
int main(){
	LL r,B,g;
	scanf("%lld %lld %lld",&r,&B,&g);
	for(LL i=1;i<=r;++i)	scanf("%lld",&a[i]);
	for(LL i=1;i<=B;++i)	scanf("%lld",&b[i]);
	for(LL i=1;i<=g;++i)	scanf("%lld",&c[i]);
	sort(a+1,a+1+r,greater<LL>());
	sort(b+1,b+1+B,greater<LL>());
	sort(c+1,c+1+g,greater<LL>());
	LL ans=0;
	for(LL i=0;i<=r;++i)
	{
		for(LL j=0;j<=B;++j)
		{
			for(LL k=0;k<=g;++k)
			{
				if(i && j && k)	dp[i][j][k]=max(dp[i-1][j-1][k]+a[i]*b[j],max(dp[i-1][j][k-1]+a[i]*c[k],dp[i][j-1][k-1]+b[j]*c[k]));
				else if(i && j)	dp[i][j][k]=dp[i-1][j-1][k]+a[i]*b[j];
				else if(i && k)	dp[i][j][k]=dp[i-1][j][k-1]+a[i]*c[k];
				else if(j && k)	dp[i][j][k]=dp[i][j-1][k-1]+b[j]*c[k];
				ans=max(ans,dp[i][j][k]);
//				printf("dp[%lld][%lld][%lld]=%lld\n",i,j,k,dp[i][j][k]);
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
10 1 1
11 7 20 15 19 14 2 4 13 14
8
11

*/