#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

int c[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	
	int mn[2] = {c[2], c[1]};
	ll sum = c[1], ans = linf;
	for(int i=2; i<=n; ++i)
	{
		mn[i&1] = min(mn[i&1], c[i]);
		sum += c[i];
		
		int x = i / 2, y = i - x;
		ans = min(ans, sum + (ll)(n - x) * mn[0] + (ll)(n - y) * mn[1]);
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