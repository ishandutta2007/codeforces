//by yjz
#include<bits/stdc++.h>
#define FF first
#define SS second
#define MP make_pair
#define PB push_back
typedef long long ll;
using namespace std;

/*
	Template: polynomial V3
	Author: Fizzydavid
	E-mail: fizzydavid@qq.com
	Last edit: 2018/12/11
*/

typedef long long ll;
const int mod = 998244353;
const int maxsize = 270111*4;
ll qpow (ll x, ll k){return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}

//NTT head - START
const int mod_proot = 3;
template <const int mod, const int proot> struct ntt
{
	int w_pre[maxsize], inv[maxsize];
	int n, M;
	//extra
	ll fac[maxsize], ifac[maxsize];
	
	ntt()
	{
		M = 1;
		while (M*2<maxsize) M <<= 1;
		w_pre[0] = 1;
		int w = qpow(proot, (mod-1)/M);
		for (int i=1; i<=M; i++) w_pre[i] = 1ll*w_pre[i-1]*w%mod;
		inv[1] = 1;
		for (int i=2; i<maxsize; i++) inv[i] = mod-1ll*inv[mod%i]*(mod/i)%mod;
		//extra init
		fac[0] = 1;
		for (int i=1; i<maxsize; i++) fac[i] = fac[i-1]*i%mod;
		ifac[0] = 1;
		for (int i=1; i<maxsize; i++) ifac[i] = ifac[i-1]*inv[i]%mod;
	}
	void FFTinit(int sz)
	{
		n = 1;
		while (n<sz) n <<= 1;
		assert(n<=M);
	}
	void FFT(int a[], int coef)
	{
		typedef unsigned long long ull;
		const ull mod2=1ull*mod*mod;
		static ull na[maxsize];
		for (int i=0, j=0; i<n; i++)
		{
			na[j] = a[i]<0? a[i]+mod: a[i];
			for (int l=n>>1; (j^=l)<l; l>>=1) continue;
		}
		static int w[maxsize];
		for (int l=1; l<n; l<<=1)
		{
			int l2=l+l, u=M/l2;
			if (coef==1)
			{
				for (int j=0, t=0; j<l; j++, t+=u) w[j] = w_pre[t];
			}
			else
			{
				for (int j=0, t=M; j<l; j++, t-=u) w[j] = w_pre[t];
			}
			for (int i=0; i<n; i+=l2)
			{
				for (int j=0; j<l; j++)
				{
					ull tmp = na[i+j+l]%mod*w[j];
					na[i+j+l] = na[i+j]-tmp+mod2;
					na[i+j] += tmp;
				}
			}
			if(l>=16) for (int i=0; i<n; i++) na[i] %= mod;
		}
		if (coef==-1)
		{
			for (int i=0; i<n; i++) a[i] = 1ll*na[i]%mod*inv[n]%mod;
		}
		else
		{
			for (int i=0; i<n; i++) a[i] = na[i]%mod;
		}
	}
	vector<int> multi(const vector<int> &A, const vector<int> &B, int N = -1)
	{
		if (N==-1) N = max(0, int(A.size()+B.size())-1);
		FFTinit(A.size()+B.size());
		static int a[maxsize], b[maxsize];
		for (int i=0; i<n; i++) a[i] = i<A.size()? A[i]%mod: 0;
		for (int i=0; i<n; i++) b[i] = i<B.size()? B[i]%mod: 0;
		FFT(a,1);
		FFT(b,1);
		for (int i=0; i<n; i++) a[i] = 1ll*a[i]*b[i]%mod;
		FFT(a,-1);
		vector<int> ret;
		ret.resize(N);
		for (int i=0; i<N; i++) ret[i] = i<n? a[i]: 0;
		return ret; 
	}
};
ntt <mod, mod_proot> MS;
//NTT head - END

