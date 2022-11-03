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
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e2 + 10;
int a[N][N];
int row[N];
int col[N];
int b[N];
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
			scanf("%d", &a[i][j]);
		}
	}
	for (int o = 1; o <= m + 1; o++)
	{
		int flag = 0;
		for (int k = 0; k < 2; k++)
		{
			MEM(row, 0);
			MEM(col, 0);
			row[1] = k;
			for (int j = 1; j <= m; j++)
			{
				if (j < o)
				{
					if ((a[1][j] ^ k) == 1)
						col[j] = 1;
				}
				else
				{
					if ((a[1][j] ^ k) == 0)
						col[j] = 1;
				}
				b[j] = a[1][j] ^ k ^ col[j];
			}
			flag = 0;
			if (b[m] == 1) flag = 1;
			int ok = 1;
			for (int i = 2; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					b[j] = a[i][j] ^ col[j];
				}
				int cnt0 = count(b + 1, b + m + 1, 0);
				if (cnt0 == m)
				{
					if (flag)
						row[i] = 1;
					continue;
				}
				if (cnt0 == 0)
				{
					if (flag == 0) row[i] = 1;
					continue;
				}
				if (flag)
				{
					ok = 0;
					break;
				}
				int lo = 0, up = 0;
				for (int j = 2; j <= m; j++)
				{
					if (b[j] >= b[j - 1]) up++;
					if (b[j] <= b[j - 1]) lo++;
				}
				if (up == m - 1 || lo == m - 1)
				{
					if (b[1] == 1) row[i] = 1;
					flag = 1;
					continue;
				}
				ok = 0;
				break;
			}
			if (ok == 0)
				continue;
			puts("YES");
			for (int i = 1; i <= n; i++) putchar(row[i] + '0');
			puts("");
			for (int i = 1; i <= m; i++) putchar(col[i] + '0');
			puts("");
			return 0;
		}
	}
	puts("NO");
	return 0;
}