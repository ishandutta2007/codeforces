#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
struct node
{
	int x,y;
	int step;
};
int n,m,t,a[1005][1005],dp[1005][1005];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
bool vis[1005][1005],ffff;
queue<node> q;
void bfs()
{
	while(!q.empty())
	{
		node tmp=q.front();
		q.pop();
		dp[tmp.x][tmp.y]=tmp.step;
		for(int i=0;i<4;i++)
		{
			if(tmp.x+dx[i]==0 || tmp.x+dx[i]==n+1 || tmp.y+dy[i]==0 || tmp.y+dy[i]==m+1)
				continue;
			if(!vis[tmp.x+dx[i]][tmp.y+dy[i]])
			{
				vis[tmp.x+dx[i]][tmp.y+dy[i]]=true;
				q.push((node){tmp.x+dx[i],tmp.y+dy[i],tmp.step+1});
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=1e9+1;
			char tmp;
			scanf(" %c",&tmp);
			if(tmp=='1') a[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			bool flag=false;
			for(int k=0;k<4;k++)
			{
				if(i+dx[k]==0 || i+dx[k]==n+1 || j+dy[k]==0 || j+dy[k]==m+1)
					continue;
				if(a[i][j]==a[i+dx[k]][j+dy[k]]) flag=true,ffff=true;
			}
			if(flag)
			{
				q.push((node){i,j,0});
				vis[i][j]=true;
			}
		}
	}
	if(!ffff)
	{
		for(int i=1;i<=t;i++)
		{
			long long x,y,z;
			scanf("%lld%lld%lld",&x,&y,&z);
			printf("%d\n",a[x][y]);
		}
		return 0;
	}
	bfs();
	for(int i=1;i<=t;i++)
	{
		long long x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
//		printf("%d\n",dp[x][y]);
		if(dp[x][y]>=z) printf("%d\n",a[x][y]);
		else if((z-dp[x][y])%2==0) printf("%d\n",a[x][y]);
		else printf("%d\n",!a[x][y]);
	}
}