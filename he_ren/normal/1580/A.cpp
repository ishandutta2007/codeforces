#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 4e2 + 5;
const int MAXM = 4e2 + 5;
const int inf = 0x3f3f3f3f;

char s[MAXN][MAXM];
int a[MAXN][MAXM], sum[MAXN][MAXM];
inline int get(int xl,int xr,int yl,int yr)
{
	return sum[xr][yr] - sum[xr][yl-1] - sum[xl-1][yr] + sum[xl-1][yl-1];
}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%s",s[i]+1);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
		{
			a[i][j] = s[i][j] - '0';
			sum[i][j] = a[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	
	int ans = inf;
	for(int l=1; l<=n; ++l)
		for(int r=l+4; r<=n; ++r)
		{
			static int val1[MAXN], val2[MAXN];
			for(int i=1; i<=m; ++i)
			{
				val1[i] = (!a[l][i]) + (!a[r][i]) + get(l+1, r-1, i, i);
				val2[i] = (r - l - 1) - get(l+1, r-1, i, i);
				
				val1[i] += val1[i-1];
			}
			
			int mn = inf;
			for(int i=4; i<=m; ++i)
			{
				mn = min(mn, -val1[i-3] + val2[i-3]);
				ans = min(ans, mn + val1[i-1] + val2[i]);
			}
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