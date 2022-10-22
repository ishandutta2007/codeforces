#include<bits/stdc++.h>
using namespace std;
int rd()
{
	char c=getchar();int x=0;
	while(!(c>='0'&&c<='9'))
		c=getchar();
	while(c>='0'&&c<='9')
	{
		x=x*10+(c-'0');
		c=getchar();
	}
	return x;
}
const int N=200005;
int n,m,ans[N];
struct ed
{
	int u,v,w,d;
	bool operator<(const ed k)const
	{
		return w<k.w;
	}
}e[N];
vector<ed>s[N];
vector<pair<int,int>>g[N];
vector<int>c[N];
struct dsu
{
	int f[N],sz[N];
	void init(int n){for(int i=1;i<=n;i++)f[i]=i,sz[i]=1;}
	int fa(int x){return x==f[x]?x:f[x]=fa(f[x]);}
}d1,d2;
namespace zz
{
	int fa[N][20],st[N][20],d[N];
	void dfs(int u,int f,int w)
	{
		fa[u][0]=f,st[u][0]=w,d[u]=d[f]+1;
		for(auto [v,w]:g[u])
			if(v!=f)
				dfs(v,u,w);
	}
	void main()
	{
		dfs(1,0,0);
		for(int j=1;j<=18;j++)
			for(int i=1;i<=n;i++)
				fa[i][j]=fa[fa[i][j-1]][j-1],st[i][j]=max(st[i][j-1],st[fa[i][j-1]][j-1]);
		for(int i=1;i<=m;i++)
		{
			int u=e[i].u,v=e[i].v,w=0;
			if(d[u]<d[v])
				swap(u,v);
			for(int j=18;j>=0;j--)
				if(d[fa[u][j]]>=d[v])
					w=max(w,st[u][j]),u=fa[u][j];
			if(u!=v)
			{
				for(int j=18;j>=0;j--)
					if(fa[u][j]!=fa[v][j])
						w=max(w,max(st[u][j],st[v][j])),u=fa[u][j],v=fa[v][j];
				w=max(w,max(st[u][0],st[v][0]));
			}
			ans[e[i].d]=w;
		}
	}
}
void mg(int u,int v,int w)
{
	u=d2.fa(u),v=d2.fa(v);
	if(u==v)
		return;
	if(s[u].size()>s[v].size())
		swap(u,v);
	int t=0;
	for(auto i:s[u])
		if(d2.fa(i.u)==v||d2.fa(i.v)==v)
			t++;
	if(t==1ll*d2.sz[u]*d2.sz[v])
		return;
	g[u].emplace_back(v,w);
	g[v].emplace_back(u,w);
	d2.f[u]=v;
	d2.sz[v]+=d2.sz[u];
	for(auto i:s[u])
		s[v].push_back(i);
}
void sol()
{
	n=rd(),m=rd();
	for(int i=0;i<=n;i++)
	{
		c[i]={i};
		g[i].clear();
		s[i].clear();
	}
	d1.init(n),d2.init(n);
	for(int i=1;i<=m;i++)
	{
		e[i].u=rd(),e[i].v=rd(),e[i].w=rd();
		e[i].d=i;
		s[e[i].u].push_back(e[i]);
		s[e[i].v].push_back(e[i]);
	}
	sort(e+1,e+m+1);
	for(int i=1;i<=m;i++)
	{
		int u=e[i].u,v=e[i].v,w=e[i].w;
		u=d1.fa(u),v=d1.fa(v);
		if(u==v)
			continue;
		for(auto x:c[u])
			for(auto y:c[v])
				mg(x,y,w);
		vector<int>p;
		for(auto x:c[u])
			if(d2.fa(x)==x)
				p.push_back(x);
		for(auto x:c[v])
			if(d2.fa(x)==x)
				p.push_back(x);
		sort(p.begin(),p.end());
		p.erase(unique(p.begin(),p.end()),p.end());
		d1.f[u]=v;
		d1.sz[v]+=d1.sz[u];
		c[v]=p;
	}
	zz::main();
	for(int i=1;i<=m;i++)
		printf("%d ",ans[i]);
	puts("");
}
int main()
{
	int t=rd();
	while(t--)
		sol();
	return 0;
}