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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int u[N][N];
int d[N][N];
int l[N];
int r[N];
char str[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] == str[i - 1][j])
				u[i][j] = u[i - 1][j] + 1;
			else
				u[i][j] = 1;
		}
	}
	for (int i = n; i >= 1; i--)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] == str[i + 1][j])
				d[i][j] = d[i + 1][j] + 1;
			else
				d[i][j] = 1;
		}
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (str[i][j] != str[i][j - 1])
			{
				l[j] = 1;
			}
			else
			{
				l[j] = min(l[j - 1] + 1, min(u[i][j], d[i][j]));
			}
		}
		for (int j = m; j >= 1; j--)
		{
			if (str[i][j] != str[i][j + 1])
			{
				r[j] = 1;
			}
			else
			{
				r[j] = min(r[j + 1] + 1, min(u[i][j], d[i][j]));
			}
		}
		for (int j = 1; j <= m; j++)
		{
			ans += min(l[j], r[j]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}