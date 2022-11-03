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
const int N = 5e3 + 10;
int flag[N][N];
char board[N][N];
int n, m;
vector<tuple<char, int, int>> vp;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
void dfs(int x, int y, int ox, int oy)
{
	if (x < 0 || x >= n) return;
	if (y < 0 || y >= m) return;
	if (flag[x][y]) return;
	if (board[x][y] == '#') return;
	flag[x][y] = 1;
	vp.push_back({ 'B',x,y });
	for (int i = 0; i < 4; i++)
	{
		dfs(x + dx[i], y + dy[i], ox, oy);
	}
	if (x != ox || y != oy)
	{
		vp.push_back({ 'D',x,y });
		vp.push_back({ 'R',x,y });
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dfs(i, j, i, j);
		}
	}
	printf("%d\n", vp.size());
	for (auto &p : vp)
	{
		char c;
		int x, y;
		tie(c, x, y) = p;
		printf("%c %d %d\n", c, x + 1, y + 1);
	}
	return 0;
}