#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
#define int ll 
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=5e5+5;
int gc[N],tim,inq[N],bel[N],tot,n,m;
ll dep[N];
vector<pa> E[N];
int dfn[N],low[N],q[N],top,eu[N],ev[N],ew[N];
inline void Tar(int x)
{
	dfn[x]=low[x]=++tim;q[++top]=x;inq[x]=1;
	for(auto u:E[x])
	{
		if(!dfn[u.fir])	Tar(u.fir),low[x]=min(low[x],low[u.fir]);
		else	if(inq[u.fir])	low[x]=min(low[x],low[u.fir]);
	}
	if(dfn[x]==low[x])
	{
		++tot;
		for(;q[top+1]!=x;top--)
			bel[q[top]]=tot,inq[q[top]]=0;
	}
}
bool vis[N];
inline void Dfs(int x,int fa)
{
	vis[x]=1;
	for(auto u:E[x])
	{
		if(vis[u.fir])	continue;
		if(bel[u.fir]!=bel[fa])	continue;
		dep[u.fir]=dep[x]+u.sec;
		Dfs(u.fir,x);
	}
}
inline void Solve(int rt)
{
	Dfs(rt,rt);
}
signed main()
{
	n=read();m=read();
	For(i,1,m)
	{
		int u=read(),v=read(),w=read();
		E[u].pb(mk(v,w));
		eu[i]=u;ev[i]=v;ew[i]=w;
	}
	For(i,1,n)
		if(!dfn[i])	Tar(i);
	
	For(i,1,n)
		if(!vis[i])	Dfs(i,i);
//	For(i,1,n)	cout<<bel[i]<<' '<<dep[i]<<"<="<<i<<endl;
	For(i,1,m)
	{
		if(bel[eu[i]]!=bel[ev[i]])	continue;
		if(dep[eu[i]]+ew[i]-dep[ev[i]]!=0)
		{
			int lop=abs(dep[eu[i]]+ew[i]-dep[ev[i]]);
			if(!gc[bel[eu[i]]])	gc[bel[eu[i]]]=lop;
			else	gc[bel[eu[i]]]=__gcd(gc[bel[eu[i]]],lop);
		}
	}
	int q=read();
	while(q--)
	{
		int pos=read(),s=read(),t=read();
		if(s==0)	{puts("YES");continue;}
		if(!gc[bel[pos]])	{puts("NO");continue;}
		int tmp=__gcd(gc[bel[pos]],t);
		if((t-s)%tmp==0)	puts("YES");else	puts("NO");
	}
}