#include <cstdio>
#include <algorithm>
using namespace std;
#define N 500000 + 5

int m, k, n, s, cnt, A[N], B[N], Cnt[N], Ans[N], _Cnt[N];
bool ok;

void Add(int x, int del)
{
	if (Cnt[x] > 0) cnt -= Cnt[x];
	Cnt[x] += del;
	if (Cnt[x] > 0) cnt += Cnt[x];
}

int main()
{
	scanf("%d%d%d%d", &m, &k, &n, &s);
	for (int i = 1; i <= m; i ++)
		scanf("%d", A + i);
	for (int i = 1; i <= s; i ++)
	{
		scanf("%d", B + i);
		Cnt[B[i]] ++, cnt ++;
	}
	for (int l = 1, r = 1; !ok && l <= m; l ++)
	{
		for (; r <= m && cnt; r ++)
			Add(A[r], -1);
		if (cnt == 0)
		{
			int block;
			if (r - l >= k)
				block = (l - 1) / k + (m - r + 1) / k + 1;
			else block = (l - 1) / k + (m - l + 1) / k;
			if (block >= n)
			{
				for (int i = 1, _ = (l - 1) % k; i <= _; i ++)
					Ans[++ Ans[0]] = i;
				for (int i = 1; i <= s; i ++)
					_Cnt[B[i]] ++;
				for (int i = l, _cnt = r - l - k; _cnt > 0 && i < r; i ++)
				{
					if (!_Cnt[A[i]])
						Ans[++ Ans[0]] = i, _cnt --;
					else _Cnt[A[i]] --;
				}
				ok = 1;
			}
		}
		Add(A[l], 1);
	}
	if (ok)
	{
		printf("%d\n", Ans[0]);
		for (int i = 1; i <= Ans[0]; i ++)
			printf("%d%c", Ans[i], i == Ans[0] ? '\n' : ' ');
	}
	else puts("-1");
	return 0;
}