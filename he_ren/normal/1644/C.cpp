#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;

int a[MAXN];
ll f[MAXN];

void solve(void)
{
	int n,x;
	scanf("%d%d",&n,&x);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	memset(f, 0xc0, sizeof(f));
	f[0] = 0;
	for(int i=1; i<=n; ++i)
	{
		ll cur = 0;
		for(int j=i; j<=n; ++j)
		{
			cur += a[j];
			f[j-i+1] = max(f[j-i+1], cur);
		}
	}
	
	for(int k=0; k<=n; ++k)
	{
		ll ans = 0;
		for(int i=1; i<=n; ++i)
			ans = max(ans, f[i] + (ll)min(i,k) * x);
		printf("%lld ",ans);
	}
	printf("\n");
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}