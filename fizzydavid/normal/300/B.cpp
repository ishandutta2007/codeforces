#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
int n,m,sz[30];
bool vis[50],ok=1;
vector<int>con[50],ans[30];
void dfs(int u,int p)
{
	vis[u]=1;
	ans[p].push_back(u);
	sz[p]++;
	for(int i=0;i<con[u].size();i++)
	{
		if(!vis[con[u][i]])dfs(con[u][i],p);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		con[u].push_back(v);
		con[v].push_back(u);
	}
	int id=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i]&&con[i].size()>0)id++,dfs(i,id);
		if(sz[id]>3||id>n/3){ok=0;break;}
	}
	if(ok==0)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			bool t=0;
			for(int j=1;j<=id;j++)
			{
				if(sz[j]<3){ans[j].push_back(i),sz[j]++,vis[i]=1,t=1;break;}
			}
			if(t==0)
			{
				id++;ans[id].push_back(i);sz[id]++;vis[i]=1;
			}
		}
	}
	for(int i=1;i<=id;i++)printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);
// 	system("pause");
	return 0;
}