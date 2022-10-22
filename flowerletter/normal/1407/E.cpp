#include <iostream>
#include <vector>
#include <cstdio>
#include <queue> 
using namespace std;
vector <int> e0[500005],e1[500005];
int vis[500005],dis[500005],ans[500005];
queue <int> q;
int main(int argc, char** argv) {
	int n,m;
	cin >> n >> m;
	if(n==1)
	{
		puts("0");
		puts("0");
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		if(!w) e0[v].push_back(u);
		else e1[v].push_back(u);
	}
	vis[n]=3;
	q.push(n);
	dis[1]=1e9;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto v:e0[x])
		{
			if(!(vis[v]&1))
			{
				vis[v]|=1;
				if(vis[v]==3)
				{
					dis[v]=dis[x]+1,ans[v]=0;
					q.push(v);
				}
			}
		}
		for(auto v:e1[x])
		{
			if(!(vis[v]&2))
			{
				vis[v]|=2;
				if(vis[v]==3)
				{
					dis[v]=dis[x]+1,ans[v]=1;
					q.push(v);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==1) ans[i]=1;
		if(vis[i]==2) ans[i]=0;
	}
	if(dis[1]>1e8)
		puts("-1");
	else cout << dis[1] << "\n";
	for(int i=1;i<=n;i++)
		cout << ans[i];
	return 0;
}