struct poly
{
	vector <int> v;
	int& operator[](const int &t) {return v[t];}
	int size () const{return v.size();}
	void resize (int sz){v.resize(sz);}
	void reserve (int sz){v.resize(max(sz, size()));}
	void shrink (int sz){v.resize(min(sz, size()));}
	void clear (){v.clear();}
	poly (){clear();}
	poly (const vector<int> &t){v = t;}
	poly(int a[], int n)
	{
		v.resize(n);
		for (int i=0; i<n; i++) v[i] = a[i];
	}
	void push_back(const int &t){v.push_back(t);}
	poly operator << (const int &t) const
	{
		poly ret;
		for (int i=0; i<t; i++) ret.PB(0);
		for (int i=0; i<v.size(); i++) ret.PB(v[i]);
		return ret;
	}
	poly operator >> (const int &t) const
	{
		poly ret;
		for (int i=t; i<v.size(); i++) ret.PB(v[i]);
		return ret;
	}
	poly operator * (const poly &t) const
	{
		return MS.multi(v, t.v);
	}
	poly operator * (const int &t) const
	{
		poly ret; ret.resize(size());
		for (int i=0; i<size(); i++) ret[i] = 1ll*v[i]*t%mod;
		return ret;
	}
	poly operator / (const int &t) const
	{
		poly ret; ret.resize(size());
		int inv;
		if (t>=0 && t<maxsize) inv = MS.inv[t]; else inv = qpow(t,mod-2);
		for (int i=0; i<size(); i++) ret[i] = 1ll*v[i]*inv%mod;
		return ret;
	}
	poly operator + (const poly &t) const
	{
		int sz = max(size(), t.size());
		poly ret; ret.resize(sz);
		for (int i=0; i<sz && i<size(); i++) ret[i] = v[i];
		for (int i=0; i<sz && i<t.size(); i++) ret[i] = (ret[i]+t.v[i])%mod;
		return ret;
	}
	poly operator - (const poly &t) const
	{
		int sz = max(size(), t.size());
		poly ret; ret.resize(sz);
		for (int i=0; i<sz && i<size(); i++) ret[i] = v[i];
		for (int i=0; i<sz && i<t.size(); i++) ret[i] = (ret[i]-t.v[i])%mod;
		return ret;
	}
	poly operator - () const
	{
		int sz = size();
		poly ret; ret.resize(sz);
		for (int i=0; i<sz; i++) ret[i] = -v[i];
		return ret;
	}
	poly operator % (int t) const
	{
		poly ret; ret.resize(min(t, size()));
		for (int i=0; i<ret.size(); i++) ret[i] = v[i];
		return ret;
	}
	poly inv(int N=-1) const
	{
		assert(size()>=1 && v[0]%mod!=0);
		poly x({qpow(v[0], mod-2)});
		int sz = size();
		if (N!=-1) sz = N;
		while (x.size() < sz)
		{
			int nsz = x.size()<<1;
			x = x*(poly({2})-((*this)%nsz*x%nsz))%nsz;
			x.reserve(nsz);
		}
		return x%sz;
	}
	poly operator / (const poly &t) const
	{
		int sz = max(size(),t.size());
		return (*this) * (t.inv(sz)) % sz;
	}
	poly itg() const
	{
		int sz = size()+1;
		poly ret; ret.resize(sz);
		for (int i=1; i<sz; i++) ret[i] = 1ll*v[i-1]*MS.inv[i]%mod;
		return ret;
	}
	poly drv() const
	{
		int sz = max(0, size()-1);
		poly ret; ret.resize(sz);
		for (int i=0; i<sz; i++) ret[i] = 1ll*v[i+1]*(i+1)%mod;
		return ret;
	}
	poly ln(int N=-1) const
	{
		assert(size()>0 && (v[0]-1)%mod==0);
		if (N==-1) N = size();
		return (drv()%N*inv(N)).itg()%N;
	}
	poly exp(int N=-1) const
	{
		assert(size()==0 || v[0]%mod==0);
		if (N==-1) N = size();
		poly x({1});
		while (x.size()<N)
		{
			int nsz = x.size()<<1;
			x = x-(x.ln(nsz)-(*this)%nsz)*x%nsz;
			x.reserve(nsz);
		}
		return x%N;
	}
	poly sqrt(int N=-1) const
	{
		assert(size()>0 && (v[0]-1)%mod==0);
		if (N==-1) N = size();
		poly x({1});
		while (x.size()<N)
		{
			int nsz = x.size()<<1;
			x = (x+(*this)%nsz/x)/2%nsz;
			x.reserve(nsz);
		}
		return x%N;
	}
	poly pow(int K, int N=-1) const
	{
		if (N==-1) N = size();
		int it = 0;
		while (it<size() && v[it]%mod==0) it++;
		int coef = it==size()? 0: v[it];
		int icoef = qpow(coef, mod-2);
		ll cnt = 1ll*it*K, m = max(0ll, N-cnt);
		poly p, ret; ret.resize(N);
		for (int i=it; i<N&&i<size(); i++) p.push_back(1ll*v[i]*icoef%mod);
		if (p.size()==0) return ret;
		else
		{
			p = (p.ln(m)*K).exp(m)*qpow(coef,K);
			if (m>0)
			{
				for (int i=0; i<m; i++) ret[cnt+i]=p[i];
			}
		}
		return ret;
	}
	poly serrev(int N = -1) const
	{
		int sz = N!=-1? N: size();
		assert(v.size()>1&&v[0]%mod==0);
		poly f = ((*this)>>1).inv();
		poly p({1}), ret({0});
		for (int i=1; i<sz; i++)
		{
			p = p*f%sz;
			ret.PB(1ll*p[i-1]*MS.inv[i]%mod);
		}
		return ret;
	}
	int serrev_nth(int N) const
	{
		assert(v.size()>1&&v[0]%mod==0);
		poly f = ((*this)>>1).inv();
		return 1ll*f.pow(N,N)[N-1]*MS.inv[N]%mod;
	}
	poly compose(const poly &f, int N=-1) const
	{
		if (N==-1) N = size();
		poly ret, p({1});
		for (int i=0; i<size(); i++)
		{
			ret = ret+p*v[i];
			p = p*f%N;
		}
		return ret%N;
	}
	void debug() const
	{
		cerr<<"poly size="<<size()<<endl;
		for (int i=0; i<size(); i++) cerr<<(v[i]>mod/2? v[i]-mod: (v[i]<-mod/2? v[i]+mod: v[i]))<<" "; cerr<<endl;
	}
	void debugp() const
	{
		cerr<<"poly size="<<size()<<endl;
		for (int i=0; i<size(); i++) cerr<<(v[i]+mod)%mod<<" "; cerr<<endl;
	}
	void out() const
	{
		for (int i=0; i<size(); i++) printf("%d%c", (v[i]+mod)%mod, i+1==size()? '\n': ' ');
	}
	poly ex() const
	{
		poly ret;
		for (int i=0; i<size(); i++) ret.PB(1ll*v[i]*MS.fac[i]%mod);
		return ret;
	}
}; 

