#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int mod = 998244353;

inline int gcd(int a,int b){ return b? gcd(b,a%b): a;}
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

inline ll C2(ll n){ return n * (n-1) / 2 %mod;}

ll fac[MAXN], inv[MAXN];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	vector<int> cnt(n+1);
	for(int i=1; i<=n; ++i) ++cnt[a[i]];
	int G = n;
	for(int i=1; i<=n; ++i) G = gcd(G, cnt[i]);
	
	vector<int> bak(n+1);
	for(int i=1; i<=n; ++i) ++bak[cnt[i]];
	if(bak[n])
	{
		printf("1\n");
		return;
	}
	
	vector<pii> mem(n+1, {-1,-1});
	auto getres = [&] (int k)
	{
		if(mem[k] != (pii){-1,-1}) return mem[k];
		if(G % k != 0) return mem[k] = {0,0};
		
		int res2 = fac[n / k];
		for(int i=k; i<=n; i+=k) if(bak[i])
			res2 = res2 * pw(inv[i / k], bak[i]) %mod;
		
		int res1 = 0;
		for(int i=k; i<=n; i+=k) if(bak[i] && i/k >= 2)
		{
			int cur = res2
				* inv[n / k] %mod * fac[i / k] %mod
				* fac[n / k - 2] %mod * inv[i / k - 2] %mod;
			res1 = (res1 + (ll)cur * bak[i]) %mod;
		}
		res1 = (ll)res1 * n %mod;
		res1 = ((ll)n * res2 - res1 + mod) %mod;
		
		return mem[k] = {res1, res2};
	};
	
	pii ans = {0,0};
	for(int i=0; i<n; ++i)
	{
		auto cur = getres(n / gcd(i,n));
		add_mod(ans.first, cur.first);
		add_mod(ans.second, cur.second);
	}
	ans.first = ans.first * pw(n, mod-2) %mod;
	ans.second = ans.second * pw(n, mod-2) %mod;
	printf("%lld\n",ans.first * pw(ans.second, mod-2) %mod);
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