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
#include <regex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
LL dp[N][N];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, s;
	scanf("%d%d%d", &n, &m, &s);
	for (int a = 0; a < N; a++)
	{
		for (int b = 0; b < N; b++)
		{
			if ((2 * a + 1) * (2 * b + 1) > s) break;
			for (int c = 0; c < N; c++)
			{
				if (a >= c && (2 * a + 1) * (2 * b + 1) == s)
				{
					dp[a][b] += b + 1;
					continue;
				}
				int sum1 = (a * 2 + 1) * (b * 2 + 1);
				int d = 0;
				int sum2 = (c * 2 + 1) * (d * 2 + 1);
				int sum01 = (min(a, c) * 2 + 1) * (b * 2 + 1);
				int sum02 = (min(a, c) * 2 + 1) * (d * 2 + 1);
				int d1 = -1;
				int d2 = -1;
				int delta = c - min(a, c);
				if ((s - sum1 + sum01) % (c * 2 + 1) == 0)
				{
					int x = (s - sum1 + sum01) / (c * 2 + 1);
					if ((x - 1) >= 0 && (x - 1) % 2 == 0)
					{
						d1 = (x - 1) / 2;
					}
				}
				if (delta != 0 && (s - sum1) % (delta * 2) == 0)
				{
					int x = (s - sum1) / (delta * 2);
					if (x - 1 >= 0 && (x - 1) % 2 == 0)
					{
						d2 = (x - 1) / 2;
					}
				}
				if (d1 < b) d1 = -1;
				if (d2 > b) d2 = -1;
				if (d1 == d2 && d1 >= 0)
				{
					dp[max(a, c)][max(b, d1)] ++;
					//cout << a << ' ' << b << ' ' << c << ' ' << d1 << endl;
					continue;
				}
				if (d1 >= 0 && d1 < N)
				{
					dp[max(a, c)][max(b, d1)]++;
					//cout << a << ' ' << b << ' ' << c << ' ' << d1 << endl;
				}
				if (d2 >= 0 && d2 < N)
				{
					dp[max(a, c)][max(b, d2)]++;
					//cout << a << ' ' << b << ' ' << c << ' ' << d2 << endl;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i > 0)
				dp[i][j] += dp[i - 1][j];
			if (j > 0)
				dp[i][j] += dp[i][j - 1];
			if (i > 0 && j > 0)
				dp[i][j] -= dp[i - 1][j - 1];
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			ans += dp[min(i - 1, n - i)][min(j - 1, m - j)];
		}
	}
	printf("%lld\n", ans);
	return 0;
}