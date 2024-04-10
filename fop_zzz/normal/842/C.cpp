#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<algorithm>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
int poi[500001],nxt[500001],head[500001],cnt,tot[500001],f[500001],g[500001];
int n,a[500001];
inline int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;}
inline void Dfs(int x,int fa,int dep)
{
	for(int i=1;i*i<=a[x];++i)
	{
		if(a[x]%i)	continue;
		tot[i]++;if(tot[i]>=dep-1)	g[x]=max(g[x],i);
		if(i*i!=a[x])	{tot[a[x]/i]++;if(tot[a[x]/i]>=dep-1)	g[x]=max(g[x],a[x]/i);}
	}
	g[x]=max(f[fa],g[x]),f[x]=gcd(f[fa],a[x]);
	for(int i=head[x];i;i=nxt[i])	if(poi[i]!=fa)	Dfs(poi[i],x,dep+1);
	for(int i=1;i*i<=a[x];++i)
	{
		if(a[x]%i)	continue;
		tot[i]--;if(i*i!=a[x])	tot[a[x]/i]--;
	}
}
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n-1)	add(read(),read());
	f[0]=g[0]=a[1];
	Dfs(1,1,1);
	For(i,1,n)	printf("%d ",max(f[i],g[i]));
}