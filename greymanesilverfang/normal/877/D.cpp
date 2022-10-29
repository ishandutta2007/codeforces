#include <cstdio>
#include <algorithm>
#include <deque>
#define in(l,mid,r) ((l)<=(mid)&&(mid)<=(r))
const int N = 1001, INF = 1e9+7;
const int U = 0, D = 1, L = 2, R = 3;
const int dx[4] = {-1, 1, 0, 0}, 
          dy[4] = {0, 0, -1, 1};
char s[N], c[N][N];
bool chk[N][N][4];
int  dst[N][N][4];
struct TState {
	int x, y, time, energy, direction;
	TState() {}
	TState(int _x, int _y, int _t, int _e, int _d) {
		x = _x; y = _y; time = _t; energy = _e; direction = _d;
	}
} f[2][N * N * 4];

int main()
{
	int m, n, k; scanf("%d%d%d", &m, &n, &k);
	for (int i = 1; i <= m; ++i)
	{
		scanf("%s", s);
		for (int j = 1; j <= n; ++j)
			c[i][j] = s[j - 1];
	}
	int sx, sy, tx, ty; scanf("%d%d%d%d", &sx, &sy, &tx, &ty);
	if (sx == tx && sy == ty)
	{
		printf("0");
		return 0;
	}
	int prv = 0, cur = 1;
	int prv_sz = 0, cur_sz = 0;
	f[cur][++cur_sz] = TState(sx, sy, 0, 0, 0);
	while (cur_sz != 0)
	{
		std::swap(prv, cur);
		std::swap(prv_sz, cur_sz);
		cur_sz = 0;
		for (int i = 1; i <= prv_sz; ++i)
		{
			TState s = f[prv][i];
			int x = s.x;
			int y = s.y;
			int t = s.time;
			int e = s.energy;
			int d = s.direction;
			if (chk[x][y][d])
				continue;
			// printf("%d %d %d %d %d\n", x, y, t, e, d);
			chk[x][y][d] = true;
			dst[x][y][d] = t;
			for (int i = U; i <= R; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				// printf("%d %d\n", nx, ny);
				if (in(1, nx, m) && in(1, ny, n) && c[nx][ny] == '.' && !chk[nx][ny][i])
					if (i == d && e != 0)
						f[prv][++prv_sz] = TState(nx, ny, t, e - 1, i);
					else
						f[cur][++cur_sz] = TState(nx, ny, t + 1, k - 1, i);
			}
		}
	}
	int res = INF;
	for (int i = U; i <= R; ++i)
		if (chk[tx][ty][i])
			res = std::min(res, dst[tx][ty][i]);
	if (res == INF)
		printf("-1");
	else 
		printf("%d", res);
	return 0;
}