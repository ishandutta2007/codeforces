#include<cstdio>
#include<cstring>
const int MAXN = 5e3 + 5;
const int MAXA = 1e5 + 5;

int max(int a,int b){ return a>b? a: b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int a[MAXN],dp[MAXN][MAXN],f[10],g[MAXA];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans=0;
	for(int i=0; i<=n; ++i)
	{
		memset(f,0,sizeof(f));
		memset(g,0,sizeof(g));
		for(int j=1; j<i; ++j)
		{
			chk_max(f[a[j]%7], dp[i][j]);
			chk_max(g[a[j]], dp[i][j]);
		}
		for(int j=i+1; j<=n; ++j)
		{
			dp[i][j]=dp[i][0];
			chk_max(dp[i][j], f[a[j]%7]);
			chk_max(dp[i][j], max(g[a[j]+1], g[a[j]-1]));
			++dp[i][j];
			dp[j][i]=dp[i][j];
			
			chk_max(f[a[j]%7], dp[i][j]);
			chk_max(g[a[j]], dp[i][j]);
			chk_max(ans,dp[i][j]);
		}
	}
	
	printf("%d",ans);
	return 0;
}