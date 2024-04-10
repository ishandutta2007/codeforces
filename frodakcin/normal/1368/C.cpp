#include <cstdio>

int N;
int main(void)
{
	scanf("%d", &N);
	printf("%d\n", (N+1)*3+1);
	printf("0 0\n");
	for(int i=0;i<=N;++i)
	{
		printf("%d %d\n", i+1, i+1);
		printf("%d %d\n", i, i+1);
		printf("%d %d\n", i+1, i);
	}
	return 0;
}