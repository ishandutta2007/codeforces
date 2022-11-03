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
int flag[N][N];
char c[N][N];
int edge;
int node;
int cur;
char color;
int n, m;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y)
{
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= m) return;
	if (c[x][y] != color) return;
	edge++;
	if (flag[x][y]) return;
	node++;
	flag[x][y] = cur;
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dx[i], y + dy[i]);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	MEM(flag, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c[i][j];
		}
	}
	cur = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (flag[i][j]) continue;
			node = edge = 0;
			cur++;
			color = c[i][j];
			dfs(i, j);
			edge /= 2;
			if (edge >= node)
			{
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}