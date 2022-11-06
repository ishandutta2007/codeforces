#include <cstdio>
#include <algorithm>
using namespace std;
#define N 500 + 5
#define INF 0x3f3f3f3f

int n, Dp[N][N][26], Min[N][N][2];
char s[N];

int main()
{
	scanf("%d%s", &n, s + 1);
	for (int i = 1; i <= n; i ++)
		for (int j = i; j <= n; j ++)
		{
			for (int c = 0; c < 26; c ++)
				Dp[i][j][c] = INF;
			Min[i][j][0] = Min[i][j][1] = INF;
		}
	for (int len = 1; len <= n; len ++)
		for (int i = 1; i + len - 1 <= n; i ++)
		{
			int j = i + len - 1;
			for (int k = i; k <= j; k ++)
			{
				int c = s[k] - 'a';
				int lhs = min(Dp[i][k - 1][c], Min[i][k - 1][Dp[i][k - 1][c] == Min[i][k - 1][0]] + 1);
				int rhs = min(Dp[k + 1][j][c], Min[k + 1][j][Dp[k + 1][j][c] == Min[k + 1][j][0]] + 1);
				Dp[i][j][c] = min(Dp[i][j][c], lhs + rhs);
			}
			for (int c = 0; c < 26; c ++)
			{
				Min[i][j][1] = min(Min[i][j][1], Dp[i][j][c]);
				if (Min[i][j][1] < Min[i][j][0])
					swap(Min[i][j][0], Min[i][j][1]);
			}
		}
	printf("%d\n", Min[1][n][0] + 1);
	return 0;
}