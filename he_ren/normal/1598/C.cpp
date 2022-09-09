#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

ll a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	
	ll k = 0;
	for(int i=1; i<=n; ++i)
		k += a[i], a[i] *= n;
	
	map<ll,int> t;
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		ans += t[k - a[i]];
		++t[a[i] - k];
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