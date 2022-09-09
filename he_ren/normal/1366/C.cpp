#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 30 + 5;
const int MAXM = 30 + 5;

int a[MAXN][MAXM];

int cnt[MAXN][2];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			scanf("%d",&a[i][j]);
	
	memset(cnt,0,sizeof(cnt));
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			int dis1 = (i-1) + (j-1);
			int dis2 = (n-i) + (m-j);
			if(dis1 == dis2) continue;
			
			++cnt[min(dis1,dis2)][a[i][j]];
		}
	
	int ans = 0;
	for(int i=0; i<MAXN; ++i)
		ans += min(cnt[i][0], cnt[i][1]);
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}