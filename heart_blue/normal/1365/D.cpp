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
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
char str[N][N];
int flag[N][N];
bool solve()
{
	int n, m;
	scanf("%d%d", &n, &m);
	MEM(str, 0);
	for (int i = 1; i <= n; i++)
		scanf("%s", str[i] + 1);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cnt += str[i][j] == 'G';
			if (str[i][j] != 'B') continue;
			for (int o = 0; o < 4; o++)
			{
				int x = i + dx[o];
				int y = j + dy[o];
				if (str[x][y] == 'B') continue;
				if (str[x][y] == 'G') return false;
				str[x][y] = '#';
			}
		}
	}
	if (cnt == 0) return true;
	if (str[n][m] == '#') return false;
	MEM(flag, 0);
	queue<pair<int, int>> q;
	q.emplace(n, m);
	flag[n][m] = 1;
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		if (str[x][y] == 'G') cnt--;
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 1 || tx > n) continue;
			if (ty < 1 || ty > m) continue;
			if (str[tx][ty] == '#') continue;
			if (str[tx][ty] == 'B') return false;
			if (flag[tx][ty]) continue;
			flag[tx][ty] = 1;
			q.emplace(tx, ty);
		}
	}
	return cnt == 0;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		if (solve()) puts("Yes");
		else puts("No");
	}
	return 0;
}