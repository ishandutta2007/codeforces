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
#include <iterator>
#include <complex>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int flag[N][N];
int f[N][N][4];
char c[N][N];
int ans[N*N];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
int dfs(int x, int y, int cur, int o = -1)
{
	if (c[x][y] == '*')
	{
		if (f[x][y][o] != cur)
		{
			f[x][y][o] = cur;
			return 1;
		}
		return 0;
	}
	if (flag[x][y]) return 0;
	flag[x][y] = cur;
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		ret += dfs(x + dx[i], y + dy[i], cur, i);
	}
	return ret;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, q;
	cin >> n >> m >> q;
	MEM(c, '*');
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
		}
	}
	MEM(flag, 0);
	MEM(f, 0);
	int k = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (flag[i][j]) continue;
			if (c[i][j] == '*') continue;
			ans[k] = dfs(i, j, k);
			k++;
		}
	}
	while (q--)
	{
		int x, y;
		cin >> x >> y;
		cout << ans[flag[x][y]] << '\n';
	}
	return 0;
}