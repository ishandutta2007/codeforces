#include <cstdio>
#include <algorithm>

int N, K, a[101000];
int main(void)
{
	scanf("%d%d", &N, &K);
	for(int i=1,x;i<=N;++i)
	{
		scanf("%d", &x);
		a[i] = std::min(N, i+K) - std::max(0, i-K-1);
		if(x)
			a[i] += a[x] - std::max(0, std::min(N, (x+K))-std::max(0,(i-K-1)));
		printf("%d%c", a[i], " \n"[i==N]);
	}
	return 0;
}