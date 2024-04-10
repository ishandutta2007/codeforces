#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2.5e5 + 5;
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

namespace Poly
{
	const int g = 3;
	const int N = 524288;
	int omega[N+5];
	inline void init(void)
	{
		omega[0] = 1; omega[1] = pw(g, (mod-1) / N);
		for(int i=2; i<N; ++i) omega[i] = (ll)omega[i-1] * omega[1] %mod;
	}
	inline void dft(int a[],int n)
	{
		for(int i=0,j=0; i<n; ++i)
		{
			if(i<j) swap(a[i],a[j]);
			for(int k=n>>1; (j^=k)<k; k>>=1);
		}
		for(int k=1, step=N>>1; k<n; k<<=1, step>>=1)
			for(int i=0; i<n; i+=k<<1)
				for(int j=i, cur=0; j<i+k; ++j, cur+=step)
				{
					int tmp = (ll)a[j+k] * omega[cur] %mod;
					add_mod(a[j+k] = a[j], mod - tmp); add_mod(a[j], tmp);
				}
	}
	inline void idft(int a[],int n){ dft(a,n); reverse(a+1,a+n);}
	
	int a[N+5], b[N+5];
	inline vector<int> mul(const vector<int> &A,const vector<int> &B)
	{
		if(!A.size() || !B.size()) return vector<int>();
		vector<int> res((int)A.size() + (int)B.size() - 1);
		int n = 1;
		while(n < (int)res.size()) n<<=1;
		for(int i=0; i<n; ++i) a[i] = i<(int)A.size()? A[i]: 0;
		for(int i=0; i<n; ++i) b[i] = i<(int)B.size()? B[i]: 0;
		dft(a,n); dft(b,n);
		for(int i=0; i<n; ++i) a[i] = (ll)a[i] * b[i] %mod;
		idft(a,n);
		ll invn = pw(n,mod-2);
		for(int i=0; i<(int)res.size(); ++i) res[i] = a[i] * invn %mod;
		return res;
	}
} using Poly::mul;

int a[MAXN];

int main(void)
{
	fac[0] = 1;
	for(int i=1; i<MAXN; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXN-1] = pw(fac[MAXN-1], mod - 2);
	for(int i=MAXN-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	Poly::init();
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		++a[u]; ++a[v];
	}
	
	static int cnt[MAXN];
	for(int i=1; i<=n; ++i) ++cnt[a[i] - (i != 1)];
	
	vector<int> f = {1};
	for(int i=n; i>=1; --i) if(cnt[i])
	{
		int x = cnt[i];
		vector<int> g(x + 1);
		ll cur = 1;
		for(int j=0; j<=x; ++j)
		{
			g[j] = C(x,j) * cur %mod;
			cur = cur * i %mod;
		}
		f = mul(f, g);
	}
	
	int ans = 0;
	for(int i=0; i<(int)f.size(); ++i)
	{
		int cur = (ll)f[i] * fac[n-i] %mod;
		if(i&1) add_mod(ans, mod - cur);
		else add_mod(ans, cur);
	}
	printf("%d",ans);
	return 0;
}