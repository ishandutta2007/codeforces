#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,fa[N],q[N],bg,ed,d[N],a[N],fl;
vector<int>e[N],g[N];
void dfs(int u,int f)
{
	fa[u]=f;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
}
void cal(int u)
{
	if(fl)
		return;
	int c0=0,c1=0;
	for(auto v:e[u])
	{
		if(v==fa[u])
			continue;
		cal(v);
		if(a[v])
			c1++;
		else
			c0++;
	}
	if(u==1&&c0>c1)
		fl=1;
	a[u]=(c1<=c0);
	int w=c1-c0;
	if(u!=1)
	{
		if(a[u])
			w++;
		else
			w--;
	}
	if(w!=0&&w!=1)
		fl=1;
}
void add(int u,int v)
{
	g[u].push_back(v);
	d[v]++;
}
void path(int u)
{
	vector<int>p[3];
	for(auto v:e[u])
	{
		if(v==fa[u])
			continue;
		path(v);
		p[a[v]].push_back(v);
	}
	if(u!=1)
		p[a[u]].push_back(u);
	for(int i=0;i<p[1].size();i++)
	{
		p[2].push_back(p[1][i]);
		if(i<p[0].size())
			p[2].push_back(p[0][i]);
	}
	reverse(p[2].begin(),p[2].end());
	for(int i=0;i+1<p[2].size();i++)
		add(p[2][i],p[2][i+1]);
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		e[i].clear();
		g[i].clear();
		d[i]=0;
	}
	bg=ed=fl=0;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	cal(1);
	if(fl)
	{
		puts("NO");
		return;
	}
	puts("YES");
	path(1);
	for(int i=2;i<=n;i++)
		if(!d[i])
			q[ed++]=i;
	while(bg<ed)
	{
		int u=q[bg++];
		printf("%d %d\n",u,fa[u]);
		for(auto v:g[u])
		{
			d[v]--;
			if(!d[v])
				q[ed++]=v;
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}