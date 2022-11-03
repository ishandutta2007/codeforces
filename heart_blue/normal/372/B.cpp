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
const int N = 40 + 10;
int a[N][N][N][N];
int n, m;
int sum[N][N];
void check(int sum[N][N])
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
}
int rec(int ax, int ay, int bx, int by)
{
	if (ax <= bx && ay <= by)
		return sum[bx][by] - sum[ax - 1][by] - sum[bx][ay - 1] + sum[ax - 1][ay - 1] == 0;
	else
		return 0;
}
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str + 1);
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] = str[j] - '0';
		}
	}
	check(sum);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			for (int x = 1; x <= n; x++)
			{
				for (int y = 1; y <= m; y++)
				{
					a[i][j][x][y] = rec(i, j, x, y);
				}
			}
			check(a[i][j]);
		}
	}
	while (q--)
	{
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int ans = 0;
		for (int i = a; i <= c; i++)
		{
			for (int j = b; j <= d; j++)
			{
				ans += ::a[i][j][c][d];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}