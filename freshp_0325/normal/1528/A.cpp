#include<bits/stdc++.h>
using namespace std;
//typedef long long LL;
vector<int> G[100005];
int n,T,l[100005],r[100005];
long long dp[100005][2];
int Abs(int x){return x>0?x:-x;}
void dfs(int now,int pre)
{
	for(unsigned int i=0;i<G[now].size();++i)
	{
		int to=G[now][i];
		if(to==pre)	continue;
		dfs(to,now);
		dp[now][0]+=max(Abs(l[now]-l[to])+dp[to][0],Abs(l[now]-r[to])+dp[to][1]);
		dp[now][1]+=max(Abs(r[now]-l[to])+dp[to][0],Abs(r[now]-r[to])+dp[to][1]);
	}
}
int main(){
	scanf("%d",&T);
	while(T-->0)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	scanf("%d %d",&l[i],&r[i]),G[i].clear(),dp[i][0]=dp[i][1]=0;
		for(int i=1;i<n;++i)
		{
			int u,v;
			scanf("%d %d",&u,&v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,0);
		printf("%lld\n",max(dp[1][0],dp[1][1]));
	}
	return 0; 
}