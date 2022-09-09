#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 50 + 5;
const int MAXM = 50 + 5;

int ans[MAXN][MAXM];

void solve(void)
{
	int n,m,a,b;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(n*a != m*b){ printf("NO\n"); return;}
	
	for(int k=0; k<=a; ++k)
	{
		memset(ans,0,sizeof(ans));
		
		for(int i=1; i<=n; ++i)
		{
			int beg = (i-1)*k + 1;
			int now = (beg-1)%m + 1;
			for(int j=1; j<=a; ++j)
			{
				ans[i][now] = 1;
				++now;
				if(now>m) now=1;
			}
		}
		
		bool flag=1;
		for(int i=1; i<=n; ++i)
		{
			int cnt=0;
			for(int j=1; j<=m; ++j)
				cnt += ans[i][j];
			if(cnt!=a){ flag=0; break;}
		}
		if(!flag) continue;
		
		for(int j=1; j<=m; ++j)
		{
			int cnt=0;
			for(int i=1; i<=n; ++i)
				cnt += ans[i][j];
			if(cnt!=b){ flag=0; break;}
		}
		if(!flag) continue;
		
		printf("YES\n");
		for(int i=1; i<=n; ++i, putchar('\n'))
			for(int j=1; j<=m; ++j)
				putchar(ans[i][j] + '0');
		return;
	}
	printf("NO\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}