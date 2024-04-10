#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e3 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int a[MAXN], s[MAXN];
ll f[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&s[i]);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i) f[i] = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int j=i-1; j>=1; --j) if(a[j] != a[i])
		{
			ll lst = f[i];
			f[i] = max(f[i], f[j] + abs(s[i] - s[j]));
			f[j] = max(f[j], lst + abs(s[i] - s[j]));
			ans = max(ans, f[j]);
		}
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