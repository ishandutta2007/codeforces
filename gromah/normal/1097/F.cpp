#include <bitset>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100000 + 5
#define M 7000 + 5

int n, m, mu[M], q[M];
bitset <M> B[N], A[M], D[M];
bool Flag[M];

void Prepare()
{
	mu[1] = 1;
	for (int i = 2; i < M; i ++)
	{
		if (!Flag[i])
		{
			q[++ q[0]] = i, mu[i] = -1;
		}
		for (int j = 1; j <= q[0] && i * q[j] < M; j ++)
		{
			Flag[i * q[j]] = 1;
			if (i % q[j] == 0)
			{
				mu[i * q[j]] = 0;
				break ;
			}
			mu[i * q[j]] = -mu[i];
		}
	}
	for (int i = 1; i < M; i ++)
		for (int j = i; j < M; j += i)
		{
			if (mu[j / i] != 0)
				A[i][j] = 1;
			D[j][i] = 1;
		}
}

int main()
{
	Prepare();
	scanf("%d%d", &n, &m);
	for (int i = 1, op; i <= m; i ++)
	{
		scanf("%d", &op);
		if (op == 1)
		{
			int x, v;
			scanf("%d%d", &x, &v);
			B[x] = D[v];
		}
		else if (op == 2)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			B[x] = B[y] ^ B[z];
		}
		else if (op == 3)
		{
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			B[x] = B[y] & B[z];
		}
		else
		{
			int x, v;
			scanf("%d%d", &x, &v);
			B[0] = B[x] & A[v];
			putchar('0' + (B[0].count() & 1));
		}
	}
	puts("");
	return 0;
}