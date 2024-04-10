//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
/*
	Template: polynomial V3
	Author: Fizzydavid
	E-mail: fizzydavid@qq.com
	Last edit: 2018/12/11
*/

typedef long long ll;
int mod;
const int maxsize = 270111;
ll qpow (ll x, ll k){return k==0? 1: 1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}

//FFT head - START
const int mod_bitn=30; // must be even; mod<=2^mod_bitn  
struct fft
{
	const double pi = acos(-1);
	struct point
	{
		double x, y;
		point (double _x=0, double _y=0) {x=_x; y=_y;}
		point operator + (const point &t) const {return point(x+t.x, y+t.y);}
		point operator - (const point &t) const {return point(x-t.x, y-t.y);}
		point operator * (const point &t) const {return point(x*t.x-y*t.y, x*t.y+y*t.x);}
		point conj () const {return point(x, -y);}
	};
	point w_pre[maxsize];
	int n, M, inv[maxsize];
	void init()
	{
		M = 1;
		while (M*2<maxsize) M <<= 1;
		for (int i=0; i<=M; i++) w_pre[i] = point(cos(2*pi/M*i), sin(2*pi/M*i));
		inv[1]=1;
		for (int i=2; i<maxsize; i++) inv[i] = mod-1ll*inv[mod%i]*(mod/i)%mod;
	}
	void FFTinit(int sz)
	{
		n = 1;
		while (n<sz) n <<= 1;
		assert(n<=M);
	}
	void FFT(point a[], int coef)
	{
		for (int i=0, j=0; i<n; i++)
		{
			if (i<j) swap(a[i], a[j]);
			for (int l=n>>1; (j^=l)<l; l>>=1) continue;
		}
		static point w[maxsize];
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
					point tmp = a[i+j+l]*w[j];
					a[i+j+l] = (a[i+j]-tmp);
					a[i+j] = (a[i+j]+tmp);
				}
			}
		}
		if (coef==-1)
		{
			for (int i=0; i<n; i++) a[i] = a[i]*(1.0/n);
		}
	}
	vector<int> multi_for_small_mod(const vector<int> &A, const vector<int> &B, int N = -1)
	{
		if (N==-1) N = max(0, int(A.size()+B.size())-1);
		FFTinit(A.size()+B.size());
		static point a[maxsize], b[maxsize];
		for (int i=0; i<n; i++)
		{
			a[i] = i<A.size()? point((A[i]+mod)%mod, 0): 0;
			b[i] = i<B.size()? point((B[i]+mod)%mod, 0): 0;
		}
		FFT(a, 1);
		FFT(b, 1);
		for (int i=0; i<n; i++) a[i] = a[i] * b[i];
		FFT(a, -1);
		vector<int> C; C.resize(N);
		for (int i=0; i<N; i++) C[i] = i>=n? 0: ll(a[i].x+0.5)%mod;
		return C;
	}
	vector<int> multi(const vector<int> &A, const vector<int> &B, int N = -1)
	{
		if (N==-1) N = max(0, int(A.size()+B.size())-1);
		FFTinit(A.size()+B.size());
		static point tl[maxsize], tr[maxsize], ta[maxsize], tb[maxsize];
		int msk = (1<<(mod_bitn/2))-1;
		for (int i=0; i<n; i++)
		{
			ta[i] = i<A.size()? point(((A[i]+mod)%mod)&msk, ((A[i]+mod)%mod)>>(mod_bitn/2)): 0;
			tb[i] = i<B.size()? point(((B[i]+mod)%mod)&msk, ((B[i]+mod)%mod)>>(mod_bitn/2)): 0;
		}
		FFT(ta, 1); ta[n] = ta[0];
		FFT(tb, 1); tb[n] = tb[0];
		for (int i=0; i<n; i++)
		{
			point a0 = (ta[i]+ta[n-i].conj())*point(+0.5,0);
			point a1 = (ta[i]-ta[n-i].conj())*point(0,-0.5);
			point b0 = (tb[i]+tb[n-i].conj())*point(+0.5,0);
			point b1 = (tb[i]-tb[n-i].conj())*point(0,-0.5);
			tl[i] = a0*b0+a0*b1*point(0,1);
			tr[i] = a1*b0+a1*b1*point(0,1);
		}
		FFT(tl, -1);
		FFT(tr, -1);
		vector<int> C; C.resize(N);
		for (int i=0; i<N; i++)
		{
			C[i] = i>=n? 0: (ll(tl[i].x+0.5)%mod+
						   ((ll(tr[i].y+0.5)%mod)<<mod_bitn)+
						  (((ll(tl[i].y+0.5)+ll(tr[i].x+0.5))%mod)<<(mod_bitn/2)))%mod;
		}
		return C;
	}
};
fft MS;
//FFT head - END

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

int Tn;
const int maxn = 411;
int main()
{
	cin>>Tn>>mod;
	MS.init();
	poly F;
	F.reserve(maxn);
	int f = 1;
	for (int i=1; i<maxn; i++) f = 1ll*f*i%mod, F[i] = f;
	poly a = F.serrev()*(-1);
	for (int i=4; i<maxn; i++)
	{
		(a[i] += (i&1? 2: -2)) %= mod;
	}
	while (Tn--)
	{
		int x;
		cin>>x;
		if (x==1) puts("1");
		else if (x==2) puts("2");
		else if (x==3) puts("0");
		else cout<<(a[x]+mod)%mod<<endl;
	}
	return 0;
}