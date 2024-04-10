//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,dp1[200111],dp2[200111],sz[200111];
vector<int>con[200111];
void dfs(int x,int pre,int dis)
{
	for(int i=0;i<con[x].size();i++)
		if(pre!=con[x][i])
			dfs(con[x][i],x,dis+1);
	if(con[x].size()==0)
	{
		dp1[x]=dp2[x]=sz[x]=1;
		return;
	}
	for(int i=0;i<con[x].size();i++)
		if(pre!=con[x][i])
			sz[x]+=sz[con[x][i]];	
	if(dis&1)
	{
		for(int i=0;i<con[x].size();i++)
			if(pre!=con[x][i])
				dp1[x]=max(dp1[x],sz[x]-(sz[con[x][i]]-dp1[con[x][i]])),dp2[x]+=dp2[con[x][i]];
	}
	else
	{
		dp1[x]=1;dp2[x]=n+1;
		for(int i=0;i<con[x].size();i++)
			if(pre!=con[x][i])
				dp2[x]=min(dp2[x],dp2[con[x][i]]),dp1[x]+=dp1[con[x][i]]-1;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	int x,y;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		con[x].PB(y);
	}
	dfs(1,-1,1);
	/*
	for(int i=1;i<=n;i++)
	{
		cout<<dp1[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<dp2[i]<<" ";
	}
	cout<<endl;
	*/
	cout<<dp1[1]<<" "<<dp2[1]<<endl;
	return 0;
}