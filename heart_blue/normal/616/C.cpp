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
const int N = 1e6 + 10;
const int M = 1e3 + 10;
char board[M][M];
int ans[N];
int flag[M][M];
int ks[N];
int n, m;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int cnt;
void dfs(int x, int y, int key)
{
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= m) return;
	if (board[x][y] == '*') return;
	if (flag[x][y]) return;
	flag[x][y] = key;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dx[i], y + dy[i], key);
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	MEM(flag, 0);
	MEM(ks, 0);
	for (int i = 0; i < n; i++) cin >> board[i];
	int k = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (flag[i][j]) continue;
			if (board[i][j] == '*') continue;
			cnt = 0;
			dfs(i, j, k);
			ans[k++] = cnt;
		}
	}
	k = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != '*') continue;
			k++;
			int res = 1;
			for (int o = 0; o < 4; o++)
			{
				int x = i + dx[o];
				int y = j + dy[o];
				if (x < 0 || x >= n) continue;
				if (y < 0 || y >= m) continue;
				if (board[x][y] == '*') continue;
				int t = flag[x][y];
				if (ks[t] != k)
				{
					ks[t] = k;
					res += ans[t];
				}
			}
			board[i][j] = res % 10 + '0';
		}
	}
	for (int i = 0; i < n; i++) puts(board[i]);
	return 0;
}