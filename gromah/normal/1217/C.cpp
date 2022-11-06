#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define N 200000 + 5

int Case, n, ans, Len[N], Zero[N];
char s[N];

bool Is(int src, int dst, int k)
{
	int x = 0;
	for (int i = src; i < dst; i ++)
		x = x * 2 + s[i] - '0';
	return x == k;
}

int main()
{
	for (int i = 1; i < N; i ++)
		Len[i] = Len[i >> 1] + 1;
	for (int i = 1; i < N; i ++)
		Zero[i] = i - Len[i];
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%s", s + 1);
		n = strlen(s + 1), ans = 0;
		for (int i = 1, last = 0; i <= n; i ++)
			if (s[i] == '1')
			{
				for (int j = 1; Zero[j] <= i - last - 1; j ++)
					if (Is(i, i + Len[j], j))
						ans ++;
				last = i;
			}
		printf("%d\n", ans);
	}
	return 0;
}