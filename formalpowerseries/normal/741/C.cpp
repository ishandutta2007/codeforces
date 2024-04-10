#include<bits/stdc++.h>
using namespace std;
vector<int> G[200005];
int n,u[100005],v[100005],col[200005];
void dfs(int now,int c)
{
	col[now]=c;
	for(auto st:G[now])
	{
		assert(col[now]^col[st]);
		if(!col[st])	dfs(st,c^3);
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d %d",&u[i],&v[i]);
	for(int i=1;i<=n;++i)	G[u[i]].push_back(v[i]),G[v[i]].push_back(u[i]);
	for(int i=1;i<=n;++i)	G[2*i].push_back(2*i-1),G[2*i-1].push_back(2*i);
	for(int i=1;i<=n*2;++i)	if(!col[i])	dfs(i,1);
	for(int i=1;i<=n;++i)	printf("%d %d\n",col[u[i]],col[v[i]]);
	return 0;
}