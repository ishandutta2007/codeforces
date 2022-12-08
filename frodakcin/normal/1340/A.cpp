#include <cstdio>

const int MN = 1e5 + 100;
int N, T, a[MN], b[MN];

void solve()
{
	scanf("%d", &N);
	for(int i = 0;i < N;++i)
		scanf("%d", a+i), b[--a[i]] = i;
	int E = N;
	for(int i = 0, j, k;i < N;i += j-b[i])
	{
		for(j = b[i], k = i;j < E;++j, ++k)
		{
			if(a[j] != k)
				return (void) printf("No\n");
		}
		E = b[i];
	}
	printf("Yes\n");
}

int main(void)
{
	scanf("%d", &T);
	for(int i = 0;i < T;++i)
		solve();
	return 0;
}