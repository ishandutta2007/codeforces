#include<cstdio>
#include<queue>
const int MAXN = 50 + 5;
using namespace std;

int a[MAXN][MAXN];
bool vis[MAXN][MAXN];

struct Node
{
	int x,y;
};
queue<Node> q;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
	
	for(int i=1; i<n; ++i)
	{
		for(int j=1; j<m; ++j)
		{
			if(a[i][j] && a[i+1][j] && a[i][j+1] && a[i+1][j+1])
			{
				vis[i][j]=vis[i+1][j]=vis[i][j+1]=vis[i+1][j+1]=1;
				q.push((Node){i,j});
			}
		}
	}
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			if(a[i][j]!=vis[i][j])
			{
				printf("-1");
				return 0;
			}
		}
	}
	
	printf("%d\n",q.size());
	while(!q.empty())
	{
		printf("%d %d\n",q.front().x,q.front().y);
		q.pop();
	}
	return 0;
}