//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,m,S;
int head[200111],to[600111],nxt[600111],cost[600111],tot=1;
ll dis[200111];
bool vis[200111];
set<pair<ll,int> >st;
int ord[200111],ordn,lv[200111];
void dijkstra()
{
	st.insert(MP(0,S));
	memset(dis,-1,sizeof(dis));
	dis[S]=0;
	while(st.size()>0)
	{
		int u=st.begin()->SS;
		st.erase(st.begin());
		if(vis[u])continue;
		vis[u]=1;
		ord[ordn++]=u;
		for(int i=head[u];i;i=nxt[i])
		{
			if(dis[to[i]]==-1||dis[to[i]]>dis[u]+cost[i])
			{
				dis[to[i]]=dis[u]+cost[i];
				st.insert(MP(dis[to[i]],to[i]));
			}
		}
	}
}
int p[20][200111];
int newnode(int x,int f)
{
	p[0][x]=f;
	for(int i=1;i<20;i++)
	{
		if(p[i-1][x]==-1)p[i][x]=-1;
		else p[i][x]=p[i-1][p[i-1][x]];
	}
	lv[x]=lv[f]+1;
}
int getlca(int x,int y)
{
	if(lv[x]<lv[y])swap(x,y);
	for(int i=19;i>=0;i--)
	{
		if(lv[x]-lv[y]>=(1<<i))
		{
			x=p[i][x];
		}
	}
	if(x==y)return x;
	for(int i=19;i>=0;i--)
	{
		if(p[i][x]!=p[i][y])
		{
			x=p[i][x];
			y=p[i][y];
		}
	}
	return p[0][x];
}
int ans;
int sz[200111];
int main()
{
	scanf("%d%d%d",&n,&m,&S);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		nxt[++tot]=head[x];
		head[x]=tot;
		to[tot]=y;
		cost[tot]=w;
		nxt[++tot]=head[y];
		head[y]=tot;
		to[tot]=x;
		cost[tot]=w;
	}
	dijkstra();
	for(int i=0;i<20;i++)p[i][S]=-1;
	for(int i=1;i<ordn;i++)
	{
		int x=ord[i],pre=-1;
		for(int j=head[x];j;j=nxt[j])
		{
			int u=to[j];
			if(dis[u]+cost[j]==dis[x])
			{
				if(pre==-1)pre=u;
				else pre=getlca(u,pre);
			}
		}
		newnode(x,pre);
	}
	for(int i=ordn-1;i>0;i--)
	{
		int x=ord[i];
		sz[x]++;
		sz[p[0][x]]+=sz[x];
		ans=max(ans,sz[x]);
	}
	cout<<ans<<endl;
	return 0;
}