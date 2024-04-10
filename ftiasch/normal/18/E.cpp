// Codeforces Beta Round #19
// Problem E -- Flag 2
#include <cstdio>
#include <cstring>
#include <utility>

#define N 500
#define M 26
#define INF 1000000

#define FI first
#define SE second
#define PIII pair<int, pair<int, int> >
#define MP(x, y, z) make_pair(x, make_pair(y, z))

using namespace std;

int n, m, ct[N][2][M];
PIII ul[M][M], ur[M][M], dl[M][M], dr[M][M], dp[N + 1][M][M];
char gp[N][N + 1];

void clear(PIII a[M][M])
{
	for(int i = 0; i != M; ++ i)
	{
		a[0][i] = MP(-INF, 0, i);
		a[i][0] = MP(-INF, i, 0);
		a[M - 1][i] = MP(-INF, M - 1, i);
		a[i][M - 1] = MP(-INF, i, M - 1);
	}
}

PIII max(PIII a, PIII b)
{
	if(a.FI > b.FI)
		return a;
	return b;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(ct, 0, sizeof(ct));
	for(int i = 0; i != n; ++ i)
	{
		scanf("%s", gp[i]);
		for(int j = 0; j != m; ++ j)
			ct[i][j & 1][gp[i][j] - 'a'] ++;
	}
	for(int i = 0; i != M; ++ i)
		for(int j = 0; j != M; ++ j)
			dp[n][i][j] = MP(i == j? -INF: 0, i, j);
	for(int k = n - 1; k != -1; -- k)
	{
		clear(ul);
		for(int i = 1; i != M; ++ i)
			for(int j = 1; j != M; ++ j)
				ul[i][j] = max(MP(dp[k + 1][i - 1][j - 1].FI, i - 1, j - 1), max(ul[i - 1][j], ul[i][j - 1]));
		clear(ur);
		for(int i = 1; i != M; ++ i)
			for(int j = M - 2; j != -1; -- j)
				ur[i][j] = max(MP(dp[k + 1][i - 1][j + 1].FI, i - 1, j + 1), max(ur[i - 1][j], ur[i][j + 1]));
		clear(dl);
		for(int i = M - 2; i != -1; -- i)
			for(int j = 1; j != M; ++ j)
				dl[i][j] = max(MP(dp[k + 1][i + 1][j - 1].FI, i + 1, j - 1), max(dl[i + 1][j], dl[i][j - 1]));
		clear(dr);
		for(int i = M - 2; i != -1; -- i)
			for(int j = M - 2; j != -1; -- j)
				dr[i][j] = max(MP(dp[k + 1][i + 1][j + 1].FI, i + 1, j + 1), max(dr[i + 1][j], dr[i][j + 1]));
		for(int i = 0; i != M; ++ i)
			for(int j = 0; j != M; ++ j)
				if(i == j)
					dp[k][i][j] = MP(-INF, i, j);
				else
				{
					dp[k][i][j] = max(max(ul[i][j], ur[i][j]), max(dl[i][j], dr[i][j]));
					dp[k][i][j].FI += ct[k][0][i] + ct[k][1][j];
				}
	}
	PIII ans = MP(-INF, 0, 0);
	for(int i = 0; i != M; ++ i)
		for(int j = 0; j != M; ++ j)
			ans = max(ans, MP(dp[0][i][j].FI, i, j));
	printf("%d\n", n * m - ans.FI);
	for(int i = 0; i != n; ++ i)
	{
		for(int j = 0; j != m; ++ j)
			printf("%c", 'a' + (j & 1? ans.SE.SE: ans.SE.FI));
		ans = dp[i][ans.SE.FI][ans.SE.SE];
		printf("\n");
	}
	return 0;
}