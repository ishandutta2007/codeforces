#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

int n;
int a[MAXN];

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	sort(a+1,a+n+1);
	
	ll ans = a[n];
	for(int i=n; i>1; --i) a[i] -= a[i-1];
	
	for(int i=2; i<=n; ++i)
		ans += (ll)-a[i] * (i - 1) * (n - i + 1);
	printf("%lld\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}