#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int ch[N][26],a[N],v[N],dp[N],sz[N],n,m;
void dfs(int i,int x)
{
	if(v[i])
	{
		sz[i]=1;
		dp[i]=min(dp[i],x+1);
	}
	for(int j=0;j<26;j++)
	{
		if(ch[i][j])
		{
			dp[ch[i][j]]=dp[i]+1;
			dfs(ch[i][j],min(dp[i],x)+sz[i]);
			sz[i]+=sz[ch[i][j]];
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int u;
		char v;
		cin>>u>>v;
		ch[u][v-'a']=i;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		v[a[i]]=1;
	}
	dfs(0,0);
	for(int i=1;i<=m;i++)
		cout<<dp[a[i]]<<' ';
	return 0;
}