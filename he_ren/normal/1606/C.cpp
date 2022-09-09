#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 10 + 5;

ll pw10[16];

int a[MAXN];

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	++d;
	ll res = 0;
	for(int i=1; i<n && d; ++i)
	{
		ll mx = pw10[a[i+1] - a[i]] - 1;
		mx = min(mx, (ll)d);
		res += pw10[a[i]] * mx;
		d -= mx;
	}
	res += pw10[a[n]] * d;
	
	printf("%lld\n",res);
}

int main(void)
{
	pw10[0] = 1;
	for(int i=1; i<16; ++i) pw10[i] = pw10[i-1] * 10;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}