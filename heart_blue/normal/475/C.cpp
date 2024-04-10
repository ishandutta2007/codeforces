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
const int N = 3e3 + 10;
char str[N][N];
int sum[N][N];
inline int getsum(int x1, int y1, int len1, int len2)
{
	int x2 = x1 + len1 - 1;
	int y2 = y1 + len2 - 1;
	return sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int x = n;
	int y = m;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			sum[i][j] = str[i][j] == 'X';
			if (str[i][j] == 'X')
				x = min(x, i), y = min(y, j);
		}
	}
	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < N; j++)
		{
			sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	int tot = getsum(1, 1, n, m);
	if (tot == 0)
	{
		puts("1");
		return 0;
	}
	int ans = INF;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int a = x, b = y;
			int res = i * j;
			if (res >= ans) break;
			if (getsum(a, b, i, j) != res) continue;
			int cur = res;
			while (1)
			{
				int dsum = getsum(a + 1, b, i, j);
				int rsum = getsum(a, b + 1, i, j);
				if (dsum == res && rsum == res)
				{
					break;
				}
				if (dsum == res)
				{
					cur += j;
					a++;
				}
				else if (rsum == res)
				{
					cur += i;
					b++;
				}
				else break;
			}
			if (cur == tot)
				ans = res;
		}
	}
	if (ans == INF)
		ans = -1;
	printf("%d\n", ans);
	return 0;
}