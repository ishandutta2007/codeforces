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
const int N = 1e3 + 10;
int a[N][N];
int L[N][N];
int R[N][N];
int U[N][N];
int D[N][N];
int n, m;
void buildrow(int x)
{
	for (int i = 1; i <= m; i++)
	{
		L[x][i] = 0;
		if (a[x][i] == 1) L[x][i] = L[x][i - 1] + 1;
	}
	for (int i = m; i >= 1; i--)
	{
		R[x][i] = 0;
		if (a[x][i] == 1) R[x][i] = R[x][i + 1] + 1;
	}
}
void buildcol(int x)
{
	for (int i = 1; i <= n; i++)
	{
		U[i][x] = 0;
		if (a[i][x] == 1) U[i][x] = U[i - 1][x] + 1;
	}
	for (int i = n; i >= 1; i--)
	{
		D[i][x] = 0;
		if (a[i][x] == 1) D[i][x] = D[i + 1][x] + 1;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) buildrow(i);
	for (int i = 1; i <= m; i++) buildcol(i);
	while (q--)
	{
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (op == 1)
		{
			a[x][y] ^= 1;
			buildrow(x);
			buildcol(y);
			continue;
		}
		int ans = 0;
		{
			int minv1 = L[x][y], minv2 = R[x][y];
			for (int i = x; i <= n; i++)
			{
				minv1 = min(minv1, L[i][y]);
				minv2 = min(minv2, R[i][y]);
				ans = max(ans, (minv1 + minv2 - 1) * (i - x + 1));
			}
		}
		{
			int minv1 = L[x][y], minv2 = R[x][y];
			for (int i = x; i >= 1; i--)
			{
				minv1 = min(minv1, L[i][y]);
				minv2 = min(minv2, R[i][y]);
				ans = max(ans, (minv1 + minv2 - 1) * (x - i + 1));
			}
		}
		{
			int minv1 = U[x][y], minv2 = D[x][y];
			for (int i = y; i <= m; i++)
			{
				minv1 = min(minv1, U[x][i]);
				minv2 = min(minv2, D[x][i]);
				ans = max(ans, (minv1 + minv2 - 1) * (i - y + 1));
			}
		}
		{
			int minv1 = U[x][y], minv2 = D[x][y];
			for (int i = y; i >= 1; i--)
			{
				minv1 = min(minv1, U[x][i]);
				minv2 = min(minv2, D[x][i]);
				ans = max(ans, (minv1 + minv2 - 1) * (y - i + 1));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}