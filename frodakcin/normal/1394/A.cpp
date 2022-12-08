#include <cstdio>
#include <cassert>
#include <algorithm>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}

using ll = long long;

const int MN = 1e5+10;
int N, D, M, L=-1, a[MN], h, l, ex, minh;
ll p[MN], f;

int main()
{
	scanf("%d%d%d", &N, &D, &M);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	std::sort(a, a+N);
	for(int i=0;i<N;++i) p[i+1]=p[i]+a[i];
	for(int i=0;i<N;++i)
		if(a[i]>M)
		{
			L=i;
			break;
		}
	if(!~L)
		return printf("%lld\n", p[N]), 0;
	minh = (N-L+D)/(D+1);
	/*
	if(minh*(D+1)>=N) // L <= D
		return printf("%lld\n", p[N]-p[N-minh]+p[L]);
		*/
	h=minh, l=L, ex=(N-L)-(minh*(D+1)-D);
	f = p[N]-p[N-h]+p[L]-p[L-l];
	//printf("%d %d %d\n", h, l, ex);
	assert(ex>=0 && ex<=D);
	for(;h+L<N;)
	{
		++h;
		l-=D+1-ex;
		ex=0;
		if(l<0)
			break;
		//printf("%d %d, %lld\n", h, l, p[N]-p[N-h]+p[L]-p[L-l]);
		ckmax(f, p[N]-p[N-h]+p[L]-p[L-l]);
	}
	printf("%lld\n", f);
	return 0;
}