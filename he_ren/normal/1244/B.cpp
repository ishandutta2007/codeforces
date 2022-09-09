#include<cstdio>
const int MAXN = 1e3 + 5;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

int n;
char s[MAXN];

void solve(void)
{
	scanf("%d%s",&n,s+1);
	int ans=0,cnt=0;
	for(int i=1; i<=n; ++i) if(s[i]=='1')
	{
		++cnt;
		chk_max(ans, i*2);
		chk_max(ans, (n-i+1)*2);
	}
	chk_max(ans, n+cnt);
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}