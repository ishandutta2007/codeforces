#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int dp[MAXN][2];
	for(int i=0; i<=n+2; ++i)
		dp[i][0] = dp[i][1] = 0;
	dp[0][0] = 1;
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int x = a[i];
		if(x)
		{
			int t = (dp[x-1][1] + dp[x-1][0]) %mod;
			add_mod(ans, t);
			add_mod(dp[x-1][1], t);
		}
		
		for(int j=0; j<=1; ++j)
			add_mod(ans, dp[x+1][j]),
			add_mod(dp[x+1][j], dp[x+1][j]);
		
		add_mod(ans, dp[x][0]);
		add_mod(dp[x+1][0], dp[x][0]);
	}
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}