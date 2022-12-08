#include <cstdio>
#include <cassert>

using ll = long long;

const int MN = 1e5+10;
int N;
ll a[MN], x, y;//x*N+y*(N-1) = 1

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
		scanf("%lld", a+i);
	if(N==1)
	{
		printf("1 1\n%lld\n", -a[0]);
		printf("1 1\n0\n");
		printf("1 1\n0\n");
		return 0;
	}
	printf("1 1\n%lld\n", -a[0]);
	a[0]=0;

	x=1, y=-1;
	printf("2 %d\n", N);
	for(int i=1;i<N;++i)
	{
		ll d=-(N-1)*y*a[i];
		printf("%lld%c", d, " \n"[i+1==N]);
		a[i]+=d;
	}
	printf("1 %d\n", N);
	for(int i=0;i<N;++i)
	{
		assert(a[i]%N==0);
		printf("%lld%c", -a[i], " \n"[i+1==N]);
	}
	return 0;
}