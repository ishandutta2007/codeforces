#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
#define int long long
struct edge
{
	int nxt,to,weight;
}e[60005<<5];
int n,m,tot=1,s,t,h[60005],p[60005],dep[60005],cur[60005],ans,sum;
bool vis[60005];
inline void add(int x,int y,int w)
{
	e[++tot].nxt=h[x];
	h[x]=tot;
	e[tot].to=y;
	e[tot].weight=w;
}
inline bool bfs()
{
	queue<int> q;
	for(register int i=0;i<=t;++i)
	{
		vis[i]=0;
		cur[i]=h[i];
		dep[i]=0x3f3f3f3f;
	}
	q.push(s);
	dep[s]=0;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		vis[k]=0;
		for(register int i=h[k];i;i=e[i].nxt)
			if(e[i].weight&&dep[e[i].to]>dep[k]+1)
			{
				dep[e[i].to]=dep[k]+1;
				if(!vis[e[i].to])
				{
					vis[e[i].to]=1;
					q.push(e[i].to);
				}
			}
	}
	return dep[0]!=dep[t];
}
int dfs(int k,int f)
{
	int r=0;
	if(k==t)
	{
		vis[t]=1;
		ans+=f;
		return f;
	}
	int used=0;
	for(register int i=cur[k];i;i=e[i].nxt)
	{
		cur[k]=i;
		if((!vis[e[i].to]||e[i].to==t)&&e[i].weight&&dep[e[i].to]==dep[k]+1)
			if((r=dfs(e[i].to,min(e[i].weight,f-used))))
			{
				e[i].weight-=r;
				e[i^1].weight+=r;
				used+=r;
				if(f==used)
					break;
			}
	}
	return used;
}
inline int dinic()
{
	while(bfs())
		dfs(s,1ll<<50);
	return ans;
}
signed main()
{
	scanf("%lld%lld",&n,&m);
	s=n+m+1;
	t=s+1;
	for(register int i=1;i<=n;++i)
	{
		scanf("%lld",&p[i]);
		add(s,i,p[i]);
		add(i,s,0);
	}
	for(register int i=1;i<=m;++i)
	{
		int x,y,w;
		scanf("%lld%lld%lld",&x,&y,&w);
		sum+=w;
		add(i+n,t,w);
		add(t,i+n,0);
		add(x,i+n,1ll<<50);
		add(i+n,x,0);
		add(y,i+n,1ll<<50);
		add(i+n,y,0);
	}
	printf("%lld\n",sum-dinic());
	return 0;
}