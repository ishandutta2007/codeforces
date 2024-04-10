#include<cstdio>
#include<cstring>
const int MAXN = 30 + 5;
const int MAXP = 50 + 5;
const int inf = 0x3ffffff;

inline void swap(int &a,int &b){ int t=a; a=b; b=t;}
inline void chk_min(int &a,int b){ if(a>b) a=b;}

int dp[MAXN][MAXN][MAXP];

int gao(int n,int m,int p)
{
	if(n<m) swap(n,m);
	if(dp[n][m][p]!=-1) return dp[n][m][p];
	if(!p) return dp[n][m][p]=0;
	if(n*m < p) return dp[n][m][p] = inf;
	if(n*m == p) return dp[n][m][p] = 0;
	if(m==1) return dp[n][m][p] = 1;
	
	dp[n][m][p] = inf;
	int nc=m*m, mc=n*n;
	for(int i=0; i<=p; ++i)
	{
		for(int j=1; j<=(n>>1); ++j)
			chk_min(dp[n][m][p], gao(j,m,i)+gao(n-j,m,p-i)+nc);
		
		for(int j=1; j<=(m>>1); ++j)
			chk_min(dp[n][m][p], gao(n,j,i)+gao(n,m-j,p-i)+mc);
	}
	
	return dp[n][m][p];
}

int main(void)
{
	memset(dp,-1,sizeof(dp));
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n,m,p;
		scanf("%d%d%d",&n,&m,&p);
		printf("%d\n",gao(n,m,p));
	}
	return 0;
}