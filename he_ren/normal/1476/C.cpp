#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int c[MAXN], a[MAXN], b[MAXN];
ll f[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	ll ans = 0;
	f[1] = -linf;
	for(int i=2; i<=n; ++i)
	{
		if(a[i] < b[i]) swap(a[i], b[i]);
		f[i] = c[i]-1 + 2 + (a[i] - b[i]);
		if(a[i] != b[i]) f[i] = max(f[i], f[i-1] - (a[i] - b[i]) + 2 + c[i]-1);
		ans = max(ans, f[i]);
	}
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}