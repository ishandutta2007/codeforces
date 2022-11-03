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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 6e1 + 10;
char str[N][N];
int row[N];
int col[N];
int maxv1[N];
int maxv2[N];
int sum1[N][N];
int sum2[N][N];
pair<int, int> a[N], b[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	MEM(sum1, -1);
	MEM(sum2, -1);
	while (ncase--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		MEM(row, 0);
		MEM(col, 0);
		MEM(maxv1, -1);
		MEM(maxv2, -1);
		MEM(a, 0);
		MEM(b, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str[i] + 1);
			for (int j = 1; j <= m; j++)
			{
				sum1[i][j] = sum1[i][j - 1] + 1;
				sum2[i][j] = sum2[i - 1][j] + 1;
				if (str[i][j] == 'A')
				{
					row[i]++, col[j]++;
				}
				else
				{
					sum1[i][j] = sum2[i][j] = -1;
					if (a[i].first == 0) a[i].first = j;
					a[i].second = j;
					if (b[j].first == 0) b[j].first = i;
					b[j].second = i;
				}
				maxv1[j] = max(maxv1[j], sum1[i][j]);
				maxv2[i] = max(maxv2[i], sum2[i][j]);
			}
		}
		if (count(row + 1, row + n + 1, 0) == n)
		{
			puts("MORTAL");
			continue;
		}
		if (count(row + 1, row + n + 1, m) == n)
		{
			puts("0");
			continue;
		}
		if (row[1] == m || row[n] == m || col[1] == n || col[m] == n)
		{
			puts("1");
			continue;
		}
		if (count(row + 1, row + n + 1, m) || count(col + 1, col + m + 1, n))
		{
			puts("2");
			continue;
		}
		int ans = 4;
		if (row[1] || row[n] || col[1] || col[m]) ans = 3;
		if (str[1][1] == 'A' || str[1][m] == 'A' || str[n][1] == 'A' || str[n][m] == 'A')
			ans = 2;
		for (int i = 1; i <= n; i++)
		{
			int l, r;
			tie(l, r) = a[i];
			int flag = 0;
			for (int j = r; j <= n; j++)
			{
				if (maxv1[j] >= j - l)
					flag = 1;

			}
			if (flag)
			{
				if (i == 1 || i == n) ans = min(ans, 2);
				else ans = min(ans, 3);
			}
		}
		for (int i = 1; i <= m; i++)
		{
			int l, r;
			tie(l, r) = b[i];
			int flag = 0;
			for (int j = r; j <= m; j++)
			{
				if (maxv2[j] >= j - l)
				{
					flag = 1;
				}
			}
			if (flag)
			{
				if (i == 1 || i == m) ans = min(ans, 2);
				else ans = min(ans, 3);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}