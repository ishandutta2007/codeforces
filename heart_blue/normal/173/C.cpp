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
const int N = 5e2 + 10;
int a[N / 2][N][N];
int sum[N][N];
inline int getsum(int ax, int ay, int bx, int by)
{
	return sum[bx][by] - sum[bx][ay - 1] - sum[ax - 1][by] + sum[ax - 1][ay - 1];
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[0][i][j]);
			sum[i][j] = a[0][i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}
	int ans = -INF;
	for (int o = 1; o <= min(n, m); o++)
	{
		int len = 2 * o + 1;
		for (int i = 1; i + len - 1 <= n; i++)
		{
			for (int j = 1; j + len - 1 <= m; j++)
			{
				a[o][i][j] = getsum(i, j, i + len - 1, j + len - 1) - a[o - 1][i + 1][j + 1] - a[0][i + 1][j];
				ans = max(ans, a[o][i][j]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}