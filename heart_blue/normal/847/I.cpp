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
#define MEM(x, y) memset((x),(y),sizeof(x))
const LL INF = 1e9 + 7;
const int N = 3e2 + 10;
vector<vector<int>> vs;
int n, m;
char board[N][N];
int flag[N][N];
int power[N][N];
int ans[N][N];
int ks = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int p, q;
void solve(int x, int y)
{
	ks++;
	queue<pair<int, int>> qu;
	qu.push({ x,y });
	flag[x][y] = ks;
	power[x][y] = (board[x][y] - 'A' + 1)*q;
	ans[x][y] += power[x][y];
	while (!qu.empty())
	{
		int x, y;
		tie(x, y) = qu.front();
		qu.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 0 || tx >= n) continue;
			if (ty < 0 || ty >= m) continue;
			if (board[tx][ty] == '*') continue;
			if (flag[tx][ty] == ks) continue;
			flag[tx][ty] = ks;
			power[tx][ty] = power[x][y] >> 1;
			ans[tx][ty] += power[tx][ty];
			if (power[tx][ty] != 0)
			{
				qu.push({ tx,ty });
			}
		}
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m >> q >> p;
	MEM(flag, 0);
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (isalpha(board[i][j]))
			{
				solve(i, j);
			}
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ans[i][j] > p) res++;
		}
	}
	cout << res << endl;
	return 0;
}