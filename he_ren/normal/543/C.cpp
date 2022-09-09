#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 20 + 5;
const int MAXM = 20 + 5;
const int ALL = (1<<20)+5;
const int inf = 0x3f3f3f3f;

#define bit(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

inline void chk_min(int &a,int b){ if(a>b) a=b;}
inline void chk_max(int &a,int b){ if(a<b) a=b;}

int lb[ALL];

char s[MAXN][MAXM];
int a[MAXN][MAXM];
int same[MAXN][MAXM],cost[MAXN][MAXM];
int dp[ALL];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
	
	for(int i=0; i<n; ++i) lb[1<<i]=i;
	
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			int mx=0;
			for(int k=1; k<=n; ++k)
				if(s[i][j]==s[k][j])
				{
					same[i][j] |= 1<<(k-1);
					cost[i][j] += a[k][j];
					chk_max(mx,a[k][j]);
				}
			cost[i][j]-=mx;
		}
	
	int all=(1<<n)-1;
	for(int mask=0; mask<all; ++mask)
	{
		int i=lowbit(~mask);
		int next=mask|i;
		i=lb[i]+1;
		
		for(int j=1; j<=m; ++j)
		{
			chk_min(dp[next], dp[mask]+a[i][j]);
			chk_min(dp[mask | same[i][j]], dp[mask]+cost[i][j]);
		}
	}
	printf("%d",dp[all]);
	return 0;
}