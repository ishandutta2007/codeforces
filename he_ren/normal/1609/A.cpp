#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 15 + 5;

ll a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%lld",&a[i]);
	
	ll t = 1;
	for(int i=1; i<=n; ++i)
		while(a[i] % 2 == 0)
		{
			a[i] /= 2;
			t *= 2;
		}
	
	int pos = max_element(a+1,a+n+1) - a;
	a[pos] *= t;
	
	ll ans = 0;
	for(int i=1; i<=n; ++i) ans += a[i];
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}