poly pdiv(poly A, poly B)
{
	reverse(A.v.begin(), A.v.end());
	reverse(B.v.begin(), B.v.end());
	assert(B.size()>0 && B.v.back()%mod!=0);
	if (A.size()<B.size()) return poly();
	int sz = A.size()-B.size()+1;
	poly ret = ((A%sz)/(B%sz))%sz;
	reverse(ret.v.begin(), ret.v.end());
	return ret;
}
poly pmod(const poly &A, const poly &B)
{
	int sz = B.size()-1;
	return (A-pdiv(A,B)%sz*B)%sz;
}

//polynomial template END
poly getpow(poly P, int n)
{
	poly ret, ret0;
	ret.PB(1);
	for (int i=0; i<(P.size()-1)*n; i++)
	{
		ll cur = 0;
		for (int j=1; j<P.size(); j++)
		{
			if (i-j>=0) cur = (cur+1ll*ret0[i-j]*P[j])%mod; 
		}
		ll cur2 = 0;
		for (int j=0; j+1<P.size(); j++)
		{
			if (i-j>=0) cur2 = (cur2+1ll*ret[i-j]*P[j+1]%mod*(j+1)%mod)%mod;
		}
		ll v = (1ll*cur2*n-cur)%mod*qpow(i+1, mod-2)%mod;
		ret.PB(v);
		ret0.PB(v*(i+1)%mod);
	}
	return ret;
}
int n, K, val[200111];
int main()
{
	scanf("%d%d", &n, &K);
	int cnt = 0;
	for (int i=1; i<=n; i++)
	{
		scanf("%d", &val[i]);
	}
	for (int i=1; i<n; i++) cnt += val[i]!=val[i+1];
	cnt += val[n]!=val[1];
	ll ans = 0;
	poly A (vector<int>{1, (K-2)%mod, 1});
	if (cnt==0)
	{
		A = poly(vector<int> {1});
	}
	else
	{
		A = getpow(A, cnt);
	}
//	A.out();
	for (int i=cnt+1; i<A.size(); i++) ans += A[i];
	ans %= mod;
	for (int i=cnt+1; i<=n; i++) ans = ans*K%mod;
	cout<<(ans%mod+mod)%mod<<endl;
	return 0;
}