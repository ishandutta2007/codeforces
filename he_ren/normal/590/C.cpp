#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
using namespace std;
const int MAXN = 1e3 + 5;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void error(void){ printf("-1"); exit(0);}

int n,m;
char s[MAXN];
int a[MAXN][MAXN];

struct Node
{
	int x,y;
};
int dis[4][MAXN][MAXN];
queue<Node> q;
void bfs(int clr)
{
	memset(dis[clr],-1,sizeof(dis[clr]));
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(a[i][j]==clr)
			{
				dis[clr][i][j]=0;
				q.push((Node){i,j});
			}
	
	while(!q.empty())
	{
		int x=q.front().x, y=q.front().y;
		q.pop();
		
		for(int k=0; k<4; ++k)
		{
			int nx=x+dx[k], ny=y+dy[k];
			if(!a[nx][ny] || dis[clr][nx][ny]!=-1) continue;
			dis[clr][nx][ny] = dis[clr][x][y]+1;
			q.push((Node){nx,ny});
		}
	}
}

int cdis[5][5];
int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s+1);
		for(int j=1; j<=m; ++j)
		{
			if(s[j]=='#') continue;
			if(s[j]=='.') a[i][j]=4;
			else a[i][j]=s[j]-'0';
		}
	}
	
	for(int i=1; i<=3; ++i) bfs(i);
	
	int ans=inf;
	memset(cdis,0x3f,sizeof(cdis));
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j) if(a[i][j])
		{
			int tot=0;
			for(int k=1; k<=3; ++k)
			{
				if(dis[k][i][j]==-1)
				{
					if(a[i][j]!=4) error();
					tot=-1;
					break;
				}
				
				chk_min(cdis[ a[i][j] ][k], dis[k][i][j]);
				tot+=dis[k][i][j];
			}
			
			if(tot!=-1) chk_min(ans,tot-2);
		}
	
	for(int i=1; i<=3; ++i)
	{
		int tot=0;
		for(int j=1; j<=3; ++j) tot+=cdis[i][j];
		chk_min(ans,tot-2);
	}
		
	if(ans==inf) printf("-1");
	else printf("%d",ans);
	return 0;
}