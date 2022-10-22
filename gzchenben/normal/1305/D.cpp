#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector> 
#include<algorithm>
using namespace std;
int n,maxn1,maxn2,cnt=1,a[1005],head[1005],dis[1005],rt;
struct node
{
	int to;
	int nxt;
	bool flag;
}edge[2005];
void add(int x,int y)
{
	edge[++cnt].to=y;
	edge[cnt].flag=true;
	edge[cnt].nxt=head[x];
	head[x]=cnt;
}
bool check(int x)
{
	for(int i=head[x];i;i=edge[i].nxt)
	{
		if(edge[i].flag) return true;
	}
	return false;
}
void dfs(int x,int fa)
{
	dis[x]=dis[fa]+1;
	for(int i=head[x];i;i=edge[i].nxt)
	{
		if(!edge[i].flag || edge[i].to==fa) continue;
		dfs(edge[i].to,x);
	}
}
void del(int x)
{
	while(x!=maxn1)
	{
		for(int i=head[x];i;i=edge[i].nxt)
		{
			if(!edge[i].flag) continue;
			if(dis[edge[i].to]==dis[x]-1)
			{
//				printf("del: %d %d\n",x,edge[i].to);
				edge[i].flag=edge[i^1].flag=false;
				x=edge[i].to;
				break;
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n-1;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		add(x,y);
		add(y,x);
	}
	rt=1;
	while(check(rt))
	{
		maxn1,maxn2=0;
		memset(dis,0,sizeof(dis));
		dfs(rt,0);
		for(int i=1;i<=n;i++)
		{
			if(dis[i]>dis[maxn1])
			{
				maxn1=i;
			}
		}
		memset(dis,0,sizeof(dis));
		dfs(maxn1,0);
		for(int i=1;i<=n;i++)
		{
//			printf("dis[%d]=%d\n",i,dis[i]);
			if(dis[i]>dis[maxn2])
			{
				maxn2=i;
			}
		}
		printf("? %d %d\n",maxn1,maxn2);
		fflush(stdout);
		del(maxn2);
		scanf("%d",&rt);
	}
	printf("! %d\n",rt);
	fflush(stdout);
	return 0;
}