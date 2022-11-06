#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 100 + 5

int m, n, Len[N], A[N];
char s[N][N], Ans[N];
bool Flag[N];

int main()
{
	scanf("%d%d", &m, &n);
	for (int i = 1; i <= m; i ++)
	{
		scanf("%s", s[i]);
		Len[i] = strlen(s[i]);
	}
	for (int i = 1; i <= n; i ++)
	{
		scanf("%d", A + i);
		Flag[A[i]] = 1;
	}
	bool ok = 1;
	for (int i = 1; ok && i < n; i ++)
		ok = Len[A[i]] == Len[A[n]];
	if (!ok) puts("No");
	else
	{
		for (int j = 0; j < Len[A[n]]; j ++)
		{
			Ans[j] = s[A[n]][j];
			for (int i = 1; Ans[j] != '?' && i < n; i ++)
				if (s[A[i]][j] != Ans[j]) Ans[j] = '?';
		}
		for (int i = 1; ok && i <= m; i ++)
		{
			if (Flag[i]) continue ;
			ok = Len[i] != Len[A[n]];
			for (int j = 0; !ok && j < Len[A[n]]; j ++)
				ok = Ans[j] != '?' && Ans[j] != s[i][j];
		}
		if (!ok) puts("No");
		else printf("Yes\n%s\n", Ans);
	}
	return 0;
}