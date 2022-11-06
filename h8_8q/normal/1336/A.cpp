#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<map>
#include<set>
#define LL long long

using namespace std;

LL read()
{
	LL ans=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){ans=ans*10+c-'0';c=getchar();}
	return ans*f;
}

const LL N=1e6+5;
LL n,k,is[N],sum[N],ans;

struct Edge
{
	LL v,ne;
}e[N];
LL head[N],tot;

struct Node
{
	LL dep,x,siz;
	bool operator < (const Node &x)const
	{
		return ((x.dep-1)*x.siz-x.dep*(x.siz-1))<((dep-1)*siz-dep*(siz-1));
	}
}node[N];

inline void add(LL u,LL v);
void dfs1(LL u,LL fa);
void dfs2(LL u,LL fa);

int main()
{
	n=read();k=read();
	for(LL i=1;i<=n-1;++i)
	{
		LL u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs1(1,0);
	sort(node+1,node+1+n);
	for(LL i=1;i<=k;++i)
		is[node[i].x]=1;
	dfs2(1,0);
	printf("%lld",ans);
	return 0;
}

inline void add(LL u,LL v)
{
	e[++tot]=(Edge){v,head[u]};
	head[u]=tot;
}

void dfs1(LL u,LL fa)
{
	node[u].dep=node[fa].dep+1;
	node[u].siz=1;
	node[u].x=u;
	for(LL i=head[u];i;i=e[i].ne)
	{
		LL v=e[i].v;
		if(v==fa)
			continue;
		dfs1(v,u);
		node[u].siz+=node[v].siz;
	}
}

void dfs2(LL u,LL fa)
{
	if(!is[u])
		sum[u]++;
	else
		ans+=sum[u];
	for(LL i=head[u];i;i=e[i].ne)
	{
		LL v=e[i].v;
		if(v==fa)
			continue;
		sum[v]=sum[u];
		dfs2(v,u);
	}
}