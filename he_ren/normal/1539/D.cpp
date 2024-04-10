#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN = 1e5 + 5;

pll p[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%lld%lld",&p[i].second,&p[i].first);
	
	sort(p+1,p+n+1);
	reverse(p+1,p+n+1);
	
	ll suma = 0;
	for(int i=1; i<=n; ++i) suma += p[i].second;
	
	ll ans = 2 * suma, rem = suma;
	for(int i=1; i<=n; ++i)
	{
		ll cur = max(0ll, min(rem - p[i].first, p[i].second));
		ans -= cur;
		rem -= cur;
	}
	printf("%lld",ans);
	return 0;
}