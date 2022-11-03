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
const int N = 10 + 10;
char board[N][N][N];
int flag[N][N][N];
int dx[] = { 0,0,0,1,1,1,-1,-1,-1 };
int dy[] = { 0,1,-1,1,-1,0,1,-1,0 };
int n, m;
bool dfs(int o, int x, int y)
{
	if (x < 0 || x >= n) return false;
	if (y < 0 || y >= m) return false;
	if (o >= 0 && board[o][x][y] == 'S') return false;
	o++;
	if (board[o][x][y] == 'S') return false;
	if (flag[o][x][y]) return false;
	flag[o][x][y] = 1;
	if (o == 8) return true;
	for (int i = 0; i < 9; i++)
	{
		if (dfs(o, x + dx[i], y + dy[i]))
			return true;
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(board, '.');
	n = m = 8;
	for (int i = 0; i < 8; i++)
	{
		cin >> board[0][i];
	}
	board[0][7][0] = '.';
	board[0][0][7] = '.';
	for (int i = 1; i <= 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			memcpy(board[i][j], board[i - 1][j - 1], sizeof(board[i][j]));
		}
	}
	if (dfs(-1, 7, 0)) puts("WIN");
	else puts("LOSE");
	return 0;
}