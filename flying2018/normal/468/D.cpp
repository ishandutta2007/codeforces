#include<cstdio>
#include<cstring>
#include<set> 
#define N 100010
#define P pair<int,int>
#define MP make_pair
#define fi first
#define se second
#define ll long long
using namespace std;
int nxt[N<<1],to[N<<1],w[N<<1],head[N],cnt;
void add(int u,int v,int w)
{
	nxt[++cnt]=head[u];
	to[cnt]=v;
	::w[cnt]=w;
	head[u]=cnt;
}
int n,m,siz[N],rt[N],maxn[N],fa[N],sum[N],root;
void dfs(int u,int pre)
{
	siz[u]=1;
	maxn[u]=0;
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==pre) continue;
		dfs(v,u);
		maxn[u]=max(maxn[u],siz[v]);
		siz[u]+=siz[v];
	}
	maxn[u]=max(maxn[u],n-siz[u]);
	if(!root || maxn[u]<maxn[root]) root=u;
}
ll dis[N],ans;
void dfs(int u)
{
	ans+=dis[u];
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[u]) continue;
		fa[v]=u;
		dis[v]=dis[u]+w[i];
		dfs(v);
	}
}
set<int>sm,in[N];
set<P >s;
void work(int u,int root)
{
	rt[u]=root;
	in[root].insert(u);
	for(int i=head[u];i;i=nxt[i])
	{
		int v=to[i];
		if(v==fa[u]) continue;
		work(v,root);
	}
}
void merge(int x,int y)
{
	int rx=rt[x],ry=rt[y];
	sm.erase(y);
	if(rx) s.erase(MP(sum[rx],rx)),s.insert(MP(--sum[rx],rx));
	if(ry)
	{
		in[ry].erase(y);
		if(!in[ry].empty()) sm.insert(*in[ry].begin());
		s.erase(MP(sum[ry],ry)),s.insert(MP(--sum[ry],ry));
	}
}
int solve(int x)
{
	int res=0;
	if(s.rbegin()->fi==n-x+1 && s.rbegin()->se!=rt[x]) res=*in[s.rbegin()->se].begin();
	else if(rt[*sm.begin()]!=rt[x] || x==root) res=*sm.begin();
	else res=*next(sm.begin());
	merge(x,res);
	return res;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0);
	dfs(root);
	printf("%lld\n",ans*2);
	if(n==1){puts("1");return 0;}
	
	sm.insert(root);
	for(int i=head[root];i;i=nxt[i])
	{
		int v=to[i];
		work(v,v);
		sm.insert(*in[v].begin());
		sum[v]=in[v].size()*2;
		s.insert(MP(sum[v],v));
	}
	for(int i=1;i<=n;i++) printf("%d ",solve(i));
	return 0;
}