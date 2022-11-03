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
const int N = 1e2 + 10;
int ans[N][N];
void check(int x1, int y1, int x2, int y2)
{
	int x[2] = { x1,x2 };
	int y[2] = { y1,y2 };
	map<int, int> mc;
	for (int o = 0; o < 2; o++)
	{
		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				mc[ans[x[o] + i][y[o] + j]] = 1;
			}
		}
	}
	int ret = -1;
	for (int i = 0; i < 26; i++)
	{
		if (mc[i] == 0)
		{
			ret = i;
			break;
		}
	}
	ans[x1][y1] = ret;
	ans[x2][y2] = ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int l = 0, r = 0;
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		if (n & 1) l += m / 2, r += m / 2;
		r += (n / 2) * (m / 2) * 2;
		if (l <= k && k <= r && (k - l) % 2 == 0)
		{
			MEM(ans, -1);
			puts("YES");
			if (n & 1)
			{
				for (int i = 1; i <= m; i += 2)
				{
					check(n, i, n, i + 1);
				}
				k -= m / 2;
			}
			if (m & 1)
			{
				for (int i = 1; i <= n; i += 2)
				{
					check(i, m, i + 1, m);
				}
			}
			for (int i = 1; i <= n / 2 * 2; i += 2)
			{
				for (int j = 1; j <= m / 2 * 2; j += 2)
				{
					if (k > 0)
					{
						check(i, j, i, j + 1);
						check(i + 1, j, i + 1, j + 1);
						k -= 2;
					}
					else
					{
						check(i, j, i + 1, j);
						check(i, j + 1, i + 1, j + 1);
					}
				}
			}
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					putchar(ans[i][j] + 'a');
				}
				puts("");
			}
		}
		else puts("NO");
	}
	return 0;
}