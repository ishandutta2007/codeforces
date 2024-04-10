// Codeforces Beta Round #46
// Problem E -- Common ancestor
#include <cstdio>
#include <cstring>

#define N 50
#define C 26
#define INF 999
#define BIT(x) (1 << (x))

using namespace std;

int n, l[2], cb[2][N][N], a[N], b[N], c[N], f[N + 1][N + 1];
char s[2][N + 1], bf[10];

int main()
{
	scanf("%s%s%d", s[0], s[1], &n);
	for(int i = 0; i != n; ++ i)
	{
		scanf("%s", bf);
		a[i] = bf[0] - 'a', b[i] = bf[3] - 'a', c[i] = bf[4] - 'a';
	}
	memset(cb, 0, sizeof(cb));
	for(int p = 0; p != 2; ++ p)
	{
		int m = l[p] = strlen(s[p]);
		for(int i = 0; i != m; ++ i)
			cb[p][i][i] = BIT(s[p][i] - 'a');
		for(int d = 1; d != m; ++ d)
			for(int i = 0; i + d != m; ++ i)
			{
				int j = i + d;
				for(int k = i; k != j; ++ k)
					for(int l = 0; l != n; ++ l)
						if((cb[p][i][k] & BIT(b[l])) && (cb[p][k + 1][j] & BIT(c[l])))
							cb[p][i][j] |= BIT(a[l]);
			}
	}
	for(int i = 0; i <= l[0]; ++ i)
		for(int j = 0; j <= l[1]; ++ j)
			f[i][j] = INF;
	f[0][0] = 0;
	for(int i = 1; i <= l[0]; ++ i)
		for(int j = 1; j <= l[1]; ++ j)
			for(int k = 0; k < i; ++ k)
				for(int l = 0; l < j; ++ l)
					if((cb[0][k][i - 1] & cb[1][l][j - 1]) && f[k][l] + 1 < f[i][j])
						f[i][j] = f[k][l] + 1;
	printf("%d\n", f[l[0]][l[1]] < INF? f[l[0]][l[1]]: -1);
	return 0;
}