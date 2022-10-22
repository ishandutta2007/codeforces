#include<bits/stdc++.h>
using namespace std;
const int N=200005;
vector<int>e[N];
int fa[N],dep[N],s[N],t[N],tim,n,m,a[N],k;
void dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	fa[u]=f;
	s[u]=++tim;
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u);
	t[u]=tim;
}
bool cmp(int x,int y)
{
	return dep[x]<dep[y];
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0);
	while(m--)
	{
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]!=1)
				a[i]=fa[a[i]];
		}
		sort(a+1,a+k+1,cmp);
		int fl=1,l=1,r=n;
		for(int i=1;i<=k;i++)
		{
			if(l<=s[a[i]]&&t[a[i]]<=r)
			{
				l=s[a[i]];
				r=t[a[i]];
			}
			else
			{
				fl=0;
				break;
			}
		}
		puts(fl?"YES":"NO");
	}
	return 0;
}