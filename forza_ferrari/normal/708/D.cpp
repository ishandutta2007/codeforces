#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
struct edge
{
	int nxt,to,weight,val;
}e[100001<<2];
int tot=1,n,m,ans,dep[1001],s,t,h[1001],cur[1001],d[1001];
bool vis[1001];
inline void add(int x,int y,int w,int val)
{
	//cout<<x<<" "<<y<<" "<<w<<" "<<val<<'\n';
	e[++tot]={h[x],y,w,val};
	h[x]=tot;
}
inline bool SPFA()
{
	for(int i=0;i<=t;++i)
	{
		dep[i]=0x3f3f3f3f;
		vis[i]=0;
		cur[i]=h[i];
	}
	queue<int> q;
	q.emplace(s);
	dep[s]=0;
	while(!q.empty())
	{
		int k=q.front();
		q.pop();
		vis[k]=0;
		for(int i=h[k];i;i=e[i].nxt)
			if(e[i].weight&&dep[e[i].to]>dep[k]+e[i].val)
			{
				dep[e[i].to]=dep[k]+e[i].val;
				if(!vis[e[i].to])
				{
					vis[e[i].to]=1;
					q.emplace(e[i].to);
				}
			}
	}
	return dep[t]^dep[0];
}
inline int dfs(int k,int f)
{
	if(k==t)
		return f;
	int r=0,used=0;
	vis[k]=1;
	for(int i=cur[k];i;i=e[i].nxt)
	{
		cur[k]=i;
		if((!vis[e[i].to]||e[i].to==t)&&e[i].weight&&dep[e[i].to]==dep[k]+e[i].val)
			if((r=dfs(e[i].to,min(e[i].weight,f-used))))
			{
				e[i].weight-=r;
				e[i^1].weight+=r;
				used+=r;
				ans+=r*e[i].val;
				if(f==used)
					break;
			}
	}
	return used;
}
inline void dinic()
{
	while(SPFA())
	{
		vis[t]=1;
		while(vis[t])
		{
			memset(vis,0,sizeof vis);
			dfs(s,1<<30);
		}
	}
}
int main()
{
	cin>>n>>m;
	s=n+1,t=s+1;
	for(int i=1;i<=m;++i)
	{
		int x,y,c,f;
		cin>>x>>y>>c>>f;
		d[x]-=f;
		d[y]+=f;
		if(c<f)
		{
			ans+=f-c;
			add(y,x,c,1);
			add(x,y,0,-1);
			add(y,x,f-c,0);
			add(x,y,0,0);
			add(x,y,1<<30,2);
			add(y,x,0,-2);
		}
		else
		{
			add(y,x,f,1);
			add(x,y,0,-1);
			add(x,y,c-f,1);
			add(y,x,0,-1);
			add(x,y,1<<30,2);
			add(y,x,0,-2);
		}
	}
	add(n,1,1<<30,0);
	add(1,n,0,0);
	for(int i=1;i<=n;++i)
		if(d[i]>0)
		{
			add(s,i,d[i],0);
			add(i,s,0,0);
		}
		else if(d[i]<0)
		{
			add(i,t,-d[i],0);
			add(t,i,0,0);
		}
	dinic();
	cout<<ans<<'\n';
	return 0;
}