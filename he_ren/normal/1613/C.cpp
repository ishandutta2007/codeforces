#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;

int n;
int a[MAXN];

inline ll calc(ll k)
{
	ll res = k;
	for(int i=1; i<n; ++i)
		res += min(k, (ll)a[i+1] - a[i]);
	return res;
}

void solve(void)
{
	ll h;
	scanf("%d%lld",&n,&h);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll l = 0, r = h;
	while(l<r)
	{
		ll mid = (l+r)>>1;
		if(calc(mid) >= h) r = mid;
		else l = mid + 1;
	}
	printf("%lld\n",l);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}