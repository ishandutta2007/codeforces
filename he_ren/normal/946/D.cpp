#include<cstdio>
#include<cstring>
const int MAXN = 5e2 + 5;
const int MAXM = 5e2 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

char s[MAXN][MAXM];
int sum[MAXN][MAXM],f[MAXN][MAXM],g[MAXN][MAXM];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=1; j<=m; ++j)
		{
			s[i][j]-='0';
			sum[i][j] = sum[i][j-1] + s[i][j];
		}
		sum[i][m+1] = sum[i][m];
		
		for(int j=0; j<=m; ++j)
			for(int k=m+1; k>j; --k)
			{
				int tot = sum[i][j] + sum[i][m+1]-sum[i][k-1];
				chk_max(f[i][tot], j + m-k+1);
			}
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=d; ++j)
		{
			g[i][j] = g[i-1][j];
			for(int k=0; k<=sum[i][m] && k<=j; ++k)
				chk_max(g[i][j], g[i-1][j-k]+f[i][k]);
		}
	
	printf("%d",n*m-g[n][d]);
	return 0;
}