#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <random>
#include <numeric>
#include <algorithm>

std::mt19937 rng;

const int MN = (1 << 11) + 10;

int get(int x, int y)
{
	assert(x!=y);
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	if(!~r) exit(0);
	return r;
}
int N, a[MN],x,y,v,u, f[MN];
int main(void)
{
	rng = std::mt19937(std::time(0));
	scanf("%d", &N);
	std::iota(a, a+N, 1);
	std::shuffle(a, a+N, rng);
	x=a[0],y=a[1],v=get(x, y);
	for(int i=2;i<N;++i)
	{
		u=get(x, a[i]);
		if(u<v)
			y=a[i], v=u;
		else if(u==v)
			x=a[i], v=get(x, y);
	}
	std::shuffle(a, a+N, rng);
	for(int i=0;i<N;++i)
	{
		if(a[i] == x || a[i] == y)
			continue;
		u=get(a[i],x);
		v=get(a[i],y);
		if(u==v) continue;
		if(u>v) std::swap(x, y);
		break;
	}
	for(int i=1;i<=N;++i)
		if(x==i)
			f[i]=0;
		else
			f[i]=get(x, i);
	printf("!");
	for(int i=1;i<=N;++i)
		printf(" %d", f[i]);
	printf("\n");
	return 0;
}