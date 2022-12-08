#include <cstdio>
#include <algorithm>

const int MN = 1e5+10;
int P, N, a[MN], min, max;
int main()
{
	scanf("%d%d", &N, &P);
	for(int i=0;i<N;++i)
		scanf("%d", a+i);
	std::sort(a, a+N);
	min = -1, max = a[N-1];
	for(int i=0;i<N;++i)
	{
		if(i+P<=N) max = std::min(a[i+P-1]-i, max);
		min = std::max(a[i]-i, min);
	}
	if(max<=min) printf("0\n");
	else
	{
		printf("%d\n", max-min);
		for(int i=min;i<max;++i) printf("%d%c", i, " \n"[i+1==max]);
	}
	return 0;
}