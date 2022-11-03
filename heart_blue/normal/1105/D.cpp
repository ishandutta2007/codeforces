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
const int N = 1e3 + 10;
char str[N][N];
int flag[N][N];
int dis[N][N];
int cnt[10];
int s[10];
int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
queue<pair<int, int>> q[10];
int solve(queue<pair<int, int>>& q, int step, int c)
{
	if (q.empty()) return 0;
	int tot = 0;
	if (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		tot = dis[x][y] + step;
	}
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		if (dis[x][y] == tot) break;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (str[tx][ty] != '.') continue;
			if (flag[tx][ty]) continue;
			dis[tx][ty] = dis[x][y] + 1;
			flag[tx][ty] = c;
			q.emplace(tx, ty);
		}
	}
	return 1;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= k; i++)
		scanf("%d", &s[i]);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i] + 1);
		for (int j = 1; j <= m; j++)
		{
			if (isdigit(str[i][j]))
			{
				q[str[i][j] - '0'].emplace(i, j);
				flag[i][j] = str[i][j] - '0';
			}
		}
	}
	while (1)
	{
		int flag = 0;
		for (int i = 1; i <= k; i++)
			flag |= solve(q[i], s[i], i);
		if (flag == 0) break;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cnt[flag[i][j]]++;
	}
	for (int i = 1; i <= k; i++)
		printf("%d ", cnt[i]);
	return 0;
}