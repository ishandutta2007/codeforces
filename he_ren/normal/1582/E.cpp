#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXD = 5e2 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[MAXN];
ll sum[MAXN];

ll f[MAXN][MAXD];
int g[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i) sum[i] = sum[i-1] + a[i];
	
	int mxd = 0;
	while(mxd * (mxd + 1) / 2 <= n) ++mxd;
	--mxd;
	
	memset(f[n+1], 0, (mxd+2)<<3);
	g[n+1] = 0; f[n+1][0] = linf;
	for(int i=n; i>=1; --i)
	{
		g[i] = g[i+1];
		memcpy(f[i], f[i+1], (mxd+2)<<3);
		
		f[i][g[i]+1] = 0;
		for(int j=1; j<=g[i]+1 && i+j-1<=n; ++j)
		{
			ll cur = sum[i+j-1] - sum[i-1];
			if(cur < f[i+j][j-1])
				f[i][j] = max(f[i][j], cur);
		}
		if(f[i][g[i]+1]) ++g[i];
	}
	
	printf("%d\n",g[1]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}