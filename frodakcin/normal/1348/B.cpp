#include <cstdio>
#include <algorithm>

const int MN = 1e4 + 100;
int T, N, K, a[MN], V;

int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &N, &K);
		for(int i = 0;i < N;++i)
			scanf("%d", a+i);
		std::sort(a, a+N);
		V = std::unique(a, a+N)-a;
		if(V > K)
		{
			printf("-1\n");
			continue;
		}
		printf("%d\n", N*K);
		for(int i = 0;i < N;++i)
		{
			for(int j = 0;j < V;++j)
				printf("%d ", a[j]);
			for(int j = V;j < K;++j)
				printf("1 ");
		}
		printf("\n");
	}
	return 0;
}