#include <cstdio>
#include <algorithm>
using namespace std;
#define N 200000 + 5

int n, s, cnt, ans, Max, A[N], T[N];

int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		if (A[i] == 0 && i != s)
			cnt ++, ans ++;
		else if (A[i] != 0 && i == s)
			ans ++, A[i] = 0;
		else
		{
			T[A[i]] ++;
			Max = max(Max, A[i]);
		}
	}
	bool ok = 0;
	for (int i = 1; cnt && i <= Max; i ++)
	{
		if (!T[i]) T[i] = 1, cnt --;
		if (i == Max) ok = 1;
	}
	if (ok) printf("%d\n", ans);
	else
	{
		for (int i = 1, t = Max; i < t; i ++)
		{
			if (!T[i]) T[i] = 1, T[t] --, ans ++;
			for (; i < t && !T[t]; t --) ;
		}
		printf("%d\n", ans);
	}
	return 0;
}