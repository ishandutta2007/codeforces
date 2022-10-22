#include<bits/stdc++.h>
using namespace std;
vector<int> G[400005];
bool vis[400005];
void dfs(int now)
{
	vis[now]=true;
	for(unsigned int i=0;i<G[now].size();++i)	if(!vis[G[now][i]])	dfs(G[now][i]);
}
int main(){
	int n,m,in;
	scanf("%d %d %d",&n,&m,&in);
	for(int i=1;i<=in;++i)
	{
		int x,y;
		scanf("%d %d",&x,&y);
		G[x].push_back(n+y);
		G[n+y].push_back(x);
	}
	int ans=0;
	for(int i=1;i<=n+m;++i)	if(!vis[i])	dfs(i),++ans;
	printf("%d",ans-1);
	return 0;
}