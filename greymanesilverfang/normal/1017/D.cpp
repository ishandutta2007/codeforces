#include <cstdio>
char string[12];
int w[12], val[4096], scnt[4096], tcnt[4096], wcnt[4096][102];

int main()
{
	int n, m, q; scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", &w[i]);
	for (int i = 0; i < 1 << n; ++i)
	{
		for (int j = 0; j < n; ++j)
			val[i] += w[n - j - 1] * ((i >> j ^ 1) & 1);
		if (val[i] > 100)
			val[i] = 101;
	}
	for (int i = 0; i < m; ++i)
	{
		scanf("%s", string);
		int s = 0;
		for (int i = 0; i < n; ++i)
			s = s * 2 + string[i] - '0';
		++scnt[s];
	}
	for (int i = 0; i < q; ++i)
	{
		scanf("%s", string);
		int t = 0;
		for (int i = 0; i < n; ++i)
			t = t * 2 + string[i] - '0';
		if (!tcnt[t]++)
		{
			for (int s = 0; s < 1 << n; ++s)
				wcnt[t][val[s ^ t]] += scnt[s];
			for (int wu = 0; wu < 100; ++wu)
				wcnt[t][wu + 1] += wcnt[t][wu];
		}
		int k; scanf("%d", &k);
		printf("%d\n", wcnt[t][k]);
	}
	return 0;
}