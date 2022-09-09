#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 3e4 + 5;
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

ll pw2[MAXD];

ll fac[MAXD], inv[MAXD];
inline ll c(int n,int m){ return n<0||m<0||n<m? 0: fac[n] * inv[m] %mod * inv[n-m] %mod;}

namespace FFT
{
	typedef complex<double> cnum;
	const int N = 65536;
	
	cnum omega[N];
	inline void init(void)
	{
		const double pi = acos(-1);
		for(int i=0; i<N; ++i)
			omega[i] = cnum(cos(2 * pi / N * i), sin(2 * pi / N * i));
	}
	inline void dft(cnum a[],int n)
	{
		for(int i=0,j=0; i<n; ++i)
		{
			if(j<i) swap(a[i], a[j]);
			for(int k=n>>1; (j^=k) < k; k>>=1);
		}
		for(int d = 2, step = N >> 1; d <= n; d <<= 1, step >>= 1)
			for(int i = 0, k = d >> 1; i < n; i += d)
				for(int j = i, cur = 0; j < i + k; ++j, cur += step)
				{
					cnum tmp = a[j + k] * omega[cur];
					a[j + k] = a[j] - tmp; a[j] += tmp;
				}
	}
	inline void idft(cnum a[],int n){ dft(a,n); reverse(a+1,a+n);}
	
	inline void regen(cnum f[],cnum a[],cnum b[],int n,bool f_to_ab)
	{
		if(f_to_ab) for(int i=0; i<n; ++i)
		{
			cnum g = f[i? n-i: 0];
			a[i] = cnum(0.5 * (f[i].real() + g.real()), 0.5 * (f[i].imag() - g.imag()));
			b[i] = cnum(0.5 * (f[i].imag() + g.imag()), -0.5 * (f[i].real() - g.real()));
		}
		else for(int i=0; i<n; ++i)
			f[i] = cnum(a[i].real() - b[i].imag(), a[i].imag() + b[i].real());
	}
	
	cnum a[N], b[N], t1[N], t2[N], t3[N], t4[N];
	inline vector<int> mul(const vector<int> &A,const vector<int> &B)
	{
		if(!A.size() || !B.size()) return vector<int>();
		vector<int> res((int)A.size() + (int)B.size() - 1);
		int n = 1;
		while(n < (int)res.size()) n <<= 1;
		
		for(int i=0; i<n; ++i) a[i] = i < (int)A.size()? cnum(A[i] >> 15, A[i] & 32767): cnum(0,0);
		for(int i=0; i<n; ++i) b[i] = i < (int)B.size()? cnum(B[i] >> 15, B[i] & 32767): cnum(0,0);
		dft(a,n); dft(b,n);
		regen(a, t1, t2, n, 1);
		regen(b, t3, t4, n, 1);
		for(int i=0; i<n; ++i)
		{
			cnum c1 = t1[i], c2 = t2[i], c3 = t3[i], c4 = t4[i];
			t1[i] = c1 * c3;
			t2[i] = c1 * c4 + c2 * c3;
			b[i] = c2 * c4;
		}
		regen(a, t1, t2, n, 0);
		idft(a,n); idft(b,n);
		for(int i=0; i<(int)res.size(); ++i)
		{
			ll x = a[i].real() / n + 0.5, y = a[i].imag() / n + 0.5, z = b[i].real() / n + 0.5;
			res[i] = ((x %mod << 30) + (y %mod << 15) + z %mod) %mod;
		}
		return res;
	}
} using FFT::mul;

vector<int> vec_mul(vector<int> a,const vector<int> &b,int y)
{
	ll cur = 1;
	for(int i=0; i<(int)b.size(); ++i)
		a[i] = a[i] * cur %mod, cur = cur * pw2[y] %mod;
	
	vector<int> res = mul(a,b);
	res.resize(a.size());
	return res;
}

int main(void)
{
	pw2[0] = 1;
	for(int i=1; i<MAXD; ++i) pw2[i] = pw2[i-1] * 2 %mod;
	
	fac[0] = 1;
	for(int i=1; i<MAXD; ++i) fac[i] = fac[i-1] * i %mod;
	inv[MAXD-1] = pw(fac[MAXD-1], mod-2);
	for(int i=MAXD-2; i>=0; --i) inv[i] = inv[i+1] * (i+1) %mod;
	
	FFT::init();
	
	ll n;
	int d;
	scanf("%lld%d",&n,&d);
	if(n > d) return printf("0") ,0;
	
	vector<int> f(d+1), g;
	for(int i=1; i<=d; ++i) f[i] = inv[i];
	
	int p = n, fx = 1;
	while(p)
	{
		if(p&1) g = g.size()? vec_mul(g, f, fx): f;
		f = vec_mul(f, f, fx); fx <<= 1; p >>= 1;
	}
	
	ll ans = 0;
	for(int i=0; i<=d; ++i)
		ans = (ans + g[i] * fac[i] %mod * c(d,i)) %mod;
	printf("%lld",ans);
	return 0;
}