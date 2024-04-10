#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
long long n,m,a[444],l,r,p,c,dp[444][444],pos,ans;
vector<pair<long long,long long> > que[444][444];
int main()
{
	scanf("%lld%lld",&n,&m);
	for (long long i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}	
	for (long long i=1;i<=m;i++)
	{
		scanf("%lld%lld%lld%lld",&l,&r,&c,&p);
		que[l][r].push_back(make_pair(c,p)); 
	}
	for (long long i=1;i<=n;i++)
	{
		for (long long j=i+1;j<=n;j++)
		{
			dp[j][1]=a[j]-a[i];pos=i;
			for (long long k=2;k<=n+1;k++)
			{
				while(pos<j && max(dp[pos][k-1],a[j]-a[pos])>max(dp[pos+1][k-1],a[j]-a[pos+1])) pos++;
				dp[j][k]=max(dp[pos][k-1],a[j]-a[pos]);
			}
			for (long long k=0;k<que[i][j].size();k++)
			{
				ans=max(ans,dp[j][que[i][j][k].second+1]*que[i][j][k].first);
			}
			//cout<<dp[5][1]<<" "<<dp[5][2]<<" "<<dp[5][3]<<" "<<dp[5][4]<<" "<<dp[5][5]<<" "<<dp[5][6]<<" "<<dp[5][7]<<endl;
		}
	}
	printf("%lld\n",ans);
	return 0;
}