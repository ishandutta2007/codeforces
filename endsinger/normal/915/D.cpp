#include<bits/stdc++.h>
using namespace std;
const int N=505;
vector<int>e[N];
int d[N],res[N],vis[N],n,m;
queue<int>q;
int solve(int b)
{
	for(int i=1;i<=n;i++)
	{
		res[i]=d[i];
		vis[i]=0;
		if(i==b)
			res[i]--;
		if(res[i]<=0)
		{
			q.push(i);
			vis[i]=1;
		}
	}
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(auto v:e[u])
		{
			res[v]--;
			if(vis[v]==0&&res[v]<=0)
			{
				q.push(v);
				vis[v]=1;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			return 0;
	return 1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		d[v]++;
	}
	for(int i=1;i<=n;i++)
	{
		if(solve(i))
		{
			puts("YES");
			return 0;
		}
	}
	puts("NO");
	return 0;
}