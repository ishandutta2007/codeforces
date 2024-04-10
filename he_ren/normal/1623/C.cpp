#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

int n;
int a[MAXN];
ll b[MAXN];

inline bool chk(ll lim)
{
	for(int i=1; i<=n; ++i) b[i] = 0;
	for(int i=n; i>=1; --i)
	{
		if(a[i] + b[i] < lim) return 0;
		if(i <= 2) continue;
		ll d = min((ll)a[i], a[i] + b[i] - lim) / 3;
		b[i-1] += d; b[i-2] += 2 * d;
	}
	return 1;
}

void solve(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	ll l = 0, r = 1e10;
	while(l<r)
	{
		ll mid = (l+r+1)>>1;
		if(chk(mid)) l=mid;
		else r=mid-1;
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