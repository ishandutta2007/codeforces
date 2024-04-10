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
int flag[N][N][4][3];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int n, m;
char board[N][N];
void dfs(int x, int y, int o, int turn)
{
	if (turn > 2) return;
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= m) return;
	if (flag[x][y][o][turn]) return;
	flag[x][y][o][turn] = 1;
	if (board[x][y] == '*') return;
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dx[i], y + dy[i], i, turn + (i != o));
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	int sx, sy, tx, ty;
	sx = sy = tx = ty = 0;
	MEM(flag, 0);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin >> ch;
			board[i][j] = ch;
			if (ch == 'S')
			{
				sx = i, sy = j;
			}
			else if (ch == 'T')
			{
				tx = i, ty = j;
			}
		}
	}
	for (int i = 0; i < 4; i++)
		dfs(sx, sy, i, 0);
	for (int o = 0; o < 4; o++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (flag[tx][ty][o][i])
			{
				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}