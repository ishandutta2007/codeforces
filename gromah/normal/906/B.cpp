#include <map>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef pair <int, int> Pii;
#define N 100000 + 5
#define mp make_pair

const int Fx[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int n, m, Map[N];
map <Pii, bool> Flag;

int Get(int x, int y)
{
	return (x - 1) * m + y;
}

int main()
{
	scanf("%d%d", &n, &m);
	if (n == 1 && m == 1)
	{
		puts("YES");
		puts("1");
		return 0;
	}
	for (int i = 1, t = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++, t ++)
			Map[Get(i, j)] = t;
/*	Flag.clear();
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++)
			for (int k = 0; k < 4; k ++)
			{
				int x = i + Fx[k][0], y = j + Fx[k][1];
				if (!x || !y || x > n || y > m) continue ;
				int u = Map[Get(i, j)], v = Map[Get(x, y)];
				Flag[mp(u, v)] = Flag[mp(v, u)] = 1;
			}*/
	if (n * m <= 6 && n <= 3 && m <= 3) puts("NO");
	else
	{
		puts("YES");
		if (m > 3 && n > 1)
		{
			for (int i = 1; i <= n; i += 2)
			{
				int a = Map[Get(i, m - 1)], b = Map[Get(i, m)];
				for (int j = m; j >= 3; j --)
					Map[Get(i, j)] = Map[Get(i, j - 2)];
				Map[Get(i, 1)] = a, Map[Get(i, 2)] = b;
			}
			for (int j = 1; j <= m; j += 2)
			{
				int a = Map[Get(n, j)];
				for (int i = n; i >= 2; i --)
					Map[Get(i, j)] = Map[Get(i - 1, j)];
				Map[Get(1, j)] = a;
			}
		}
		else if (n > 3 && m > 1)
		{
			for (int i = 1; i <= m; i += 2)
			{
				int a = Map[Get(n - 1, i)], b = Map[Get(n, i)];
				for (int j = n; j >= 3; j --)
					Map[Get(j, i)] = Map[Get(j - 2, i)];
				Map[Get(1, i)] = a, Map[Get(2, i)] = b;
			}
			for (int i = 1; i <= n; i += 2)
			{
				int a = Map[Get(i, m)];
				for (int j = m; j >= 2; j --)
					Map[Get(i, j)] = Map[Get(i, j - 1)];
				Map[Get(i, 1)] = a;
			}
		}
		else if (n == 3 && m == 3)
		{
			puts("5 9 3");
			puts("7 2 4");
			puts("1 6 8");
			return 0;
		}
		else if (n == 1)
		{
			int t = 0;
			for (int j = 2; j <= m; j += 2)
				Map[Get(1, ++ t)] = j;
			for (int j = 1; j <= m; j += 2)
				Map[Get(1, ++ t)] = j;
		}
		else if (m == 1)
		{
			int t = 0;
			for (int j = 2; j <= n; j += 2)
				Map[Get(++ t, 1)] = j;
			for (int j = 1; j <= n; j += 2)
				Map[Get(++ t, 1)] = j;
		}
	/*	for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				for (int k = 0; k < 4; k ++)
				{
					int x = i + Fx[k][0], y = j + Fx[k][1];
					if (!x || !y || x > n || y > m) continue ;
					int u = Map[Get(i, j)], v = Map[Get(x, y)];
					if (Flag[mp(u, v)]) {puts("MMP"); printf("%d %d\n", n, m); while(1);}
				}*/
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= m; j ++)
				printf("%d%c", Map[Get(i, j)], j == m ? '\n' : ' ');
	}
	return 0;
}