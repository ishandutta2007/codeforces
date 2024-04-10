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
const int N = 7e2 + 10;
int a[N];
int g[N][N];
int flag[N][N];
int gcd(int n, int m)
{
	return m == 0 ? n : gcd(m, n % m);
}


int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			g[i][j] = gcd(a[i], a[j]);
		}
	}
	for (int i = 1; i <= n; i++) flag[i][i] = 1;
	for (int len = 1; len <= n; len++)
	{
		for (int i = 1; i + len <= n; i++)
		{
			int x = i;
			int y = i + len;
			if (g[x][y] != 1)
			{
				flag[x][y] |= flag[y][x + 1];
				flag[y][x] |= flag[x][y - 1];
			}
			if (flag[x][y] && flag[y][x]) continue;
			for (int k = x + 1; k < y; k++)
			{
				if (g[x][k] != 1)
				{
					flag[x][y] |= flag[k][x + 1] & flag[k][y];
				}
				if (g[y][k] != 1)
				{
					flag[y][x] |= flag[k][x] & flag[k][y - 1];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (flag[i][1] && flag[i][n]) ans = 1;
	}
	if (ans) puts("Yes");
	else puts("No");
	return 0;
}