#include <cstdio>
#include <cassert>

const int MN = 1e6 + 10;
int N;


struct range
{
public:
	int s;
	double v;
};
range wt(range a, range b)
{
	return {a.s + b.s, (a.v*a.s+b.v*b.s)/(a.s+b.s)};
}

range b[MN];
int B;

int main(void)
{
	scanf("%d", &N);
	for(int i = 0, x;i < N;++i)
	{
		scanf(" %d", &x);
		b[B++] = {1, (double)x};
		for(;B > 1 && b[B-1].v < b[B-2].v;--B)
			b[B-2] = wt(b[B-1], b[B-2]);
	}
	for(int i = 0;i < B;++i)
		for(int j = 0;j < b[i].s;++j)
			printf("%.12f\n", b[i].v);
	return 0;
}