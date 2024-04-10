#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXD = 2e5 + 5;
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

ll fac[MAXN], inv[MAXN];
inline ll C(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

struct BIT
{
	int tree[MAXD], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=n)
			add_mod(tree[x], k),
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			add_mod(res, tree[x]),
			x ^= lowbit(x);
		return res;
	}
}tree;

int a[MAXN], b[MAXN];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod-2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<=m; ++i) scanf("%d",&b[i]);
	
	const int d = 2e5;
	tree.n = d;
	
	static int bak[MAXD];
	for(int i=1; i<=n; ++i) ++bak[a[i]];
	
	ll prod = 1;
	for(int i=1; i<=d; ++i)
	{
		prod = prod * inv[bak[i]] %mod;
		if(bak[i] >= 1)
			tree.update(i, (ll)fac[bak[i]] * inv[bak[i]-1] %mod);
	}
	
	ll ans = 0;
	int rem = n;
	for(int i=1; i<=m; ++i)
	{
		if(i == n+1)
		{
			if(m > n)
				ans = (ans + 1) %mod;
			break;
		}
		if(rem == 0) break;
		
		ans = (ans + (ll)fac[rem-1] * prod %mod * tree.query(b[i]-1)) %mod;
		if(!bak[b[i]]) break;
		
		int &x = bak[b[i]];
		prod = prod * fac[x] %mod;
		tree.update(b[i], mod - (ll)fac[x] * inv[x-1] %mod);
		
		--rem; --x;
		prod = prod * inv[x] %mod;
		if(x >= 1)
			tree.update(b[i], (ll)fac[x] * inv[x-1] %mod);
	}
	
	printf("%lld",ans);
	return 0;
}