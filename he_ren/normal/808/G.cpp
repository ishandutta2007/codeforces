#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

char s[MAXN], t[MAXM];
int fail[MAXM], nxt[MAXM][30];

int dp[2][MAXM];

int main(void)
{
	scanf("%s%s",s+1,t+1);
	int n = strlen(s+1), m = strlen(t+1);
	
	for(int i=2,j=0; i<=m; ++i)
	{
		while(j && t[j+1] != t[i]) j = fail[j];
		if(t[j+1] == t[i]) ++j;
		fail[i] = j;
	}
	
	for(int i=0; i<=m; ++i)
	{
		if(i < m) nxt[i][t[i+1] - 'a'] = i+1;
		for(int j=0; j<26; ++j) if(t[i+1] != j+'a')
			nxt[i][j] = i? nxt[fail[i]][j]: 0;
	}
	
	memset(dp, 0xc0, sizeof(dp));
	dp[0][0] = 0;
	for(int i=1; i<=n; ++i)
	{
		int now = i&1, lst = !now;
		memset(dp[now], 0xc0, (m+1)<<2);
		for(int u=0; u<=m; ++u) if(dp[lst][u] >= 0)
			for(int x=0; x<26; ++x)
			{
				if(s[i] != '?' && s[i] != x + 'a') continue;
				int v = nxt[u][x];
				dp[now][v] = max(dp[now][v], dp[lst][u] + (v == m));
			}
	}
	
	int ans = *max_element(dp[n&1], dp[n&1]+m+1);
	printf("%d",ans);
	return 0;
}