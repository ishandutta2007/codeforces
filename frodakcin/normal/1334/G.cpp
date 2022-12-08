#include <cstdio>
#include <cmath>
#include <complex>
#include <vector>
#include <algorithm>

using ld = double;
using cd = std::complex<ld>;
const ld PI = 4*atan((ld)1);
const ld EPS = 0.01;//no need to be super small

const int MC = 26;
const int MN = 1 << 18;//1 << 19 for fft

cd rou[MN*2];
template<bool inv> void fft(cd *a, int L)//len = 1<<L
{
	for(int i=0;i<1<<L;++i)
	{
		ld ang=inv?2*PI*i/(1<<L):-2*PI*i/(1<<L);//either sign convention is ok
		rou[i]={cos(ang), sin(ang)};
	}
	for(int i=0,j;i<1<<L;++i)
	{
		j=0;
		for(int k=0;k<L;++k) if(i>>k&1) j|=1<<L-k-1;
		if(i<j) std::swap(a[i], a[j]);
	}
	for(int l=0;l<L;++l)
		for(int i=0;i<1<<L;i+=1<<l+1)
			for(int j=0;j<1<<l;++j)
			{
				cd d=rou[j<<L-l-1]*a[i|1<<l|j];
				a[i|1<<l|j]=a[i|j]-d;
				a[i|j]+=d;
			}
	if(inv)
		for(int i=0;i<1<<L;++i)
			a[i]/=1<<L;
}

int S, T, C, a[MC], g[MN], len[MN], z[MN], v[MN];
char s[MN], t[MN];
bool ok[MN];
cd ft[MN*2], fs[MN*2];
ld mv;

int main()
{
	for(int i=0;i<MC;++i) scanf("%d", a+i), --a[i];
	for(int i=0;i<MC;++i)
		if(!g[i])
		{
			++C;
			int c=0;
			for(int j=i;;j=a[j])
			{
				g[j] = C;
				v[j] = c++;
				if(a[j]==i) break;
			}
			len[C] = c;
		}
	scanf(" %s %s", s, t);
	for(;s[S];++S)s[S]-='a';
	for(;t[T];++T)t[T]-='a';
	//kmp (not z-function. oops, confusing variable names)
	z[0] = 0;
	for(int i=1;i<S;++i)
	{
		z[i]=z[i-1];
		for(;z[i] && g[s[z[i]]] != g[s[i]];) z[i] = z[z[i]-1];
		if(g[s[z[i]]] == g[s[i]]) ++z[i];
	}
	for(int i=0,v=0;i<T;++i)
	{
		for(;v && (v == S || g[s[v]] != g[t[i]]);) v = z[v-1];
		if(g[s[v]] == g[t[i]]) ++v;
		if(v == S) ok[i]=1;//ok is inclusive right bound
	}

	for(int i=0;i<S;++i)
	{
		ld ang = (ld)-PI*(2*v[s[i]]+1)/len[g[s[i]]];
		fs[i] = {cos(ang), sin(ang)};
	}
	std::reverse(fs, fs+S);//convolve
	//for(int i=0;i<S;++i) printf("%.3lf + %.3lf i\n", fs[i].real(), fs[i].imag());
	for(int i=0;i<T;++i)
	{
		ld ang = (ld)PI*(2*v[t[i]])/len[g[t[i]]];
		ft[i] = {cos(ang), sin(ang)};
	}
	//for(int i=0;i<T;++i) printf("%.3lf + %.3lf i\n", ft[i].real(), ft[i].imag());
	int L = 31 - __builtin_clz(T);//in theory should work
	if(T != 1<<L) ++L;

	fft<0>(fs, L);
	fft<0>(ft, L);
	for(int i=0;i<1<<L;++i)
		ft[i]*=fs[i];
	fft<1>(ft, L);
	//for(int i=0;i<1<<L;++i) printf("%.3lf + %.3lf i\n", ft[i].real(), ft[i].imag());

	for(int i=0;i<S-1;++i)
		mv += cos(PI/len[g[t[i]]]);
	for(int i=S-1;i<T;++i)
	{
		mv += cos(PI/len[g[t[i]]]);
		printf("%d", ok[i] && (mv-ft[i].real()<EPS));
		mv -= cos(PI/len[g[t[i-S+1]]]);
	}
	printf("\n");
	return 0;
}