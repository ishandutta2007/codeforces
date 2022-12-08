#include <cstdio>
#include <algorithm>

const int MN = 2e5 + 100;
int N, a[MN];
int x, k;

int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;++i)
	{
		scanf("%d", &k);
		a[i] = k + x;
		x = std::max(x, a[i]);
	}
	for(int i = 0;i < N;++i)
		printf("%d%c", a[i], " \n"[i == N-1]);
	return 0;
}