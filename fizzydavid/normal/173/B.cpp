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
int n,m,a[1011][1011],dp[2022];
bool vis[2022];
vector<int>row[1011],col[1011];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		cin.ignore();
		for(int j=1;j<=m;j++)
		{
			char c;
			scanf("%c",&c);
			if(c=='#')
			{
				a[i][j]=1;
				row[i].push_back(j);
				col[j].push_back(i);
			}
			else a[i][j]=0;
		}
	}
	queue<int>q;
	q.push(n);
	vis[n]=1;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		if(u==1)
		{
			cout<<dp[1];
			return 0;
		}
		if(u<=n)
		{
			for(int i=0;i<row[u].size();i++)
			{
				int v=row[u][i];
				if(!vis[n+v])
				{
					dp[n+v]=dp[u]+1;
					q.push(n+v);
					vis[n+v]=1;
				}
			}
		}
		else if(u>n)
		{
			u-=n;
			for(int i=0;i<col[u].size();i++)
			{
				int v=col[u][i];
				if(!vis[v])
				{
					dp[v]=dp[u+n]+1;
					q.push(v);
					vis[v]=1;
				}
			}
		}
	}
	puts("-1");
// 	system("pause");
	return 0;
}