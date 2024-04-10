#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,x,y,lst[1111],cnt,cr,cp;
vector<int> g[1111];
bool mp[1111][1111],can[1111],fucked;
int Get(int x)
{
	return ((rand()<<10)+rand())%x+1;
}
int ask(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	scanf("%d",&cr);
	return cr;
}
void dfs(int i,int fa)
{
	if (i==lst[x] || i==lst[y]) 
	{
		fucked=1;
		return;
	}
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa || can[to]) continue;
		dfs(to,i);
	}
}
void rfs(int i,int fa)
{
	can[i]=1;
	for (int j=0;j<g[i].size();j++)
	{
		int to=g[i][j];
		if (to==fa || can[to]) continue;
		rfs(to,i);
	}
}
int main()
{
	srand(time(0));
	scanf("%d",&n);
	for (int i=1;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(y);
		g[y].push_back(x);
		mp[x][y]=mp[y][x]=1;
	}
	cnt=n;
	for (int i=1;i<=n;i++) lst[i]=i;
	while(cnt>1)
	{
		if (cnt==2)
		{
			int cc=ask(lst[1],lst[2]);
			printf("! %d\n",cc);
			fflush(stdout);
			return 0;
		}
		x=Get(cnt);y=Get(cnt);
		while(x==y || mp[lst[x]][lst[y]]) 
		{
			x=Get(cnt);y=Get(cnt);
		} 
		cp=ask(lst[x],lst[y]);
		for (int i=0;i<g[cp].size();i++)
		{
			int to=g[cp][i];
			if (!can[to])
			{
				fucked=0;
				dfs(to,cp);
				if (fucked) rfs(to,cp);
			}
		}
		cnt=0;
		for (int i=1;i<=n;i++) 
		{
			if (!can[i]) lst[++cnt]=i;
		}
	}
	printf("! %d\n",lst[1]);
	fflush(stdout);
	return Accepted;
}
//a