#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const int mod = 1e9 + 7;
const ll inv2 = (mod+1)/2;

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

ll pw2[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	if(n == 1)
	{
		printf("1\n");
		return;
	}
	
	static int f[MAXN], ans[MAXN];
	ans[1] = 0;
	
	for(int i=0; i<=n+1; ++i)
		f[i] = 0;
	f[n] = 1; f[n-1] = mod-1;
	for(int i=n; i>=2; --i)
	{
		add_mod(f[i], f[i+1]);
		add_mod(f[i-1], f[i]);
		add_mod(f[i/2], mod - f[i]);
		
		ans[i] = (ll)pw2[i/2-1] * f[i] %mod;
	}
	
	ll ivn = pw(inv2, n-2);
	for(int i=1; i<=n; ++i)
	{
		ans[i] = (ll)ans[i] * ivn %mod;
		printf("%d\n",ans[i]);
	}
}

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXN; ++i)
		pw2[i] = pw2[i-1] * 2 %mod;
	
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}