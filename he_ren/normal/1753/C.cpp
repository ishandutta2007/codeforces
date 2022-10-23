#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
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

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	int d = count(a+1, a+n+1, 0);
	int beg = count(a+1, a+d+1, 0);
	ll tot = (ll)n * (n-1) / 2 %mod;
	
	static int f[MAXN];
	f[d] = 0;
	for(int i=d-1; i>=beg; --i)
		f[i] = (f[i+1] + tot * pw((ll)(d - i) * (d - i) %mod, mod - 2)) %mod;
	
	printf("%d\n",f[beg]);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}