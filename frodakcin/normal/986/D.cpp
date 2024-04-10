//what a terrible problem!

#include <cstdio>
#include <cassert>
#include <cmath>
#include <vector>
#include <complex>
#include <algorithm>

template<typename T> bool ckmin(T& a, T b) {return b<a?a=b,1:0;}

const int MN = 1 << 21;
using ld = double;
const ld PI = 4*atan((ld)1);
const ld EPS = 0.1;
using cd = std::complex<ld>;

template<int V> void mul(std::vector<int>& x)//c is small
{
	int c=0;
	for(int i=0;i<x.size();++i)
	{
		x[i]*=V;
		x[i]+=c;
		if(x[i]>=100)
		{
			c=x[i]/100;
			x[i]-=c*100;
		}
		else
			c=0;
	}
	if(c) x.push_back(c);
}

void fft(std::vector<cd>& x, bool inv = 0)
{
	int L = 31 - __builtin_clz(x.size());
	assert(x.size() == 1<<L);

	std::vector<cd> rou(1<<L, 0);
	for(int i=0;i<1<<L;++i)
	{
		ld ang = inv?-2*PI*i/(1<<L):2*PI*i/(1<<L);
		rou[i]={cos(ang), sin(ang)};
	}
	for(int i=0,j;i<1<<L;++i)
	{
		j=0;
		for(int k=0;k<L;++k) if(i>>k&1) j|=1<<L-k-1;
		if(i<j) std::swap(x[i], x[j]);
	}
	for(int l=0;l<L;++l)
		for(int i=0;i<1<<L;i+=1<<l+1)
			for(int j=0;j<1<<l;++j)
			{
				cd d = rou[j<<L-l-1] * x[i|1<<l|j];
				x[i|1<<l|j] = x[i|j] - d;
				x[i|j] += d;
			}
	if(inv)
		for(int i=0;i<1<<L;++i)
			x[i] /= 1<<L;
}
std::vector<cd> tmp;
void sqr(std::vector<int>& x)
{
	int L = 33 - __builtin_clz(x.size());//next (strictly) larger power of 2 + 1
	tmp.assign(1<<L, {0,0});
	for(int i=0;i<x.size();++i)
		tmp[i]={(ld)x[i], 0};
	fft(tmp);
	for(auto& x : tmp) x*=x;
	fft(tmp, 1);
	for(int i=tmp.size()-1, c=0;i>=0;--i)
	{
		assert(tmp[i].imag() < EPS);
		if(!c&&tmp[i].real() > EPS)
			c=1, x.resize(i+1, 0);
		if(c)
			x[i]=(int)round(tmp[i].real());
	}
	for(int i=0;i<x.size();++i)
		if(x[i]>=100)
		{
			if(i+1==x.size()) x.push_back(0);
			x[i+1]+=x[i]/100, x[i]%=100;
		}
}

int N, f;
char s[MN];
std::vector<int> a, v[2];

bool good(const std::vector<int>& x)
{
	assert(x.back() != 0);
	if(x.size() != a.size()) return x.size() > a.size();
	for(int i=a.size()-1;i>=0;--i)
		if(x[i] != a[i])
			return x[i] > a[i];
	return 1;
}

int main()
{
	scanf(" %s", s);
	for(;s[N];++N);
	if(N == 1 && s[0] == '1') return printf("1\n"), 0;
	tmp.reserve(N/3+10);
	a.reserve(N/3+10);
	v[0].reserve(N/3+10);
	v[1].reserve(N/3+10);

	for(int i=N-1;i>=0;i-=2)
	{
		a.push_back(0);
		for(int j=1;j>=0;--j)
			if(i-j>=0)
				a.back() = a.back()*10+s[i-j]-'0';
	}
	int p = (int)floor(N*log((ld)10)/log((ld)3));
	p=std::max(0, p-3);
	v[0]={1};
	for(int i=30, nf=0;i>=0;--i)
	{
		if(nf) sqr(v[0]);
		if(p>>i&1)
			mul<3>(v[0]), nf=1;
	}
	
	f = (int)1e9+7;
	for(int i=0;i<8;++i)
	{
		v[1] = v[0];
		if(good(v[1])) ckmin(f, 3*p);
		mul<2>(v[1]);
		if(good(v[1])) ckmin(f, 3*p+2);
		mul<2>(v[1]);
		if(good(v[1])) ckmin(f, 3*p+4);

		mul<3>(v[0]), ++p;
	}
	printf("%d\n", f);
	return 0;
}