#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5
#define K 100000

int n, L[N], T[N];
LL r, ret, Ans[N], Sum[N];

inline bool Init()
{
	scanf("%d%I64d", &n, &r);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", L + i);
		Sum[i] = Sum[i - 1] + L[i];
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", T + i);
		if (T[i] < L[i]) return 0;
	}
	return 1;
}

int main()
{
	if (!Init())
	{
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i ++)
	{
		if (L[i] <= ret)
		{
			ret -= L[i];
			continue ;
		}
		L[i] -= ret, T[i] -= ret;
		int del = L[i] * 2 - T[i];
		if (del <= 0)
		{
			ret = 0;
			continue ;
		}
		if (del - 1 >= r)
		{
			if (Ans[0] + (del - 1) / r <= K)
			{
				Ans[++ Ans[0]] = max(Sum[i - 1] * 2 - r * (Ans[0] - 1) + ret, Ans[Ans[0] - 1] + r);
				for (int j = 2; r * j + 1 <= del; j ++)
					Ans[++ Ans[0]] = Ans[Ans[0] - 1] + r;
			}
			else Ans[0] += (del - 1) / r;
		}
		if (Ans[0] <= K)
			Ans[++ Ans[0]] = Sum[i] * 2 - r * (Ans[0] - 1) - ((del - 1) % r + 1) * 2;
		else Ans[0] ++;
		ret = r - (del - 1) % r - 1;
	}
	printf("%I64d\n", Ans[0]);
	if (Ans[0] <= K)
	{
		for (int i = 1; i <= Ans[0]; i ++)
			printf("%I64d%c", Ans[i], i == Ans[0] ? '\n' : ' ');
	}
	return 0;
}