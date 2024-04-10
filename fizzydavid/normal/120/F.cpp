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
const int INF=1<<28;
int tn,n,pnt,dist;
vector<int>con[111];
void bfs(int x)
{
	bool vis[111]={};
	queue<pair<int,int> >q;
	q.push(make_pair(x,0));
	vis[x]=1;
	while(!q.empty())
	{
		int u=q.front().ff,d=q.front().ss;q.pop();
		if(d>dist)dist=d,pnt=u;
		for(int i=0;i<con[u].size();i++)
		{
			int v=con[u][i];
			if(!vis[v])
			{
				q.push(make_pair(v,d+1));
				vis[v]=1;
			}
		}
	}
}
int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tn);
	int ans=0;
	while(tn--)
	{
		for(int i=1;i<110;i++)con[i].clear();
		scanf("%d",&n);
		for(int i=1;i<n;i++)
		{
			int x,y;
			scanf("%d %d",&x,&y);
			con[x].push_back(y);
			con[y].push_back(x);
		}
		pnt=0;dist=0;
		bfs(1);dist=0;
		bfs(pnt);
		ans+=dist;
	}
	cout<<ans;
 //	system("pause");
	return 0;
}