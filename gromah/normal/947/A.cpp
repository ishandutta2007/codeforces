#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000000 + 6

int n, Min = 0x3f3f3f3f, F[N], q[N];

void Prepare()
{
	for (int i = 2; i <= n; i ++)
	{
		if (!F[i])
			q[++ q[0]] = F[i] = i;
		for (int j = 1; i * q[j] <= n && j <= q[0]; j ++)
		{
			F[i * q[j]] = q[j];
			if (i % q[j] == 0) break ;
		}
	}
}

void Get(int m)
{
	for (int x = m, last = 0; x > 1; x /= F[x])
		if (last != F[x])
		{
			Min = min(Min, m - F[x] + 1);
			last = F[x];
		}
}

int main()
{
	scanf("%d", &n);
	Prepare();
	for (int x = n, last = 0; x > 1; x /= F[x])
		if (last != F[x])
		{
			for (int i = n - F[x] + 1; i <= n; i ++)
				if (F[i] != i)
					Get(i);
			last = F[x];
		}
	printf("%d\n", Min);
	return 0;
}