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
const int N = 5e2 + 10;
int n, m;
int cnt;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int flag[N][N];
char board[N][N];
void dfs(int x, int y)
{
	if (flag[x][y]) return;
	if (board[x][y] != '#') return;
	flag[x][y] = 1;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dx[i], y + dy[i]);
	}
}
int getcnt(int o = 1)
{
	if (o) MEM(flag, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] != '#' || flag[i][j]) continue;
			cnt = 0;
			dfs(i, j);
			return cnt;
		}
	}
	return 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}
	}
	int tot = getcnt();
	int ans = 3;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (board[i][j] != '#') continue;
			MEM(flag, 0);
			flag[i][j] = 1;
			int rest = getcnt(0);
			if (rest + 1 != tot)
			{
				puts("1");
				return 0;
			}
			MEM(flag, 0);
			int tmp = 0;
			for (int o = 0; o < 4; o++)
			{
				int x = i + dx[o];
				int y = j + dy[o];
				flag[x][y] = 1;
				if (board[x][y] == '#') tmp++;
			}
			rest = getcnt(0);
			if (tmp == 2 && rest != 0)
			{
				ans = 2;
			}
		}
	}
	if (ans != 2) ans = -1;
	printf("%d\n", ans);
	return 0;
}