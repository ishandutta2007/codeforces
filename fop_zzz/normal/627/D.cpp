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
int poi[500001],nxt[500001],head[500001],cnt,sz[500001],f[500001],dp[500001],a[500001],mx,k,n,can;
bool bj[500001];
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void dfs1(int x,int fa)
{
	sz[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		dfs1(poi[i],x);
		sz[x]+=sz[poi[i]];
	}
}
inline void dfs2(int x,int fa)
{
	if(mx>=k)	return;
	int mx0=0,mx1=0,mx2=0;
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		int to=poi[i];
		dfs2(to,x);
		f[x]+=f[to];
		if(dp[to]==sz[to])
			mx0+=dp[to];
			else	
				if(dp[to]>mx1)	mx2=mx1,mx1=dp[to];else	if(dp[to]>mx2)	mx2=dp[to];
	}
	if(!bj[x])	dp[x]=0;else	dp[x]=mx1+mx0+1,f[x]++;
	if(n-sz[x]==can-f[x])	mx0+=n-sz[x];
	if(bj[x])	mx=max(mx,mx0+mx1+mx2+1);
}
inline bool check(int x)
{
	can=0;
	For(i,1,n)	if(a[i]>=x)	bj[i]=1,can++;else	bj[i]=0;
	For(i,1,n)	f[i]=dp[i]=0;
	mx=0;
	dfs2(1,1);
	if(mx>=k)	return 1;
	return 0;
}
int x,y,ans;
int main()
{
	n=read();k=read();
	int l=0,r=0;
	For(i,1,n)	a[i]=read(),r=max(r,a[i]);
	For(i,1,n-1)	x=read(),y=read(),add(x,y),add(y,x);
	dfs1(1,1);
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))	ans=mid,l=mid+1;else	r=mid-1;
	}
	cout<<ans<<endl;
}