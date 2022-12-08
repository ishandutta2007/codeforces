#include <cstdio>
#include <cassert>

const int MN = 105;
int N, c[MN];
int ans[MN][2];//0 is trip, 1 is stragit

int get(int x)
{
	for(int i = 1;i <= N+1;++i)
		if(i*(i-1)/2 == x)
			return i;
	assert(0);
}

int main(void)
{
	scanf("%d", &N);
	scanf("%d%d", ans[N], ans[N]+1);
	for(int i = N-1;i >= 3;--i)
	{
		printf("+ %d\n", i);
		fflush(stdout);
		scanf("%d%d", ans[i], ans[i]+1);
	}
	printf("+ 1\n");
	fflush(stdout);
	scanf("%d%d", ans[2], ans[2]+1);
	printf("+ 2\n");
	fflush(stdout);
	scanf("%d%d", ans[1], ans[1]+1);
	printf("+ 1\n");
	fflush(stdout);
	scanf("%d%d", ans[0], ans[0]+1);

	c[1] = get(ans[0][0] - ans[1][0])-1;
	c[3] = (ans[0][1] - ans[1][1]) - (ans[2][1] - ans[3][1]) - 1;
	c[2] = (ans[2][1] - ans[3][1]) / (c[3] + 1);
	c[4] = (ans[1][1] - ans[2][1]) / (c[3] + 1) - (c[1] + 1) - 1;
	for(int i = 5;i <= N;++i)
		c[i] = ((ans[i-2][1] - ans[i-1][1]) - (c[i-1]+1)*c[i-3] - c[i-3]*c[i-4])/(c[i-1]+1) - 1;
	++c[N];
	printf("!");
	for(int i = 1;i <= N;++i)
		printf(" %d", c[i]);
	printf("\n");
	return 0;
}