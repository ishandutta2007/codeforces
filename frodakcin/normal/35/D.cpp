#include <cstdio>
#include <algorithm>
#include <vector>

const int MN = 1e5+10;
int a[MN], b[MN], N, X;
int main(void)
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d%d", &N, &X);
	for(int i=0;i<N;++i)
	{
		scanf("%d", a+i);
		b[i]=a[i]*(N-i);
	}
	std::sort(b, b+N);
	for(int i=0;i<N;++i)
		if((X-=b[i])<0)
			return printf("%d\n", i), 0;
	printf("%d\n", N);
	return 0;
}