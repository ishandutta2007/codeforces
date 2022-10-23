#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

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

const int MAXF = MAXN * 2;
ll fac[MAXF], inv[MAXF], pw2[MAXF];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int a[MAXN];
ll pre[MAXN], suf[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	if(n == 1)
	{
		printf("1\n");
		return;
	}
	
	{
		int l = 1, r = n;
		if(a[l] == 0 && a[r] == 0) a[l] = a[r] = 1;
		while(a[l] == 0 && a[r] != 0) ++l;
		while(a[l] != 0 && a[r] == 0) --r;
		
		static int aa[MAXN];
		for(int i=l; i<=r; ++i)
			aa[i-l+1] = a[i];
		n = r-l+1;
		for(int i=1; i<=n; ++i)
			a[i] = aa[i];
	}
	
	pre[0] = suf[n+1] = 0;
	for(int i=1; i<=n; ++i)
		pre[i] = pre[i-1] + a[i];
	for(int i=n; i>=1; --i)
		suf[i] = suf[i+1] + a[i];
	
	static int f[MAXN];
	for(int i=0; i<=n+1; ++i)
		f[i] = 0;
	f[0] = 1;
	f[1] = mod - 1;
	
	int ans = 0;
	assert(n+1 < MAXN);
	a[0] = a[n+1] = 1;
	for(int i=0,j=n+1; i<=n; ++i)
	{
		if(i) add_mod(f[i], f[i-1]);
		while(j>=1 && suf[j] < pre[i]) --j;
		if(j <= i) break;
		
		if(a[i] != 0 && pre[i] == suf[j])
		{
			int ii = i, jj = j;
			while(a[ii+1] == 0) ++ii;
			while(a[jj-1] == 0) --jj;
			
			if(ii+1 == j)
			{
				ans = (ans + (ll)f[i] * (pw2[j-i]-1+mod)) %mod;
			}
			else
			{
				ll nxt = 0;
				for(int k=2; k<=ii-i+2 && k<=j-jj+2; ++k)
					nxt = (nxt + C(ii-i+2-1, k-1) * C(j-jj+2-1, k-1)) %mod;
				nxt = nxt * f[i] %mod;
				add_mod(f[ii+1], nxt);
				add_mod(ans, nxt);
			}
		}
	}
	printf("%d\n",ans);
}

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXF; ++i)
		pw2[i] = pw2[i-1] * 2 %mod;
	
	fac[0] = 1;
	for(int i=1; i<MAXF; ++i)
		fac[i] = fac[i-1] * i %mod;
	inv[MAXF-1] = pw(fac[MAXF-1], mod-2);
	for(int i=MAXF-2; i>=0; --i)
		inv[i] = inv[i+1] * (i+1) %mod;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}