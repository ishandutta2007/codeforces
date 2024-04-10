#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=2E5+1;
int read()
{
	int a=0;char b=1,c;
	do if((c=getchar())==45)b=-1;while(!(c&16));
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16);
	return a*b;
}
void write(int x)
{
	if(x<0)putchar('-'),x=-x;
	char a[10],s=0;
	do a[s++]=x%10|48;while(x/=10);
	do putchar(a[--s]);while(s);
}
int head[N],nex[N<<1],to[N<<1],low[N],cnt,k;
void dfs(int f,int x)
{
	low[x]=++cnt;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(!low[t])dfs(x,t);
		if(t!=f&&low[t]<low[x])k=low[x]=low[t];
	}
}
int gets(int f,int x)
{
	int s=1;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(t!=f&&low[t]!=k)s+=gets(x,t);
	}
	return s;
}
int main()
{
	for(int x=read();x--;)
	{
		int n=read();
		for(int i=1;i<=n;++i)head[i]=low[i]=0;
		for(int i=1,u,v;i<=n;++i)nex[i<<1]=head[u=read()],to[head[u]=i<<1]=v=read(),nex[i<<1|1]=head[v],to[head[v]=i<<1|1]=u;
		cnt=0,dfs(0,1);
		ll ans=n*1ll*(n-1);
		for(int i=1,s;i<=n;++i)if(low[i]==k)s=gets(0,i),ans-=s*1ll*(s-1)>>1;
		printf("%lld\n",ans);
	}
	return 0;
}