#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXN = 150 + 5;
const int MAXM = 150 + 5;
const int MAXS = MAXN*MAXM;
const int inf = 0x3f3f3f3f;

inline int min(int a,int b){ return a<b? a: b;}
inline void chk_min(int &a,int b){ if(a>b) a=b;}

int q[MAXN], dp[MAXM][MAXS];

int main(void)
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1; i<=n; ++i) scanf("%d",&q[i]);
	chk_min(s, m*(n-m));
	
	memset(dp,0x3f,sizeof(dp));
	for(int i=0; i<=s; ++i) dp[0][i]=0;
	
	for(int i=1; i<=n; ++i)
	{
		for(int j=min(m,i); j>=1; --j)
		{
			for(int k=0; k+i-j<=s; ++k)
			{
				chk_min(dp[j][k], dp[j-1][k+i-j]+q[i]);
			}
		}
	}
	
	int ans = inf;
	for(int i=0; i<=s; ++i) chk_min(ans, dp[m][i]);
	printf("%d",ans);
	return 0;
}