//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define sz(v) int(v.size())
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,T;
int dp[105][2011],sum[105][1011];
vector<int>lev[105];
int dfs(int l,int x)
{
	if(dp[l][x]!=-1)return dp[l][x];
	if(l==T)return dp[l][x]=0;
	for(int i=0;i<=x&&i<=lev[l].size();i++)
		dp[l][x]=max(dp[l][x],sum[l][i]+dfs(l+1,min(2000,(x-i)*2)));
	return dp[l][x];
}
int main()
{
	cin>>n>>T;
	int x,y;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y;
		lev[T-x].PB(-y);
	}
	for(int i=0;i<T;i++)sort(lev[i].begin(),lev[i].end());
	for(int i=0;i<T;i++)
		for(int j=0;j<lev[i].size();j++)
			sum[i][j+1]=sum[i][j]-lev[i][j];
	memset(dp,-1,sizeof(dp));
	cout<<dfs(0,1)<<endl;
	return 0;
}