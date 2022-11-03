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
const int N = 6e1 + 10;
int a[N][N][N];
int b[N][N];
int n, m;
void floyd()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
			}
		}
	}
}
void solve()
{
	for (int o = 1; o <= n; o++)
	{
		for (int k = 1; k <= n; k++)
		{
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					a[o][i][j] = min(a[o][i][j], a[0][i][k] + a[o - 1][k][j]);
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[o][i][j] = min(a[o][i][j], a[o - 1][i][j]);
			}
		}
	}
	
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d%d%d", &n, &m, &q);
	MEM(a, 0x3f);
	for (int o = 1; o <= m; o++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				scanf("%d", &b[i][j]);
			}
		}
		floyd();
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[0][i][j] = min(a[0][i][j], b[i][j]);
			}
		}
	}
	solve();
	while (q--)
	{
		int s, t, k;
		scanf("%d%d%d", &s, &t, &k);
		k = min(k, n);
		printf("%d\n", a[k][s][t]);
	}
	return 0;
}