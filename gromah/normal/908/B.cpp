#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100 + 5

const int Fx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, sx, sy, ex, ey, ans, Stack[5];
char s[N], Map[N][N];
bool Flag[5];

bool DFS(int x, int y, int id)
{
	if (~x && ~y && x < n && y < m && Map[x][y] == 'E') return 1;
	if (!~x || !~y || x == n || y == m || Map[x][y] == '#' || !s[id]) return 0;
	int k = Stack[s[id] - '0'];
	DFS(x + Fx[k][0], y + Fx[k][1], id + 1);
}

bool Check()
{
	return DFS(sx, sy, 0);
}

void dfs(int z)
{
	if (z == 4)
	{
		ans += Check();
		return ;
	}
	for (int k = 0; k < 4; k ++)
		if (!Flag[k])
		{
			Flag[k] = 1;
			Stack[z] = k;
			dfs(z + 1);
			Flag[k] = 0;
		}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++)
		scanf("%s", Map[i]);
	scanf("%s", s);
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
		{
			if (Map[i][j] == 'S')
				sx = i, sy = j;
			if (Map[i][j] == 'E')
				ex = i, ey = j;
		}
	dfs(0);
	printf("%d\n", ans);
	return 0;
}