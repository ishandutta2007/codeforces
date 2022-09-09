#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

ll pw2[MAXN];

string s[MAXN];

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXN; ++i) pw2[i] = pw2[i-1] * 2 %mod;
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		cin >> s[i], s[i] = '\0' + s[i];
	
	static int f[MAXN][3], g[MAXN][3], dp[MAXN];
	f[1][0] = f[1][2] = 1;
	for(int i=1; i+1<MAXN; ++i)
	{
		f[i+1][0] = (f[i][1] + f[i][2]) %mod;
		g[i+1][0] = (g[i][1] + g[i][2]) %mod;
		
		f[i+1][1] = f[i][0];
		g[i+1][1] = (g[i][0] + f[i][0]) %mod;
		
		f[i+1][2] = ((ll)f[i][0] + f[i][1] + f[i][2]) %mod;
		g[i+1][2] = ((ll)g[i][0] + g[i][1] + g[i][2]) %mod;
		
		dp[i] = ((ll)g[i][0] + g[i][1] + g[i][2]) %mod;
	}
	
	int tot = 0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			if(s[i][j] == 'o') ++tot;
	
	int ans = 0;
	for(int k=1; k<=n; ++k)
		for(int l=1,r=1; l<=m; l=r)
		{
			while(r<=m && s[k][l] == s[k][r]) ++r;
			if(s[k][l] != 'o') continue;
			ans = (ans + (ll)dp[r-l] * pw2[tot - (r-l)]) %mod;
		}
	for(int k=1; k<=m; ++k)
		for(int l=1,r=1; l<=n; l=r)
		{
			while(r<=n && s[l][k] == s[r][k]) ++r;
			if(s[l][k] != 'o') continue;
			ans = (ans + (ll)dp[r-l] * pw2[tot - (r-l)]) %mod;
		}
	
	printf("%d",ans);
	return 0;
}