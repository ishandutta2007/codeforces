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
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int sum[N][N];
char str[N][N];
int cnt1[N];
int cnt2[N];
int getsum(int x1, int y1, int x2, int y2)
{
	return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int lx = INF, rx = 0, ly = INF, ry = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] == 'w')
			{
				sum[i][j] ++, cnt1[i]++, cnt2[j]++;
				lx = min(lx, i);
				rx = max(rx, i);
				ly = min(ly, j);
				ry = max(ry, j);
			}
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	int tot = sum[n][m];
	int len = INF, x = -1, y = -1;
	for (int i = 1; i <= lx; i++)
	{
		for (int j = 1; j <= ly; j++)
		{
			int o = max(rx - i + 1, ry - j + 1);
			for (int k = o; i + k - 1 <= n && j + k - 1 <= m && k < len; k++)
			{
				if (getsum(i, j, i + k - 1, j + k - 1) != tot)
					continue;
				if (k <= 2 || getsum(i + 1, j + 1, i + k - 2, j + k - 2) == 0)
				{
					len = k;
					x = i;
					y = j;
				}
				break;
			}
		}
	}
	if (len == INF) puts("-1");
	else
	{
		for (int i = x; i <= x + len - 1; i++)
		{
			for (int j = y; j <= y + len - 1; j++)
			{
				if (i == x || i == x + len - 1 || j == y || j == y + len - 1)
				{
					if (str[i][j] == '.') str[i][j] = '+';
				}
			}
		}
		for (int i = 1; i <= n; i++)
			puts(str[i] + 1);
	}
	return 0;
}