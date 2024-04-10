//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
int n;
vector<int>con[200111];
bool f[200111];
bool son[200111];
vector<int>v;
bool vis[200111];
void dfs(int x,int pre=0)
{
	f[x]^=1;
	printf("%d ",x);
	for(int i=0;i<con[x].size();i++)
	{
		if(son[con[x][i]]&&con[x][i]!=pre)
		{
			dfs(con[x][i],x);
			f[x]^=1;
			printf("%d ",x);
			if(!f[con[x][i]])
			{
				dfs(con[x][i],x);
				f[x]^=1;
				printf("%d ",x);
			}
		}
	}
	son[x]=0;
	for(int i=0;i<con[x].size();i++)
	{
		if(con[x][i]!=pre)
		{
			son[x]|=son[con[x][i]];
		}
	}
	son[x]|=(!f[x]);
}
void initdfs(int x)
{
	vis[x]=1;
	for(int i=0;i<con[x].size();i++)
	{
		if(!vis[con[x][i]])
		{
			initdfs(con[x][i]);
			son[x]|=son[con[x][i]];
		}
	}
	son[x]|=!f[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		f[i]=(x==1);
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		con[x].PB(y);
		con[y].PB(x);
	}
	f[1]^=1;
	initdfs(1);
	memset(vis,0,sizeof(vis));
	dfs(1);
	if(!f[1])
	{
		int y=con[1][0];
		cout<<y<<" "<<1<<" "<<y<<endl;
	}
	return 0;
}