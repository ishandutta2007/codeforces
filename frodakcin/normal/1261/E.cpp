#include <cstdio>
#include <algorithm>

const int MN = 1e3 + 10;

int N;
int a[MN], c[MN], m[MN], M[MN];
bool x[MN][MN];
bool u;
int main(void)
{
	scanf("%d", &N);
	for(int i = 0;i < N;++i)
		scanf("%d", a+i), c[N+1-a[i]]++, m[i] = i;
	std::sort(m, m+N, [&](int x, int y){return a[x]>a[y];});
	for(int i = 0;i < N;++i)
		M[m[i]] = i;
	for(int i = 0;i < N;++i)
		x[N][i] = 1;
	for(int i = 1;i < N;++i)
	{
		c[i] += c[i-1];
		for(int j = 0;j < c[i];++j)
			x[i][j] = 1;
		if(c[i] < i)
			x[i][i-1] = 1, x[N][i-1] = 0;
		if(c[i] > i)
			x[i][i-1] = 0, x[0][i-1] = 1, u = 1;
	}
	printf("%d\n", N+u);
	for(int i = !u;i <= N;++i)
	{
		for(int j = 0;j < N;++j)
			printf("%d", x[i][M[j]]);
		printf("\n");
	}
	return 0;
}