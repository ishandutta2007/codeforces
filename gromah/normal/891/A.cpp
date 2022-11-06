#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 2000 + 5
#define INF 593119681

int n, Min = INF, A[N], G[N];

int gcd(int x, int y)
{
	return !y ? x : gcd(y, x % y);
}

int Calc(int id)
{
	int res = Min, cnt = 0;
	G[id] = A[id];
	for (int i = id + 1; i <= n; i ++)
		G[i] = gcd(G[i - 1], A[i]);
	for (int i = id - 1; i; i --)
		G[i] = gcd(G[i + 1], A[i]);
	for (int i = 1; i <= n; i ++)
	{
		cnt += ((A[i] > 1) && (i != id));
		if (G[i] == 1) res = min(res, abs(i - id));
	}
	return res + cnt;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= n; i ++)
		Min = min(Min, Calc(i));
	printf("%d\n", Min == INF ? -1 : Min);
	return 0;
}