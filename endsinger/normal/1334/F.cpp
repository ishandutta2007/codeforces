#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500005,inf=(1LL<<62)-1;
int a[N],b[N],p[N],dp[N],n,m,ans,fl=1;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
		dp[i]=inf;
	for(int i=1;i<=n;i++)
	{
		int k=lower_bound(b,b+m+1,a[i])-b;
		if(k<=m)
			dp[k]+=min(p[i],0LL);
		if(k<=m&&a[i]==b[k])
		{
			if(dp[k]>0)
			{
				if(k+1<=m)
					dp[k+1]+=dp[k];
				dp[k]=0;
			}
		}
		dp[0]+=p[i];
		if(k<=m)
			dp[k]-=p[i];
		if(k<=m&&dp[k]>inf/2)
			dp[k]=inf;
		if(k+1<=m&&dp[k+1]>inf/2)
			dp[k+1]=inf;
	}
	for(int i=0;i<=m;i++)
	{
		if(dp[i]==inf)
		{
			fl=0;
			break;
		}
		ans+=dp[i];
	}
	if(fl)
		cout<<"YES"<<endl<<ans<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}