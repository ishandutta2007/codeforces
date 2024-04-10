#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

char s[MAXN], t[MAXM];
int f[MAXN], g[MAXM], dp[MAXN][MAXM][2];

int main(void)
{
	scanf("%s%s",s+1,t+1);
	int n = strlen(s+1), m = strlen(t+1);
	
	f[1] = g[1] = 1;
	for(int i=2; i<=n; ++i) f[i] = s[i] == s[i-1]? 1: f[i-1] + 1;
	for(int i=2; i<=m; ++i) g[i] = t[i] == t[i-1]? 1: g[i-1] + 1;
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			if(s[i] != t[j])
				dp[i][j][0] = g[j], dp[i][j][1] = f[i];
			
			if(s[i] != s[i-1]) add_mod(dp[i][j][0], dp[i-1][j][0]);
			if(s[i] != t[j]) add_mod(dp[i][j][0], dp[i-1][j][1]);
			
			if(t[j] != t[j-1]) add_mod(dp[i][j][1], dp[i][j-1][1]);
			if(t[j] != s[i]) add_mod(dp[i][j][1], dp[i][j-1][0]);
			
			ans = ((ll)ans + dp[i][j][0] + dp[i][j][1]) %mod;
		}
	printf("%d",ans);
	return 0;
}