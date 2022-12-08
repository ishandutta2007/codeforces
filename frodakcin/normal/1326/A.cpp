#include <cstdio>

int T, N;

void solve()
{
	scanf("%d", &N);
	if(N == 1) return (void)printf("-1\n");
	if((N-1)%3 == 0)
		printf("3"), --N;
	for(int i = 0;i < N-1;++i)
		printf("2");
	printf("3\n");
}

int main(void)
{
	scanf("%d", &T);
	for(;T--;)
		solve();
	return 0;
}