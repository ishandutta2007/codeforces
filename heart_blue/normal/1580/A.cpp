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
const int N = 4e2 + 10;
char str[N];
int sum[N][N];
int getsum(int r1, int c1, int r2, int c2)
{
	return sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1];
}
int gethalf(int i, int j, int k)
{
	int tot = getsum(1, j + 1, i - 1, k - 1);
	tot += k - j - 1 - getsum(i, j + 1, i, k - 1);
	tot += i - 1 - getsum(1, j, i - 1, j);
	tot += i - 1 - getsum(1, k, i - 1, k);
	return tot;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str + 1);
			for (int j = 1; j <= m; j++)
			{
				sum[i][j] = str[j] - '0' + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			}
		}
		int ans = INF;
		for (int j = 1; j <= m; j++)
		{
			for (int k = j + 3; k <= m; k++)
			{
				pair<int, int> minv = { n * m,n * m };
				for (int i = n - 4; i >= 1; i--)
				{
					int tot = gethalf(i + 4, j, k);
					minv = min(minv, { tot,i + 4 });
					int u = i;
					int d = minv.second;
					int sum = getsum(u + 1, j + 1, d - 1, k - 1);
					sum += k - j - 1 - getsum(u, j + 1, u, k - 1);
					sum += k - j - 1 - getsum(d, j + 1, d, k - 1);
					sum += d - u - 1 - getsum(u + 1, j, d - 1, j);
					sum += d - u - 1 - getsum(u + 1, k, d - 1, k);
					ans = min(ans, sum);
				}

			}
		}
		printf("%d\n", ans);
	}
	return 0;
}