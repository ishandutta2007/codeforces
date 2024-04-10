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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
char str[N][N];
int l[N], r[N];
int u[N], d[N];
int flag[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int n, m;
void dfs(int x, int y)
{
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= m) return;
	if (flag[x][y]) return;
	if (str[x][y] == '.') return;
	flag[x][y] = 1;
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dx[i], y + dy[i]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	MEM(u, 0x3f);
	MEM(d, 0);
	MEM(l, 0x3f);
	MEM(r, 0);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str[i]);
		for (int j = 0; j < m; j++)
		{
			if (str[i][j] == '#')
			{
				l[i] = min(l[i], j);
				r[i] = j;
				u[j] = min(u[j], i);
				d[j] = i;
			}
		}
	}
	int inf = 0x3f3f3f3f;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = 0; i < n; i++)
	{
		if (l[i] == inf) cnt1++;
		for (int j = l[i]; j <= r[i]; j++)
		{
			if (str[i][j] == '.')
			{
				puts("-1");
				return 0;
			}
		}
	}
	for (int j = 0; j < m; j++)
	{
		if (u[j] == inf) cnt2++;
		for (int i = u[j]; i <= d[j]; i++)
		{
			if (str[i][j] == '.')
			{
				puts("-1");
				return 0;
			}
		}
	}
	if ((cnt1 > 0) ^ (cnt2 > 0))
	{
		puts("-1");
		return 0;
	}
	int pl = inf;
	int pr = 0;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (pl == inf && l[i] != inf)
		{
			ans++;
		}
		else if (pl != inf && l[i] != inf)
		{
			if (min(pr, r[i]) < max(pl, l[i]))
				ans++;
		}
		pl = l[i];
		pr = r[i];
	}
	printf("%d\n", ans);
	return 0;
}