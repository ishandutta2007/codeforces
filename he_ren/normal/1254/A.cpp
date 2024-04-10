#include<cstdio>
const int MAXR = 1e2 + 5;
const int MAXN = 62 + 5;

char id[MAXN];

char s[MAXR][MAXR],ans[MAXR][MAXR];
int ned[MAXN];

void solve(void)
{
	int r,c,n;
	scanf("%d%d%d",&r,&c,&n);
	int m=0;
	for(int i=1; i<=r; ++i)
	{
		scanf("%s",s[i]+1);
		for(int j=1; j<=c; ++j)
			if(s[i][j]=='R') ++m;
	}
	
	int ave = m/n, more=m%n;
	for(int i=1; i<=n; ++i) ned[i]=ave;
	for(int i=1; i<=more; ++i) ++ned[i];
	
	int now=1;
	for(int i=1; i<=r; ++i)
	{
		if(i&1) for(int j=1; j<=c; ++j)
		{
			if(s[i][j]=='R')
			{
				if(!ned[now]) ++now;
				--ned[now];
			}
			ans[i][j] = id[now];
		}
		else for(int j=c; j>=1; --j)
		{
			if(s[i][j]=='R')
			{
				if(!ned[now]) ++now;
				--ned[now];
			}
			ans[i][j] = id[now];
		}
		ans[i][c+1]=0;
	}
	
	for(int i=1; i<=r; ++i) printf("%s\n",ans[i]+1);
}

int main(void)
{
	for(int i=1; i<=26; ++i) id[i] = i-1+'a';
	for(int i=1; i<=26; ++i) id[i+26] = i-1+'A';
	for(int i=1; i<=10; ++i) id[i+52] = i-1+'0';
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}