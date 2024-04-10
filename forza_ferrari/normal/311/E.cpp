#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
struct edge
{
	int nxt,to,weight;
}e[10000001<<1];
int n,m,g,tot=1,sum,s,t,h[100005],dep[100005],cur[100005],a[100005],p[100005],ans;
bool vis[100005];
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
	return dep[t]!=dep[0];
}
int dfs(int k,int f)
{
	int r=0;
	if(k==t)
	{
		ans+=f;
		return f;
	}
	int used=0;
	for(register int i=cur[k];i;i=e[i].nxt)
	{
		cur[k]=i;
		if(e[i].weight&&dep[e[i].to]==dep[k]+1)
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
		dfs(s,1<<30);
	return ans;
}
int main()
{
	scanf("%d%d%d",&n,&m,&g);
	s=n+m+1;
	t=s+1;
	for(register int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(register int i=1;i<=n;++i)
	{
		scanf("%d",&p[i]);
		if(a[i])
		{
			add(i,t,p[i]);
			add(t,i,0);
		}
		else
		{
			add(s,i,p[i]);
			add(i,s,0);
		}
	}
	for(register int i=1;i<=m;++i)
	{
		int opt,w,cnt;
		scanf("%d%d%d",&opt,&w,&cnt);
		sum+=w;
		if(opt)
		{
			while(cnt--)
			{
				int k;
				scanf("%d",&k);
				add(k,i+n,1<<30);
				add(i+n,k,0);
			}
			scanf("%d",&opt);
			if(opt)
			{
				add(i+n,t,g+w);
				add(t,i+n,0);
			}
			else
			{
				add(i+n,t,w);
				add(t,i+n,0);
			}
		}
		else
		{
			while(cnt--)
			{
				int k;
				scanf("%d",&k);
				add(i+n,k,1<<30);
				add(k,i+n,0);
			}
			scanf("%d",&opt);
			if(opt)
			{
				add(s,i+n,g+w);
				add(i+n,s,0);
			}
			else
			{
				add(s,i+n,w);
				add(i+n,s,0);
			}
		}
	}
	printf("%d\n",sum-dinic());
	return 0;
}