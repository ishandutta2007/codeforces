#include <cstdio>
#include <algorithm>
using namespace std;
#define N 500 + 5
#define M 250000 + 5

const int Fx[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, k, cnt, ans, Max, Size[M], T[M], Id[M], Col[N][N];
char ch;
bool Map[N][N];

inline void dfs(int x, int y, int id)
{
	if (Col[x][y] == id) return ;
	Col[x][y] = id, Size[id] ++;
	for (int k = 0; k < 4; k ++)
	{
		int tx = x + Fx[k][0], ty = y + Fx[k][1];
		if (tx && ty && tx <= n && ty <= n && Map[tx][ty])
			dfs(tx, ty, id);
	}
}

inline void Modify(int x, int op, int id)
{
	if (Id[x] == id && T[x]) ans -= Size[x];
	if (Id[x] != id) Id[x] = id, T[x] = 0;
	T[x] += op;
	if (T[x]) ans += Size[x];
}

int main()
{
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
		{
			for (ch = getchar(); ch != '.' && ch != 'X'; ch = getchar()) ;
			Map[i][j] = ch == '.';
		}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if (!Col[i][j] && Map[i][j])
				dfs(i, j, ++ cnt);
	for (int i = 1; i + k - 1 <= n; i ++)
		for (int j = 1; j + k - 1 <= n; j ++)
		{
			if (j == 1)
			{
				ans = 0;
				for (int _i = i - 1; _i <= i + k; _i ++)
					for (int _j = j - 1; _j <= j + k; _j ++)
					{
						if (((_i != i - 1 && _i != i + k) || (_j != j - 1 && _j != j + k)) && Col[_i][_j])
							Modify(Col[_i][_j], 1, i);
						if (_i >= i && _i < i + k && _j >= j && _j < j + k && !Map[_i][_j]) ans ++;
					}
				Max = max(Max, ans);
				continue ;
			}
			for (int _i = i - 1; _i <= i + k; _i ++)
			{
				int op = (_i != i - 1 && _i != i + k);
				int _j = j - 1 - op;
				if (Col[_i][_j]) Modify(Col[_i][_j], -1, i);
				_j = j + k - 1 + op;
				if (Col[_i][_j]) Modify(Col[_i][_j], 1, i);
			}
			for (int _i = i; _i < i + k; _i ++)
			{
				int _j = j - 1;
				if (!Col[_i][_j]) ans --;
				_j = j + k - 1;
				if (!Col[_i][_j]) ans ++;
			}
			Max = max(Max, ans);
		}
	printf("%d\n", Max);
	return 0;
}