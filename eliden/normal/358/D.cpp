#include <bits/stdc++.h>
using namespace std;
#define rep(a,b,c) for(int a=b;a<c;++a)
#define debug(x) cerr<<(#x)<<": "<<x<<endl
const int sz = 1e4;
int n, a[sz][3], dp[sz][2];
int main()
{
	scanf("%d",&n);
	for(int k=0;k<3;k++)
		rep(i,0,n)
			scanf("%d",&a[i][k]);
	if(n==1)
		printf("%d\n",a[0][0]);
	else
	{
		dp[0][0]=a[0][0];
		dp[0][1]=a[0][1];
		rep(i,1,n-1)
		{
			dp[i][0]=max(dp[i-1][1]+a[i][0],dp[i-1][0]+a[i][1]);
			dp[i][1]=max(dp[i-1][1]+a[i][1],dp[i-1][0]+a[i][2]);
		}
		printf("%d\n",max(dp[n-2][0]+a[n-1][1],dp[n-2][1]+a[n-1][0]));
	}
}