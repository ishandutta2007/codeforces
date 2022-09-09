#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

struct Node
{
	int x,y;
};

char s[MAXN][MAXM];
int a[MAXN][MAXM], dis[MAXN][MAXM];

int main(void)
{
	int n,m,Q;
	scanf("%d%d%d",&n,&m,&Q);
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			a[i][j] = s[i][j] - '0';
	
	static queue<Node> q;
	memset(dis,-1,sizeof(dis));
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			bool flag=0;
			for(int k=0; k<4; ++k)
			{
				int x=i+dx[k], y=j+dy[k];
				if(x<1 || x>n || y<1 || y>m) continue;
				if(a[x][y] == a[i][j])
				{
					flag=1;
					break;
				}
			}
			if(!flag) continue;
			
			dis[i][j] = 0;
			q.push((Node){i,j});
		}
	
	while(!q.empty())
	{
		int x=q.front().x, y=q.front().y;
		q.pop();
		
		for(int k=0; k<4; ++k)
		{
			int xx=x+dx[k], yy=y+dy[k];
			if(xx<1 || xx>n || yy<1 || yy>m || ~dis[xx][yy]) continue;
			dis[xx][yy] = dis[x][y] + 1;
			q.push((Node){xx,yy});
		}
	}
	
	while(Q--)
	{
		int x,y;
		ll d;
		scanf("%d%d%lld",&x,&y,&d);
		
		if(dis[x][y] == -1 || d < dis[x][y]){ printf("%d\n",a[x][y]); continue;}
		
		if((d-dis[x][y])&1ll) printf("%d\n",a[x][y]^1);
		else printf("%d\n",a[x][y]);
	}
	return 0;
}