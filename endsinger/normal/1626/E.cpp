#include<bits/stdc++.h>
using namespace std;
const int N=300005;
int n,a[N],c[N],s[N],h[N],ans[N];
vector<int>e[N];
void dfs(int u,int f)
{
	for(int i=0;i<e[u].size();i++)	
	{
		if(e[u][i]==f)
		{
			e[u].erase(e[u].begin()+i);
			break;
		}
	}
	s[u]=c[u];
	for(auto v:e[u])
	{
		dfs(v,u);
		s[u]+=s[v];
		h[u]|=h[v];
	}
	if(s[u]>1&&a[u])
		h[u]=1;
}
void sol(int u,int fs,int fh)
{
	if(h[u]||fh||a[u])
		ans[u]=1;
	int m=e[u].size();
	vector<int>prs(m,0),sfs(m,0),prh(m,0),sfh(m,0);
	if(m)
	{
		prs[0]=s[e[u][0]];
		for(int i=1;i<m;i++)
			prs[i]=prs[i-1]+s[e[u][i]];
		sfs[m-1]=s[e[u][m-1]];
		for(int i=m-2;i>=0;i--)
			sfs[i]=sfs[i+1]+s[e[u][i]];
		prh[0]=h[e[u][0]];
		for(int i=1;i<m;i++)
			prh[i]=prh[i-1]|h[e[u][i]];
		sfh[m-1]=h[e[u][m-1]];
		for(int i=m-2;i>=0;i--)
			sfh[i]=sfh[i+1]|h[e[u][i]];
	}
	fs+=c[u];
	for(int i=0;i<m;i++)
	{
		int v=e[u][i],vs=fs,vh=fh;
		if(i) vs+=prs[i-1],vh|=prh[i-1];
		if(i+1<m) vs+=sfs[i+1],vh|=sfh[i+1];
		if(vs>1&&a[u]) vh=1;
		sol(v,vs,vh);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&c[i]),a[i]=c[i];
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
		if(c[u]||c[v])
			a[u]=a[v]=1;
	}
	dfs(1,0);
	sol(1,0,0);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}