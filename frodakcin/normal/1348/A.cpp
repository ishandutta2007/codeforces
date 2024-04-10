#include <cstdio>

int N, T, ans;
int main(void)
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &N);
		ans = 1<<N | (1<<N/2)-2;
		for(int i = N/2;i < N;++i)
			ans -= (1<<i);
		printf("%d\n", ans);
	}
	return 0;
}