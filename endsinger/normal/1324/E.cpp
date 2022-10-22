#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int dp[N][N],n,a[N],h,l,r;
inline void upd(int &a,int b){if(a<b)a=b;}
inline int val(int v){return l<=v&&v<=r;}
int main()
{
	scanf("%d%d%d%d",&n,&h,&l,&r);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<h;j++)
		{
			if(dp[i][j]==-1)
				continue;
			upd(dp[i+1][(j+a[i+1]+h)%h],dp[i][j]+val((j+a[i+1])%h));
			upd(dp[i+1][(j+a[i+1]-1+h)%h],dp[i][j]+val((j+a[i+1]-1)%h));
		}
	}
	int ans=0;
	for(int j=0;j<h;j++)
		upd(ans,dp[n][j]);
	printf("%d\n",ans);
	return 0;
}