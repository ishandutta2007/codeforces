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
const int N = 1e6 + 20;
int n, m;
char datac[N];
int datai[N];
char* str[N];
int* flag[N];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool check(int x, int y)
{
	if (x < 0 || x >= n || y < 0 || y >= m || str[x][y] == '#') return false;
	else return true;
}
void dfs(int x, int y)
{
	if (!check(x, y)) return;
	if (flag[x][y]) return;
	flag[x][y] = 1;
	int cnt = 0;
	for (int o = 0; o < 4; o++)
	{
		if (!check(x + dx[o], y + dy[o])) continue;
		if (str[x + dx[o]][y + dy[o]] == '.')
			cnt++;
	}
	if (cnt > 1 && str[x][y] != 'L') return;
	if (str[x][y] == '.')
		str[x][y] = '+';
	for (int o = 0; o < 4; o++)
	{
		if (!check(x + dx[o], y + dy[o])) continue;
		if (str[x + dx[o]][y + dy[o]] == '.')
		{
			flag[x + dx[o]][y + dy[o]] = 0;
			dfs(x + dx[o], y + dy[o]);
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		scanf("%d%d", &n, &m);
		fill(datai, datai + n * m, 0);
		for (int i = 0; i < n; i++)
			str[i] = datac + i * m, flag[i] = datai + i * m;
		int x = 0, y = 0;
		for (int i = 0; i < n; i++)
		{
			scanf("%s", str[i]);
			for (int j = 0; j < m; j++)
			{
				if (str[i][j] == 'L')
				{
					x = i, y = j;
				}
			}
		}
		dfs(x, y);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				putchar(str[i][j]);
			}
			puts("");
		}
	}
	return 0;

}