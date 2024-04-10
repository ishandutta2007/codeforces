#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int maxl = 1e6;
const int MAXL = 1.1e6;

namespace FFT
{
	typedef complex<double> C;
	
	C omega[MAXL];
		
	inline void fft(int n,C a[])
	{
		for(int i=0,j=0; i<n; ++i)
		{
			if(i>j) swap(a[i], a[j]);
			for(int k=n>>1; (j^=k) < k; k>>=1);
		}
		
		for(int len=2, step=n>>1; len<=n; len<<=1, step>>=1)
			for(int i=0, k=len>>1; i<n; i += len)
				for(int j=i, cur=0; j<i+k; ++j, cur += step)
				{
					C tmp = omega[cur] * a[j + k];
					a[j + k] = a[j] - tmp; a[j] += tmp;
				}
	}
	
	inline void mul(int n_,int a_[],int b_[],int res[])
	{
		static C a[MAXL];
		int n = 1;
		while(n < n_) n <<= 1;
		for(int i=0; i<n_; ++i) a[i] = C(a_[i],b_[i]);
		for(int i=n_; i<n; ++i) a[i] = 0;
		
		static int lst_n = -1;
		if(n != lst_n)
		{
			lst_n = n;
			ldb pi = acos(-1);
			omega[0] = C(1,0); omega[1] = C(cos(2 * pi / n), sin(2 * pi / n));
			for(int i=2; i<n; ++i) omega[i] = omega[i-1] * omega[1];
		}
		
		fft(n,a);
		for(int i=0; i<=(n>>1); ++i)
		{
			C p = a[i] + conj(a[(n-i)%n]);
			C q = a[(n-i)%n] - conj(a[i]);
			q = C(q.imag(), q.real());
			a[i] = (p * q) / C(4,0);
			if(i) a[n-i] = conj(a[i]);
		}
		for(int i=0; i<n; ++i) a[i] = conj(a[i]);
		fft(n,a);
		for(int i=0; i<n; ++i) res[i] = round(a[i].real() / n);
	}
};

inline int tidy(int a[])
{
	int res = 0;
	for(int i=0; i<=maxl; ++i)
		if(a[i]) a[i] = 1, res = i;
	return res + 1;
}

int a[MAXN];

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	static int has[MAXL], res[MAXL], mx = 0;
	res[0] = 1;
	for(int i=1; i<=n; ++i)
		has[a[i]] = 1, mx = max(mx, a[i]);
	
	int resl = 1, hasl = mx+1;
	while(d)
	{
		using FFT::mul;
		if(d&1) mul(resl + hasl - 1, res, has, res), resl = tidy(res);
		mul(hasl + hasl - 1, has, has, has); d>>=1;
		hasl = tidy(has);
	}
	
	for(int i=0; i<=maxl; ++i)
		if(res[i]) printf("%d ",i);
	return 0;
}