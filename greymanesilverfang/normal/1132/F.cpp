#include <cstdio>
#include <algorithm>
const int N = 505;
char s[N];
int l[26], p[N], f[N][N];

int main()
{
	int n; scanf("%d%s", &n, s);
	n = std::unique(s, s + n) - s;
	for (int i = 1; i <= n; ++i)
	{
		int c = s[i - 1] - 'a';
		p[i] = l[c]; l[c] = i;
	}
	for (int r = 1; r <= n; ++r)
		for (int l = r; l >= 1; --l)
		{
			f[l][r] = f[l][r - 1] + 1;
			for (int i = p[r]; i >= l; i = p[i])
				f[l][r] = std::min(f[l][r], f[l][i] + f[i + 1][r - 1]);
		}
	printf("%d", f[1][n]);
	return 0;
}