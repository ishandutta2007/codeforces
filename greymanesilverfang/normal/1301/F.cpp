#include <cstdio>
#include <algorithm>
#include <queue>
const int INF = 2000, N = 1001, K = 41;
const int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
int n, m, k;
int a[N][N], min[N][N][K], d[K*2][K*2];
bool chk[N][N];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= k * 2; ++i)
		for (int j = 1; j <= k * 2; ++j)
			d[i][j] = INF;
	for (int i = 1; i <= k; ++i)
		d[i * 2 - 1][i * 2] = 1;
	for (int l = 1; l <= k; ++l)
	{
		std::queue<std::pair<int,int>> q;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
				if (a[i][j] == l)
				{
					q.push(std::make_pair(i, j));
					chk[i][j] = true;
				}
				else 
					chk[i][j] = false;
		while (!q.empty())
		{
			int r = q.front().first;
			int c = q.front().second;
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				int x = r + dx[i];
				int y = c + dy[i];
				if (1 <= x && x <= n && 1 <= y && y <= m && !chk[x][y])
				{
					q.push(std::make_pair(x, y));
					chk[x][y] = true;
					min[x][y][l] = min[r][c][l] + 1;
					d[a[x][y] * 2][l * 2 - 1] = std::min(d[a[x][y] * 2][l * 2 - 1], min[x][y][l]);
				}
			}
		}
	}
	for (int l = 1; l <= 2 * k; ++l)
		for (int i = 1; i <= 2 * k; ++i)
			for (int j = 1; j <= 2 * k; ++j)
			    d[i][j] = std::min(d[i][j], d[i][l] + d[l][j]);
	int q; scanf("%d", &q);
	for (int i = 1; i <= q; ++i)
	{
		int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		int res = std::abs(r1 - r2) + std::abs(c1 - c2);
		for (int i = 1; i <= k; ++i)
			for (int j = 1; j <= k; ++j)
				res = std::min(res, min[r1][c1][i] + min[r2][c2][j] + d[i * 2 - 1][j * 2]);
		printf("%d\n", res);
	}
}