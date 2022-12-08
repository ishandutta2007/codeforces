#include <cstdio>
#include <cstring>
#include <cmath>
#include <complex>
#include <algorithm>

using ld = long double;
using cd = std::complex<ld>;
using ll = long long;

const ld PI = 4*atan((ld)1);
const int MN = 1e5+10;
const int MV = 1 << 18;
cd rou[2][MV];
int sw[MV];

void prepare(int L)
{
	for(int i=0;i<1<<L;++i)
		for(int k=0;k<L;++k)
			if(i>>k&1) sw[i]|=1<<L-k-1;
	for(int i=0;i<1<<L;++i)
	{
		ld ang=2*PI*i/(1<<L);
		rou[0][i]={cos(ang), sin(ang)};
		rou[1][i]={cos(-ang), sin(-ang)};
	}
}

template<bool inv=0>
void fft(cd *a, int L)
{
	for(int i=0;i<1<<L;++i)
		if(i<sw[i]) std::swap(a[i], a[sw[i]]);
	for(int l=0;l<L;++l)
		for(int i=0;i<1<<L;i+=1<<l+1)
			for(int j=0;j<1<<l;++j)
			{
				cd d=a[i|1<<l|j]*rou[inv][j<<L-l-1];
				a[i|1<<l|j]=a[i|j]-d;
				a[i|j]+=d;
			}
	if(inv)
		for(int i=0;i<1<<L;++i) a[i]/=1<<L;
}

const int L = 18;
int N, M, Q, a[MN], b[MN];
ll f[MV], ctr;
cd norm[2][MV], min[2][MV], max[2][MV], fin[MV];

void mul(cd *p, cd *q)
{
	for(int i=0;i<1<<L;++i) fin[i]=p[i]*q[i];
	fft<1>(fin, L);
}

int main()
{
	prepare(L);
	scanf("%d%d%d", &N, &M, &Q);
	for(int i=0;i<N;++i) scanf("%d", a+i);
	for(int i=0;i<M;++i) scanf("%d", b+i);

	for(int i=0;i<N;++i)
	{
		norm[0][a[i]]+=cd{1,0};
		if(i)
		{
			min[0][std::min(a[i], a[i-1])]+=cd{1,0};
			max[0][std::max(a[i], a[i-1])]+=cd{1,0};
		}
	}
	for(int i=0;i<M;++i)
	{
		norm[1][b[i]]+=cd{1,0};
		if(i)
		{
			min[1][std::min(b[i], b[i-1])]+=cd{1,0};
			max[1][std::max(b[i], b[i-1])]+=cd{1,0};
		}
	}
	fft(norm[0], L);
	fft(norm[1], L);
	fft(min[0], L);
	fft(min[1], L);
	fft(max[0], L);
	fft(max[1], L);

	//V
	mul(norm[0], norm[1]);
	for(int i=0;i+1<1<<L;++i) f[i+1] -= ctr += (ll)round(fin[i].real()); ctr=0;
	for(int i=(1<<L)-1;i>=0;--i) f[i] += ctr += (ll)round(fin[i].real()); ctr=0;

	//HOT
	//Q
	mul(max[0], max[1]);
	for(int i=(1<<L)-1;i>=0;--i) f[i] += ctr += (ll)round(fin[i].real()); ctr=0;
	//E, one direction
	mul(max[0], norm[1]);
	for(int i=(1<<L)-1;i>=0;--i) f[i] -= ctr += (ll)round(fin[i].real()); ctr=0;
	//E, other direction
	mul(norm[0], max[1]);
	for(int i=(1<<L)-1;i>=0;--i) f[i] -= ctr += (ll)round(fin[i].real()); ctr=0;

	//COLD
	//Q
	mul(min[0], min[1]);
	for(int i=0;i+1<1<<L;++i) f[i+1] -= ctr += (ll)round(fin[i].real()); ctr=0;
	//E, one direction
	mul(min[0], norm[1]);
	for(int i=0;i+1<1<<L;++i) f[i+1] += ctr += (ll)round(fin[i].real()); ctr=0;
	//E, other direction
	mul(norm[0], min[1]);
	for(int i=0;i+1<1<<L;++i) f[i+1] += ctr += (ll)round(fin[i].real()); ctr=0;

	for(int i=0,x;i<Q;++i)
	{
		scanf("%d", &x);
		printf("%lld\n", f[x]);
	}
	return 0;
}