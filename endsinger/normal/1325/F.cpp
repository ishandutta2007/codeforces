#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<int>e[N],s;
int c[N],n,m,k,dep[N];
void dfs(int u)
{
	s.push_back(u);
	dep[u]=s.size();
	for(auto v:e[u])
	{
		if(!dep[v])
			dfs(v);
		else if(dep[u]-dep[v]+1>=k)
		{
			printf("2\n%d\n",dep[u]-dep[v]+1);
			for(int i=dep[v]-1;i<dep[u];i++)
				printf("%d ",s[i]);
			exit(0);
		}
	}
	if(!c[u])
		for(auto v:e[u])
			c[v]=1;
	s.pop_back();
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	while(k*k<n)
		k++;
	dfs(1);
	printf("1\n");
	for(int i=1;k;i++)
	{
		if(!c[i])
		{
			printf("%d ",i);
			k--;
		}
	}
	return 0;
}