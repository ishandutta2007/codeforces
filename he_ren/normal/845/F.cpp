#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 250 + 5;
const int MAXM = 250 + 5;
const int ALL = (1<<15) + 5;
const int mod = 1e9 + 7;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

char s[MAXN][MAXM];
int dp[2][2][ALL][2];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	if(n < m)
	{
		for(int i=1; i<=n || i<=m; ++i)
			for(int j=1; j<i; ++j)
				swap(s[i][j], s[j][i]);
		swap(n, m);
	}
	
	int all = (1<<m) - 1;
	int now = 0, lst = 1;
	dp[0][0][0][0] = 1;
	for(int i=1; i<=n; ++i)
	{
		for(int x=0; x<=1; ++x)
			for(int mask=0; mask<=all; ++mask)
				add_mod(dp[now][x][mask][0], dp[now][x][mask][1]),
				dp[now][x][mask][1] = 0;
		for(int j=1; j<=m; ++j)
		{
			swap(now, lst);
			memset(dp[now], 0, sizeof(dp[now]));
			for(int x=0; x<=1; ++x)
				for(int mask=0; mask<=all; ++mask)
					for(int y=0; y<=1; ++y) if(dp[lst][x][mask][y])
					{
						int cur = dp[lst][x][mask][y];
						int nxt0 = mask ^ (mask & bbit(j-1));
						int nxt1 = nxt0 | bbit(j-1);
						if(s[i][j] == 'x')
							add_mod(dp[now][x][nxt0][0], cur);
						else
						{
							bool has = y || bdig(mask, j-1);
							add_mod(dp[now][x][nxt1][1], cur);
							if(has)
								add_mod(dp[now][x][mask][y], cur);
							else if(!x)
								add_mod(dp[now][1][mask][y], cur);
						}
					}
		}
	}
	
	int ans = 0;
	for(int x=0; x<=1; ++x)
		for(int mask=0; mask<=all; ++mask)
			for(int y=0; y<=1; ++y)
				add_mod(ans, dp[now][x][mask][y]);
	printf("%d",ans);
	return 0;
}