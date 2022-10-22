#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m,s,vis[N],fl,sz;
vector<int>e[N];
void dfs(int u)
{
	vis[u]=1,sz++;
	if(e[u].size()<=1)
		fl=1;
	for(auto v:e[u])
		if(!vis[v])
			dfs(v);
}
void sol()
{
	scanf("%d%d",&n,&m);
	s=0;
	for(int i=1;i<=n;i++)
		e[i].clear(),vis[i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(x==y)
			continue;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			sz=fl=0;
			dfs(i);
			if(fl)
				s+=sz-1;
			else
				s+=sz+1;
		}
	}
	printf("%d\n",s);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}