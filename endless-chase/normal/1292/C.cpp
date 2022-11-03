#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,x[6666],y[6666],cnt,sub[6666],crt,ctt;
long long dp[6666][6666],ans;
int head[3333],to[6666],nxt[6666],id[6666];
void addedge(int x,int y,int i)
{
	++ctt;to[ctt]=y;id[ctt]=i;
	nxt[ctt]=head[x];head[x]=ctt;
}
void dft(int i,int fa)
{
	crt++;
	for (int j=head[i];j;j=nxt[j])
	{
		if (to[j]!=fa) dft(to[j],i);
	}
}
void dfs(int i,int j)
{
	if (dp[i][j]!=-1) return;
	dp[i][j]=0;
	for (int k=head[x[i]];k;k=nxt[k])
	{
		if (to[k]==y[i]) continue;
		dfs(id[k],j);
		dp[i][j]=max(dp[i][j],dp[id[k]][j]);
	}
	for (int k=head[x[j]];k;k=nxt[k])
	{
		if (to[k]==y[j]) continue;
		dfs(i,id[k]);
		dp[i][j]=max(dp[i][j],dp[i][id[k]]);
	}
	dp[i][j]+=(1ll*sub[i]*sub[j]);
}
int main()
{
	scanf("%d",&n);cnt=1;
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x[cnt],&y[cnt]);
		cnt++;
		x[cnt]=y[cnt-1];y[cnt]=x[cnt-1];
		addedge(x[cnt],y[cnt],cnt-1);
		addedge(y[cnt],x[cnt],cnt);
		cnt++;
	}
	cnt--;
	for (int i=1;i<=cnt;i++)
	{
		for (int j=1;j<=cnt;j++)
		dp[i][j]=-1;
	}
	for (int i=1;i<=cnt;i++)
	{
		crt=0;
		dft(x[i],y[i]);
		sub[i]=crt;
	}
	for (int i=2;i<=cnt;i+=2)
	{
		if (dp[i][i-1]==-1) dfs(i,i-1);
		ans=max(ans,dp[i][i-1]);
	}
	printf("%lld\n",ans);
	return Accepted;
}