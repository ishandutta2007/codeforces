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
const int N = 2e2 + 10;
int dx[] = { 1,1,1,0,0,-1,-1,-1 };
int dy[] = { -1,1,0,-1,1,-1,1,0 };
char board[N][N];
int n = 10;
bool check(int x, int y, int o)
{
	int cnt = 0;
	while (1)
	{
		if (x < 0 || x >= n) break;
		if (y < 0 || y >= n) break;
		if (board[x][y] != 'X') break;
		cnt++;
		x += dx[o];
		y += dy[o];
	}
	return cnt >= 5;
}
bool checkall()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int o = 0; o < 8; o++)
			{
				if (check(i, j, o))
					return true;
			}
		}
	}
	return false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	for (int i = 0; i < 10; i++) cin >> board[i];
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == '.')
			{
				board[i][j] = 'X';
				if (checkall())
				{
					puts("YES");
					return 0;
				}
				board[i][j] = '.';
			}
		}
	}
	puts("NO");
	return 0;
}