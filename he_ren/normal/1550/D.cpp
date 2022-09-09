#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;

inline ll pw(ll a,ll b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

ll fac[MAXN], inv[MAXN];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

void solve(void)
{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	
	// < 0: i >= l+k
	// > 0: i <= r-k
	
	int ans = 0;
	int lim = min(1-l, r-n);// l+k <= 1 && r-k >= n
	if(lim >= 1)
		ans = (ll)lim * C(n, n / 2) * (n % 2 == 1? 2: 1) %mod;
	
	for(int k=max(1, lim+1); l+k <= n && r-k >= 1; ++k)
	{
		int rig = n - (l+k) + 1, lef = r-k;
		if(lef + rig < n) break;
		lef = min(lef, n); rig = min(rig, n);
		
		int t = lef + rig - n;
		ans = (ans + C(t, lef - n/2)) %mod;
		if(n % 2 == 1)
			ans = (ans + C(t, lef - (n+1)/2)) %mod;
	}
	
	printf("%d\n",ans);
}

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}