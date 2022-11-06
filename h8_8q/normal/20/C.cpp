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

const LL N=1e5+5;
LL n,m,dis[N],vis[N],pre[N];

struct Edge
{
	LL v,w,ne;
}e[N*2];
LL head[N],tot;

struct Node
{
	LL u,w;
	bool operator < (const Node &x)const
	{
		return x.w<w;
	}
};

inline void add(LL u,LL v,LL w);
inline void dij(LL st);
void print(LL x);

int main()
{
	n=read();m=read();
	for(LL i=1;i<=m;++i)
	{
		LL u=read(),v=read(),w=read();
		add(u,v,w);
		add(v,u,w);
	}
	dij(1);
	if(pre[n]==-1)
		printf("-1");
	else
		print(n);
	return 0;
}

inline void add(LL u,LL v,LL w)
{
	e[++tot]=(Edge){v,w,head[u]};
	head[u]=tot;
}

inline void dij(LL st)
{
	memset(dis,0x3f,sizeof(dis));
	memset(pre,-1,sizeof(pre));
	priority_queue<Node> qu;
	qu.push((Node){st,0});
	dis[st]=0;
	while(!qu.empty())
	{
		LL u=qu.top().u;
		qu.pop();
		if(vis[u])
			continue;
		vis[u]=1;
		for(LL i=head[u];i;i=e[i].ne)
		{
			LL v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				pre[v]=u;
				if(!vis[v])
					qu.push((Node){v,dis[v]});
			}
		}
	}
}

void print(LL x)
{
	if(x==-1)
		return;
	print(pre[x]);
	printf("%lld ",x);
}