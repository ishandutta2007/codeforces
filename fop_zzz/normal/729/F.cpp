#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define For(i,j,k) for(int i=j;i<=k;++i)
#define Dow(i,j,k) for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
#define pb push_back
#define VI vector<int>
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
    while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
    return t*f;
}
int ys=100,n,a[20001],sum[20001],ans,dp[2300][201][101][2];
bool vis[2100][201][101][2];
inline int dfs(int l,int r,int now,int k)
{
	int tmp=ys+l+r-n;
	if(vis[l][tmp][k][now])	return dp[l][tmp][k][now];
	vis[l][tmp][k][now]=1;
	if(now==1)
	{
		int t1=-inf,t2=-inf;
		if(l+k-1==r)	return dp[l][tmp][k][now]=(sum[r]-sum[l-1]);
		if(l+k-1>r)	return dp[l][tmp][k][now]=0;
		t1=dfs(l+k,r,now^1,k)+(sum[l+k-1]-sum[l-1]);
		t2=dfs(l+k+1,r,now^1,k+1)+(sum[l+k]-sum[l-1]);
		return dp[l][tmp][k][now]=max(t1,t2);
	}else
	{
		int t1=inf,t2=inf;
		if(l+k-1==r)	return dp[l][tmp][k][now]=-(sum[r]-sum[l-1]);
		if(l+k-1>r)	return dp[l][tmp][k][now]=0;
		t1=dfs(l,r-k,now^1,k)-(sum[r]-sum[r-k]);
		t2=dfs(l,r-k-1,now^1,k+1)-(sum[r]-sum[r-k-1]);
		return dp[l][tmp][k][now]=min(t1,t2);
	}
}
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)	sum[i]=sum[i-1]+a[i];
	int ans=dfs(1,n,1,1);
	cout<<ans<<endl;
}