#include<cstdio>
const int MAXN = 100 + 5;
const int MAXM = 1e6 + 5;
const int inf = 1e6;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

char s[MAXN];
int g[MAXN][MAXN];
int dis[MAXN][MAXN];

struct Node
{
	int x,last,next;
}a[MAXM];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s+1);
		for(int j=1; j<=n; ++j)
			g[i][j] = s[j]-'0';
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
		{
			if(i!=j && g[i][j]) dis[i][j]=1;
			else dis[i][j] = inf;
			
			if(i==j) dis[i][j]=0;
		}
	
	for(int k=1; k<=n; ++k)
		for(int i=1; i<=n; ++i) if(g[i][k])
			for(int j=1; j<=n; ++j)
				chk_min(dis[i][j], dis[i][k]+dis[k][j]);
	
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
	{
		scanf("%d",&a[i].x);
		a[i].last=i-1; a[i].next=i+1;
	}
	
	int cnt=m;
	for(int i=2; i<=m; i=a[i].next)
	{
		int u=a[i].last, v=a[i].next, x=a[i].x;
		if(dis[a[u].x][a[v].x] == dis[a[u].x][x]+dis[x][a[v].x])
		{
			--cnt;
			a[u].next=v, a[v].last=u;
		}
	}
	
	printf("%d\n",cnt);
	for(int i=1; i<=m; i=a[i].next) printf("%d ",a[i].x);
	return 0;
}