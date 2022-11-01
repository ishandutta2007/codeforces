#pragma comment(linker, "/stack:200000000")
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

const int N=4e5+5;
int poi[N],nxt[N],head[N],cnt,dis[N],siz[N],n;
ll ans;
inline void add(int x,int y)
{
	poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
	poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;
}

inline void Dfs(int x,int fa)
{
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i])	
		if(poi[i]!=fa)
		{
			Dfs(poi[i],x);
			siz[x]+=siz[poi[i]];
		}
}
inline void Dfss(int x,int fa,ll now)
{
	ans=max(ans,now);
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		Dfss(poi[i],x,now+n-2*siz[poi[i]]);
	}
}
int main()
{
	n=read();
	For(i,1,n-1)	add(read(),read());
	Dfs(1,1);
	ll now=0;
	For(i,1,n)	now+=siz[i];
	Dfss(1,1,now);
	writeln(ans);
}