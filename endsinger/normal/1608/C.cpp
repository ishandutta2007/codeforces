#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,k,dfn[N],low[N],ti,st[N],tp,in[N],c[N],a[N],b[N],oa[N],ob[N];
vector<int>e[N];
void tarjan(int u)
{
	dfn[u]=low[u]=++ti;
	st[++tp]=u,in[u]=1;
	for(auto v:e[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);
		}
		else if(in[v])
			low[u]=min(low[u],dfn[v]);
	}
	if(low[u]==dfn[u])
	{
		k++;
		int v;
		do
		{
			v=st[tp--];
			in[v]=0;
			c[v]=k;
		}while(v!=u);
	}
}
void sol()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		dfn[i]=low[i]=st[i]=in[i]=c[i]=0;
		oa[i]=ob[i]=i;
		e[i].clear();
	}
	ti=tp=k=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);
	sort(oa+1,oa+n+1,[&](int x,int y){return a[x]<a[y];});
	sort(ob+1,ob+n+1,[&](int x,int y){return b[x]<b[y];});
	for(int i=2;i<=n;i++)
		e[oa[i]].push_back(oa[i-1]),e[ob[i]].push_back(ob[i-1]);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		printf("%d",c[i]==k);
	puts("");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}