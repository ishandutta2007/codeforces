#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 10 + 5;
const int MAXP = MAXN*MAXN*3;
const int inf = 0x3f3f3f3f;
const int dx[] = { 1, 1,-1,-1, 2, 2,-2,-2};
const int dy[] = { 2,-2, 2,-2, 1,-1, 1,-1};

struct Node
{
	int x,y;
	Node(int xx=0,int yy=0){ x=xx; y=yy;}
	
	inline friend bool operator < (const Node &p,const Node &q){ return p.x==q.x? p.y<q.y: p.x<q.x;}
	inline friend Node operator + (const Node &p,const Node &q){ return (Node){p.x+q.x, p.y+q.y};}
};

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_min(Node &a,Node b){ if(b<a) a=b;}

int n;
int a[MAXN][MAXN],posx[MAXN*MAXN],posy[MAXN*MAXN];
int id[MAXN][MAXN][5];

inline bool valid(int x,int y){ return x>=1 && x<=n && y>=1 && y<=n;}

Node g[MAXP][MAXP];
Node dp[MAXN*MAXN][4];

int main(void)
{	
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			scanf("%d",&a[i][j]);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			posx[a[i][j]]=i, posy[a[i][j]]=j;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			for(int k=1; k<=3; ++k)
				id[i][j][k] = (k-1)*n*n + (i-1)*n + j;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			for(int x=1; x<=3; ++x)
				for(int y=1; y<=3; ++y)
					g[ id[i][j][x] ][ id[i][j][y] ]=(Node){1,1};
			
			int u=id[i][j][1];
			for(int k=0; k<8; ++k)
			{
				int x=i+dx[k], y=j+dy[k];
				if(valid(x,y))
					g[u][ id[x][y][1] ]=(Node){1,0};
			}
			
			u=id[i][j][2];
			for(int k=-n; k<=n; ++k)
			{
				int x=i+k, y=j+k;
				if(valid(x,y))
					g[u][ id[x][y][2] ]=(Node){1,0};
				
				x=i-k; y=j+k;
				if(valid(x,y))
					g[u][ id[x][y][2] ]=(Node){1,0};
			}
			
			u=id[i][j][3];
			for(int k=-n; k<=n; ++k)
			{
				int x=i+k, y=j;
				if(valid(x,y))
					g[u][ id[x][y][3] ]=(Node){1,0};
				
				x=i; y=j+k;
				if(valid(x,y))
					g[u][ id[x][y][3] ]=(Node){1,0};
			}
		}
	
	int p=n*n*3;
	for(int i=1; i<=p; ++i)
	{
		for(int j=1; j<=p; ++j)
			if(!g[i][j].x) g[i][j]=(Node){inf,0};
		g[i][i]=(Node){0,0};
	}
	
	for(int k=1; k<=p; ++k)
		for(int i=1; i<=p; ++i) if(g[i][k].x!=inf)
			for(int j=1; j<=p; ++j) if(g[k][j].x!=inf)
				chk_min(g[i][j], g[i][k]+g[k][j]);
	
	for(int i=1; i<=3; ++i) dp[1][i]=(Node){0,0};
	for(int i=2; i<=n*n; ++i)
	{
		int x=posx[i], y=posy[i];
		int lx=posx[i-1], ly=posy[i-1];
		for(int j=1; j<=3; ++j)
		{
			dp[i][j]=(Node){inf,0};
			int u=id[x][y][j];
			for(int k=1; k<=3; ++k)
			{
				int v=id[lx][ly][k];
				chk_min(dp[i][j], dp[i-1][k]+g[u][v]);
			}
		}
	}
	Node ans(inf,0);
	for(int i=1; i<=3; ++i)
		chk_min(ans, dp[n*n][i]);
	printf("%d %d",ans.x,ans.y);
	return 0;
}