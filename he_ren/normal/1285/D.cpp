#include<cstdio>
const int MAXN = 1e5 + 5;
const int MAXP = 1e7 + 5;
const int inf = (1<<30)-1;
const int LG = 29;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int a[MAXN];
int son[MAXP][2],scnt[MAXP],pcnt=1;
#define bit(x,i) (((x)>>(i))&1)

inline void insert(int x)
{
	int u=1;
	for(int i=LG; i>=0; --i)
	{
		int to = bit(x,i);
		if(!son[u][to])
			son[u][to]=++pcnt,
			++scnt[u];
		u=son[u][to];
	}
}

int ans=inf;
void dfs(int u,int now)
{
	if(!scnt[u])
	{
		chk_min(ans,now);
		return;
	}
	
	now<<=1;
	if(scnt[u]==2) now|=1;
	if(son[u][0]) dfs(son[u][0],now);
	if(son[u][1]) dfs(son[u][1],now);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) insert(a[i]);
	dfs(1,0);
	printf("%d",ans);
	return 0;
}