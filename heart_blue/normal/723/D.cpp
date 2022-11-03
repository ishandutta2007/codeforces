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
const int N = 1e2 + 10;

char board[N][N];
int flag[N][N];
int cur = 0;
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
vector<pair<int, int>> vp;
int n, m;

int dfs(int x, int y)
{
	if (x < 0 || x > n + 1) return 0;
	if (y < 0 || y > m + 1) return 0;
	if (flag[x][y] >= 0) return 0;
	if (board[x][y] == '*') return 0;
	flag[x][y] = cur;
	int cnt = 1;
	for (int i = 0; i < 4; i++)
	{
		cnt += dfs(x + dx[i], y + dy[i]);
	}
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> board[i][j];
		}
	}
	MEM(flag, -1);
	cur = 0;
	dfs(0, 0);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (flag[i][j] >= 0) continue;
			if (board[i][j] == '*') continue;
			cur++;
			vp.push_back({ dfs(i, j), cur });
		}
	}
	sort(vp.begin(), vp.end());
	map<int, int> mc;
	int ans = 0;
	for (int i = 0; i < cur - k; i++)
	{
		mc[vp[i].second] = 1;
		ans += vp[i].first;
	}
	cout << ans << endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (mc.count(flag[i][j])) putchar('*'), ans++;
			else putchar(board[i][j]);
		}
		puts("");
	}
	return 0;
}