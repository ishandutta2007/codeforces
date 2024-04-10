#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int mod = 1e9 + 7;

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

ll fac[MAXN], inv[MAXN];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int a[MAXN];

void solve(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int t[35];
	for(int i=1; i<=n; ++i)
	{
		a[i] = a[i] & -a[i];
		int cur = 0;
		while(a[i] >> cur) ++cur;
		++t[cur-1];
	}
	
	int ans = 0;
	for(int i=0; i<=30; ++i)
	{
		int sum = 0;
		for(int j=i+1; j<=30; ++j) sum += t[j];
		ll coef = pw(2, sum);
		for(int j=1; j<=t[i]; ++j)
		{
			if(i > 0 && j % 2) continue;
			ans = (ans + C(t[i], j) * coef) %mod;
		}
	}
	printf("%d\n",ans);
}

int main(void)
{
	int T = 1;
	while(T--) solve();
	return 0;
}