#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,Q,cnt;
vector<int> v[333333],g[333333];
int h[11111111],rig[11111111],lef[11111111];
long long val[11111111],dp[11111111];
deque<pair<int,int> > q;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for (int j=1;j<=x;j++)
		{
			scanf("%d",&y);
			v[i].push_back(y);
		}
		for (int j=1;j<=x;j++)
		{
			scanf("%d",&y);
			g[i].push_back(y);
		}
	}
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++)
	{
		scanf("%d%d",&x,&y);
		for (int j=0;j<v[x].size();j++)
		{
			h[++cnt]=v[x][j];
			val[cnt]=1ll*y*g[x][j];
		}			
	}
	for (int i=1;i<=m;i++)
	{
		while(!q.empty() && q.back().second>=i-h[i]+1) q.pop_back();
		if (!q.empty() && q.back().first>=i-h[i]+1) lef[i]=lef[q.back().first];
		else lef[i]=max(1,i-h[i]+1);
		q.push_back(make_pair(i,i-h[i]+1)); 
	}
	q.clear();
	for (int i=m;i>=1;i--)
	{
		while(!q.empty() && q.back().second<=i+h[i]-1) q.pop_back();
		if (!q.empty() && q.back().first<=i+h[i]-1) rig[i]=rig[q.back().first];
		else rig[i]=min(m,i+h[i]-1);
		q.push_back(make_pair(i,i+h[i]-1)); 
	}
	q.clear();
	for (int i=1;i<=m;i++)
	{
		dp[i]=dp[lef[i]-1]+val[i];
		while(!q.empty() && q.back().first<i) q.pop_back();
		if (!q.empty()) dp[i]=min(dp[i],dp[q.back().second-1]+val[q.back().second]);
		while(!q.empty() && q.back().first<=rig[i] && dp[q.back().second-1]+val[q.back().second]>=dp[i-1]+val[i]) q.pop_back();
		if (!q.empty() && rig[i]<=q.back().first && dp[q.back().second-1]+val[q.back().second]<=dp[i-1]+val[i]);
		else q.push_back(make_pair(rig[i],i)); 
	}
	printf("%lld\n",dp[m]);
	return 0;
}