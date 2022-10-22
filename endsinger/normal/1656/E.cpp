#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,a[N];
vector<int>e[N];
void dfs(int u,int f,int s)
{
	for(auto v:e[u])
		if(v!=f)
			dfs(v,u,s^1);
	a[u]=e[u].size();
	if(s)
		a[u]=-a[u];
}
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		e[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
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