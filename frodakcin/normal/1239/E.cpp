#include <cstdio>
#include <algorithm>

using ll = long long;

const int MN = 28;
const int MV = MN*50000;

int S, V;
int d[MV], p[MV][MN];
ll par(int * a, int L)
{
	for(int i = 0;i < L*2;++i)
		S+=a[i];
	V = S/2;
	d[0] = 1, p[0][0] = -1LL;
	for(int i = 0;i < L*2;++i)
		for(int j = L;j;--j)
			for(int k = V;k >= a[i];--k)
				if(!(d[k]&1<<j) && d[k-a[i]]&1<<j-1)
					d[k]|=1<<j, p[k][j] = i;
	for(int i = V;i >= 0;--i)
		if(d[i]>>L)
		{
			ll r = 0LL;
			for(int v = i, j = L;j;v -= a[p[v][j--]])
				r |= 1LL<<p[v][j];
			return r;
		}
	return -1LL;
}
int N, a[MN*2];

int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N*2;++i)
		scanf("%d", a+i);
	std::sort(a, a+N*2);
	ll x = par(a+2, N-1);
	printf("%d", a[0]);
	for(int i = 0;i < N-1<<1;++i) if(x&1LL<<i) printf(" %d", a[i+2]);
	printf("\n");
	for(int i = (N-1)*2-1;i >= 0;--i) if(!(x&1LL<<i)) printf("%d ", a[i+2]);
	printf("%d\n", a[1]);
	return 0;
}