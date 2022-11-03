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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 5e2 + 10;
char chess[N][N];
int flag[N][N];
int n, m;
int c;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
void dfs(int x, int y)
{
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= m) return;
	if (c == 0) return;
	if (chess[x][y] == '#') return;
	if (flag[x][y]) return;
	flag[x][y] = 1;
	c--;
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dx[i], y + dy[i]);
	}

}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	int s = 0;
	cin >> n >> m >> k;
	int x, y;
	x = -1, y = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> chess[i][j];
			if (chess[i][j] == '.') s++, x = i, y = j;
		}
	}
	c = s - k;
	MEM(flag, 0);
	dfs(x, y);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (chess[i][j] == '.')
			{
				if (flag[i][j]) putchar('.');
				else putchar('X');
			}
			else putchar('#');
		}
		putchar('\n');
	}
	return 0;
}