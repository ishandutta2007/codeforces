#include<cstdio>
const int MAXN = 100 + 5;
const int inf = 0x7fffffff;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int c[MAXN][MAXN],a[MAXN];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j) scanf("%d",&c[i][j]);
		
		a[i]=inf;
		for(int j=1; j<=m; ++j) chk_min(a[i],c[i][j]);
	}
	
	int ans=0;
	for(int i=1; i<=n; ++i) chk_max(ans,a[i]);
	printf("%d",ans);
	return 0;
}