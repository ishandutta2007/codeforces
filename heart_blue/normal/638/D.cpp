#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
char str[N][N][N];
int n, m, k;
int dx[] = { 0,0,-1 };
int dy[] = { 0,-1,0 };
int dz[] = { -1,0,0 };
int check(int a, int b, int c, int x, int y, int z)
{
	int flag[3][3][3];
	MEM(flag, 0);
	if (a < 1 || b < 1 || c < 1) return 0;
	if (x > n || y > m || z > k) return 0;
	if (str[a][b][c] == '0') return 0;
	if (str[x][y][z] == '0') return 0;
	flag[0][0][0] = 1;
	for (int i = 0; i <= x - a; i++)
	{
		for (int j = 0; j <= y - b; j++)
		{
			for (int t = 0; t <= z - c; t++)
			{
				if (str[a + i][b + j][c + t] == '0') continue;
				for (int o = 0; o < 3; o++)
				{
					if (i + dx[o] < 0 || j + dy[o] < 0 || t + dz[o] < 0) continue;
					flag[i][j][t] |= flag[i + dx[o]][j + dy[o]][t + dz[o]];
				}
			}
		}
	}
	return flag[x - a][y - b][z - c];
}
int check(int x, int y, int z)
{
	if (str[x][y][z] == '0') return 0;
	for (int a1 = 0; a1 >= -1; a1--)
	{
		for (int a2 = 0; a2 >= -1; a2--)
		{
			for (int a3 = 0; a3 >= -1; a3--)
			{
				if (a1 == 0 && a2 == 0 && a3 == 0) continue;
				int flag = 0;
				for (int b1 = 0; b1 <= 1; b1++)
				{
					for (int b2 = 0; b2 <= 1; b2++)
					{
						for (int b3 = 0; b3 <= 1; b3++)
						{
							if (b1 == 0 && b2 == 0 && b3 == 0) continue;
							if (!check(a1 + x, a2 + y, a3 + z, b1 + x, b2 + y, b3 + z)) continue;
							str[x][y][z] = '0';
							flag |= !check(a1 + x, a2 + y, a3 + z, b1 + x, b2 + y, b3 + z);
							str[x][y][z] = '1';
							if (flag)
								return 1;
						}
					}
				}
			}
		}
	}
	return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%s", str[i][j] + 1);
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int t = 1; t <= k; t++)
			{
				ans += check(i, j, t);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}