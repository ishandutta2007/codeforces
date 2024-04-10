#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

int a[MAXN], b[MAXM];
long long sum[MAXN], mx[MAXN], ans[MAXM];

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	sum[0] = 0;
	mx[0] = 0;
	for(int i=1; i<=n; ++i)
	{
		sum[i] = sum[i-1] + a[i];
		mx[i] = max(mx[i-1], sum[i]);
	}
	
	for(int i=1; i<=m; ++i)
	{
		ans[i] = 0;
		int x = b[i];
		if(x > mx[n])
		{
			if(sum[n] <= 0)
			{
				ans[i] = -1;
				continue;
			}
			
			long long full = (x - mx[n] + sum[n] - 1) / sum[n];
			ans[i] += full * n;
			x -= full * sum[n];
		}
		
		ans[i] += lower_bound(mx, mx+n+1, x) - mx;
		--ans[i];
	}
	
	for(int i=1; i<=m; ++i)
		printf("%lld ",ans[i]);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}