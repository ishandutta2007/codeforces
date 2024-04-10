#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back


using namespace std;

inline ll read()
{
	ll t=0,dp=1;char c=getchar();
	while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
	while(isdigit(c))	t=t*10+c-48,c=getchar();
	return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
/*------------------------------------------------------------------------------------------------------*/
int cnt=1;
const int N=100005;
int head[N],up[N],dep[N],tree[N],sum[N],x[N],y[N],nxt[N*2],poi[N*2],ans[N],n,m,ans_num,vis[N];
int Fa[N];
inline void add(int x,int y)
{
	poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
	poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;
}
inline void Dfs(int x,int fa)
{	
	vis[x]=1;Fa[x]=fa;
	for(int i=head[x];i;i=nxt[i])
	{
		if(vis[poi[i]]||poi[i]==fa)	continue;
		up[poi[i]]=i/2;tree[i/2]=1;
		dep[poi[i]]=dep[x]+1;
		Dfs(poi[i],x);//cout<<poi[i]<<"=>"<<x<<' '<<up[poi[i]]<<endl;
	}
}
inline void Dfs1(int x,int fa)
{
	vis[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(vis[poi[i]]||poi[i]==fa)	continue;
		Dfs1(poi[i],x);
		sum[x]+=sum[poi[i]];
	}
}
int main()
{
	n=read();m=read();
	For(i,1,m)	x[i]=read(),y[i]=read(),add(x[i],y[i]);
	For(i,1,n)	if(!vis[i])	Dfs(i,i);
	For(i,1,m)	if(!tree[i])
	{
//		cout<<i<<endl;
		if(dep[x[i]]>dep[y[i]])	swap(x[i],y[i]);
		sum[x[i]]--;sum[y[i]]++;
	}
	memset(vis,0,sizeof vis);
	For(i,1,n)	if(!vis[i])	Dfs1(i,i);
	For(i,1,m)	if(!tree[i])
	{
		int tmp=y[i];
		bool ok=1;
		while(1)
		{
//			cout<<tmp<<' '<<sum[tmp]<<endl;
			if(sum[tmp]!=1)	{ok=0;break;}
			tmp=Fa[tmp];if(tmp==x[i])	break;
		}
		if(ok)	
		{
			int tmp=y[i];
			while(1)
			{
				ans[up[tmp]]=1;
				tmp=Fa[tmp];if(tmp==x[i])	break;
			}
			ans[i]=1;
		}
	}
	For(i,1,m)	if(ans[i])	ans_num++;
	writeln(ans_num);
	For(i,1,m)	if(ans[i])	write_p(i);
}