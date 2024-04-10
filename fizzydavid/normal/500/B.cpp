//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n,g[311],p[311];
bool vis[311];
vector<int>con[311];
void dfs(int x,int c)
{
	g[x]=c;
	for(int i=0;i<con[x].size();i++)
	{
		if(g[con[x][i]]==0)dfs(con[x][i],c);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;int x;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		p[x]=i;
	}
	char tmp;
	for(int i=1;i<=n;i++)
	{
		cin.ignore();
		for(int j=1;j<=n;j++)
		{
			cin>>tmp;
			if(tmp=='1')con[i].PB(j);
		}
	}
	int id=0;
	for(int i=1;i<=n;i++)
	{
		if(g[i]==0)dfs(i,++id);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(g[i]==g[p[j]]&&!vis[j])
			{
				vis[j]=1;
				cout<<j<<" ";
				break;
			}
		}
	}
	return 0;
}