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
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
string str = "LRUDX";
int vis[N][N];
pair<int, int> d[N][N];
int tot[N][N];
int cnt = 0;
char ans[N][N];
void dfs(int x, int y, pair<int, int> p, int o = 4)
{
	if (d[x][y] != p) return;
	if (vis[x][y]) return;
	vis[x][y] = 1;
	cnt++;
	ans[x][y] = str[o];
	for (int o = 0; o < 4; o++)
	{
		dfs(x + dx[o], y + dy[o], p, o ^ 1);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			if (x != -1) tot[x][y]++;
			d[i][j] = { x,y };
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (vis[i][j]) continue;
			if (d[i][j].first == -1)
			{
				int flag = 0;
				for (int o = 0; o < 4; o++)
				{
					if (d[i + dx[o]][j + dy[o]] == d[i][j])
					{
						flag = 1;
						dfs(i, j, { -1,-1 }, o);
						break;
					}
				}
				if (flag == 0)
				{
					puts("INVALID");
					return 0;
				}
			}
			else
			{
				cnt = 0;
				int x, y;
				tie(x, y) = d[i][j];
				if (d[i][j] != d[x][y])
				{
					puts("INVALID");
					return 0;
				}
				dfs(x, y, d[i][j]);
				if (cnt != tot[x][y])
				{
					puts("INVALID");
					return 0;
				}
			}
		}
	}
	puts("VALID");
	for (int i = 1; i <= n; i++)
		puts(ans[i] + 1);
	return 0;
}