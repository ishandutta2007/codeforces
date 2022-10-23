#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 100 + 5;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	int mn = *min_element(a+1,a+n+1);
	ll ans = 0;
	for(int i=1; i<=n; ++i)
	{
		int x = 2 * mn - 1;
		ans += (a[i] + x - 1) / x - 1;
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