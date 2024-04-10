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
const int N = 2e3 + 10;
int row[10][N][2];
int col[10][N][2];
int l[N], r[N];
int u[N], d[N];
char str[N];
int solve(int a[N][2], int lo, int hi, int n)
{
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int l = a[i][0];
		int r = a[i][1];
		if (l > r) continue;
		ans = max(ans, (r - l) * max(i - 1, n - i));
		ans = max(ans, max(n - l, r - 1) * max(abs(i - lo), abs(i - hi)));
	}
	return ans;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				row[i][j][0] = INF;
				row[i][j][1] = 0;
				col[i][j][0] = INF;
				col[i][j][1] = 0;
			}
		}
		MEM(l, 0x3f);
		MEM(r, 0);
		MEM(u, 0x3f);
		MEM(d, 0);
		for (int i = 1; i <= n; i++)
		{
			scanf("%s", str + 1);
			for (int j = 1; j <= n; j++)
			{
				int x = str[j] - '0';
				l[x] = min(l[x], j);
				r[x] = max(r[x], j);
				u[x] = min(u[x], i);
				d[x] = max(d[x], i);
				row[x][i][0] = min(row[x][i][0], j);
				row[x][i][1] = max(row[x][i][1], j);
				col[x][j][0] = min(col[x][j][0], i);
				col[x][j][1] = max(col[x][j][1], i);
			}
		}
		for (int i = 0; i < 10; i++)
		{
			printf("%d ", max(solve(row[i], u[i], d[i], n), solve(col[i], l[i], r[i], n)));
		}
		puts("");
	}
	return 0;
}