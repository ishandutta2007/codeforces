#include <cstdio>
#include <cstring>
#include <cmath>
#include <complex>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}

using ld = long double;
using cd = std::complex<ld>;

const int MN = 1<<20;
const ld PI = 4*atan((ld)1);

cd rou[MN];

template<bool inv=0>
void fft(cd *a, int N)
{
	for(int i=0;i<1<<N;++i)
	{
		ld ang=2*i*PI/(1<<N);
		if(inv) ang*=-1;
		rou[i]=cd(cos(ang), sin(ang));
	}
	for(int i=0,j;i<1<<N;++i)
	{
		j=0;
		for(int k=0;k<N;++k)
			if(i>>k&1)
				j|=1<<N-k-1;
		if(i<j)
			std::swap(a[i], a[j]);
	}
	for(int l=0;l<N;++l)
		for(int j=0;j<1<<N;j+=1<<l+1)
			for(int k=0;k<1<<l;++k)
			{
				cd d=a[j|1<<l|k]*rou[k<<N-l-1];//cis(k/(1<<l+1))
				a[j|1<<l|k]=a[j|k]-d;
				a[j|k]+=d;
			}
	if(inv)
		for(int i=0;i<1<<N;++i)
			a[i]/=1<<N;
}

int N, X, Y, L, Q, a[MN], ok[MN];
cd pos[MN], neg[MN];

int main()
{
	scanf("%d%d%d", &N, &X, &Y);
	for(int i=0;i<=N;++i)
	{
		scanf("%d", a+i);
		pos[a[i]]={1,0};
		neg[X-a[i]]={1,0};
	}
	L = 31-__builtin_clz(X);
	if(X!=1<<L)++L;
	++L;
	fft(pos, L);
	fft(neg, L);
	for(int i=0;i<1<<L;++i)
		pos[i]*=neg[i];
	fft<1>(pos, L);
	memset(ok, -1, sizeof ok);
	for(int i=X+1;i<=X*2;++i)
		if(std::abs(pos[i])>.95)
			ok[i-X+Y]=i-X+Y;
	for(int i=1;i<MN;++i)
		for(int j=0,mj=(MN-1)/i;j<=mj;++j)
			ckmax(ok[i*j], ok[i]);
	scanf("%d", &Q);
	for(int i=0,x;i<Q;++i)
	{
		scanf("%d", &x);
		if(~ok[x/2]) printf("%d", ok[x/2]*2);
		else printf("-1");
		printf("%c", " \n"[i+1==Q]);
	}
	return 0;
}