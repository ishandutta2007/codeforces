#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf=214748364721474ll/2;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
struct Edge{
	LL t,v;
	Edge(LL T=0,LL V=0){t=T,v=V;}
	bool operator < (Edge ano) const {return v>ano.v;}
};
struct edge{
	LL u,v,val;
	edge(){}
	edge(LL U,LL V,LL VAL){u=U,v=V,val=VAL;}
	bool operator < (edge ano) const {return val<ano.val;}
}ed[300005];
struct unionFindSet{
	LL fa[100005];
	void makeSet(LL up){for(LL i=0;i<=up;++i)	fa[i]=i;}
	LL findSet(LL x){return x==fa[x]?x:fa[x]=findSet(fa[x]);}
	bool unionSet(LL x,LL y)
	{
		LL xx=findSet(x),yy=findSet(y);
		if(xx==yy)	return false;
		fa[yy]=xx;
		return true;
	}
}ufs;
typedef Edge Point;
vector<Edge> G[100005];
LL n,m,k,q,dis[100005],cnt,lgs[100005],maxn[18][100005],fa[18][100005],dep[100005];
void Dijkstra(LL s,LL N)
{
	priority_queue<Point> Q;
	for(LL i=1;i<=N;++i)	dis[i]=inf;
	dis[s]=0;
	Q.push(Point(s,0));
	LL pst=0;
	while(!Q.empty())
	{
		++pst;
		LL now=Q.top().t,v=Q.top().v;
		Q.pop();
		if(v>dis[now])	continue;
		for(auto st:G[now])
		{
			LL to=st.t,val=st.v;
			if(dis[to]>dis[now]+val)	Q.push(Point(to,dis[to]=dis[now]+val));
		}
	}
}
void Kruskal()
{
	ufs.makeSet(n);
	sort(ed+1,ed+1+m);
	for(LL i=1;i<=m;++i)
	{
		LL u=ed[i].u,v=ed[i].v,val=ed[i].val;
		if(ufs.unionSet(u,v))	G[u].push_back(Edge(v,val)),G[v].push_back(Edge(u,val));
	}
}
void dfs(LL now,LL pre)
{
	dep[now]=dep[pre]+1;
	fa[0][now]=pre;
	for(auto st:G[now])
	{
		LL v=st.t,val=st.v;
		if(v==pre)	continue;
		maxn[0][v]=val;
		dfs(v,now);
	}
}
LL LCA(LL u,LL v)
{
	if(dep[u]>dep[v])	swap(u,v);
	while(dep[u]<dep[v])	v=fa[lgs[dep[v]-dep[u]]][v];
	if(u==v)	return u;
	for(LL i=17;~i;--i)	if(fa[i][u]!=fa[i][v])	u=fa[i][u],v=fa[i][v];
	return fa[0][u];
}
LL getMax(LL u,LL d)
{
	LL ret=0;
	for(LL i=17;~i;--i)	if((d>>i)&1)	ret=max(ret,maxn[i][u]),u=fa[i][u];
	return ret;
}
int main(){
	n=read(),m=read(),k=read(),q=read();
	for(LL i=1;i<=m;++i)
	{
		LL u=read(),v=read(),val=read();
		G[u].push_back(Edge(v,val));
		G[v].push_back(Edge(u,val));
	}
	for(LL i=1;i<=k;++i)	G[n+1].push_back(Edge(i,0));
	Dijkstra(n+1,n+1);
	for(LL i=1;i<=n;++i)	for(auto st:G[i])	if(i<=st.t)	ed[++cnt]=edge(i,st.t,st.v+dis[i]+dis[st.t]);
	for(LL i=1;i<=n;++i)	G[i].clear();
	Kruskal();
	dfs(1,0);
	for(LL i=2;i<=n;++i)	lgs[i]=lgs[i>>1]+1;
	for(LL i=1;i<=17;++i)	for(LL j=1;j<=n;++j)	fa[i][j]=fa[i-1][fa[i-1][j]],maxn[i][j]=max(maxn[i-1][j],maxn[i-1][fa[i-1][j]]);
	while(q-->0)
	{
		LL u=read(),v=read(),lca=LCA(u,v);
		LL dx=dep[u]-dep[lca],dy=dep[v]-dep[lca];
		write(max(getMax(u,dx),getMax(v,dy))),puts("");
	}
	return 0;
}