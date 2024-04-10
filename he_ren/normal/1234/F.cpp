#include<cstdio>
#include<cstring>
const int MAXN = 1e6 + 5;
const int LB = 20;
const int ALL = (1<<LB)-1;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

char s[MAXN];
int a[MAXN],dp[ALL+5];
bool vis[ALL+5];

inline int gao(int s)
{
	if(vis[s]) return dp[s];
	if(!s) return 0;
	
	vis[s]=1;
	for(int i=0; i<LB; ++i)
		if(s&(1<<i)) chk_max(dp[s], gao(s^(1<<i)));
	return dp[s];
}

int main(void)
{
	scanf("%s",s+1);
	int n=strlen(s+1);
	for(int i=1; i<=n; ++i) s[i]-='a';
	
	for(int i=1; i<=n; ++i)
	{
		int j=i;
		while(j<=n && ((1<<s[j])&a[i]) == 0)
		{
			a[i] |= 1<<s[j];
			++j;
			chk_max(dp[a[i]], j-i);
		}
	}
	
	gao(ALL);
	int ans=0;
	for(int i=0; i<=ALL; ++i)
		chk_max(ans, dp[i]+dp[ALL^i]);
	printf("%d",ans);
	return 0;
}