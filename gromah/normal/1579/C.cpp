#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100 + 5

int Case, n, m, k;
char s[N][N];
bool Flag[N][N];

int main()
{
	for (scanf("%d", &Case); Case; Case --)
	{
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 1; i <= n; i ++)
			scanf("%s", s[i] + 1);
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				Flag[i][j] = false;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				if (s[i][j] == '*')
				{
					int l = 0, r = 0;
					for (; i > l && j > l && s[i - l - 1][j - l - 1] == '*'; l ++) ;
					for (; i > r && j + r + 1 <= m && s[i - r - 1][j + r + 1] == '*'; r ++) ;
					int sz = min(l, r);
					if (sz >= k)
					{
						for (int t = 0; t <= sz; t ++)
						{
							Flag[i - t][j - t] = true;
							Flag[i - t][j + t] = true;
						}
					}
				}
		bool ok = true;
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				if (s[i][j] == '*' && !Flag[i][j])
					ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}