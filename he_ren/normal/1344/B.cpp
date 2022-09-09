#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;
const int dx[] = {1,0,-1,0};
const int dy[] = {0,1,0,-1};

int n,m;
char s[MAXN][MAXM];
int a[MAXN][MAXM];
bool can[MAXN][MAXM];

bool hasc[MAXN],hasr[MAXM];

int ans=0;
bool vis[MAXN][MAXM];

void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0; i<4; ++i)
	{
		int xx = x+dx[i];
		int yy = y+dy[i];
		if(vis[xx][yy] || !a[xx][yy]) continue;
		dfs(xx,yy);
	}
}

int main(void)
{
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			a[i][j] = (s[i][j] == '#');
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			can[i][j] = a[i][j];
	
	for(int i=1; i<=n; ++i)
	{
		int fst=m+1;
		for(int j=m; j>=1; --j)
			if(a[i][j]) fst = j;
		int lst=0;
		for(int j=1; j<=m; ++j)
			if(a[i][j]) lst = j;
		
		for(int j=fst; j<=lst; ++j)
			if(!a[i][j]){ printf("-1"); return 0;}
	}
	
	for(int j=1; j<=m; ++j)
	{
		int fst=n+1;
		for(int i=n; i>=1; --i)
			if(a[i][j]) fst = i;
		int lst=0;
		for(int i=1; i<=n; ++i)
			if(a[i][j]) lst = i;
		
		for(int i=fst; i<=lst; ++i)
			if(!a[i][j]){ printf("-1"); return 0;}
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			hasc[i] |= a[i][j],
			hasr[j] |= a[i][j];
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(!hasc[i] && !hasr[j])
				can[i][j] = 1;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			hasc[i] |= can[i][j],
			hasr[j] |= can[i][j];
	
	for(int i=1; i<=n; ++i)
		if(!hasc[i]){ printf("-1"); return 0;}
	for(int j=1; j<=m; ++j)
		if(!hasr[j]){ printf("-1"); return 0;}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(a[i][j] && !vis[i][j])
				++ans, dfs(i,j);
	printf("%d",ans);
	return 0;
}