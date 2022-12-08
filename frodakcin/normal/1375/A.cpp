#include <cstdio>
#include <algorithm>

int N, T, a[101];
int main()
{
	scanf("%d", &T);
	for(int i=0;i<T;++i)
	{
		scanf("%d", &N);
		for(int i=0;i<N;++i) scanf("%d", a+i), printf("%d%c", std::abs(a[i])*(i&1?1:-1), " \n"[i+1==N]);
	}
	return 0;
}