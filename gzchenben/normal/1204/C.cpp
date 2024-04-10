#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
int n,m,p[1000005],cnt,ans[1000005];
bool vis[105];
struct node
{
	int x;
	int step;
};
queue<node> q;
vector<int> vec[105];
bool bfs(int x,int y)
{
	while(!q.empty()) q.pop();
	memset(vis,false,sizeof(vis));
    vis[x]=true;
	q.push(node{x,y});
	while(1)
	{
		node temp=q.front();
		q.pop();
		if(temp.step==m)
		{
			ans[++cnt]=m;
//            printf("-%d\n",m);
			return false;
		}
		if(temp.step==y+1)
		{
//            if(y==1) printf("----%d\n",vis[p[y+2]]);
			if(vis[p[y+2]])
			{
				ans[++cnt]=++y;
				return true;
			}
			y++;
		}
		for(int i=0;i<vec[temp.x].size();i++)
		{
			if(!vis[vec[temp.x][i]])
			{
                vis[vec[temp.x][i]]=true;
				q.push(node{vec[temp.x][i],temp.step+1});
			}
		}
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			char temp;
			scanf(" %c",&temp);
			if(temp=='1') vec[i].push_back(j);
		}
	}
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&p[i]);
	}
	ans[++cnt]=1;
	while(bfs(p[ans[cnt]],ans[cnt]));
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ",p[ans[i]]);
	}
	return 0;
}