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
const int N = 2e3 + 10;
int n, m;
int deg[N*N];
vector<int> v[N*N];
char board[N][N];
int dx[] = { 0,1 };
int dy[] = { 1,0 };
int getid(int x, int y)
{
	if (x < 0 || y < 0) return -1;
	if (x >= n || y >= m) return -1;
	if (board[x][y] == '*') return -1;
	return x*m + y;
}
pair<int, int> getpos(int id)
{
	return { id / m,id%m };
}
int getsize(int x)
{
	int ret = 0;
	for (auto &y : v[x])
	{
		if (deg[y] > 0) ret++;
	}
	return ret;
}
void refrain(int x)
{
	int ret = 0;
	for (auto &y : v[x])
	{
		deg[y]--;
	}
}
void redraw(pair<int, int> &p, char c)
{
	int x, y;
	tie(x, y) = p;
	board[x][y] = c;
}
void draw(int o1, int o2)
{
	auto p1 = getpos(o1);
	auto p2 = getpos(o2);
	if (p1 > p2) swap(p1, p2);
	if (p1.first == p2.first) redraw(p1, '<'), redraw(p2, '>');
	else redraw(p1, '^'), redraw(p2, 'v');
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> board[i];
	int tot = 0;
	queue<int> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == '.')
			{
				tot++;
				int o1 = getid(i, j);
				for (int k = 0; k < 2; k++)
				{
					int o2 = getid(i + dx[k], j + dy[k]);
					if (o2 == -1) continue;
					v[o1].push_back(o2);
					v[o2].push_back(o1);
					deg[o1]++;
					deg[o2]++;
				}
				if (deg[o1] == 1)
				{
					q.push(o1);
				}
			}
		}
	}
	int sum = 0;
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		int y = -1;
		for (auto &t : v[x])
		{
			if (deg[t] > 0)
			{
				y = t;
				break;
			}
		}
		if (y == -1) continue;
		sum++;
		draw(x, y);
		refrain(x);
		refrain(y);
		deg[x] = 0, deg[y] = 0;
		for (auto &t : v[y])
		{
			if (deg[t] == 1)
			{
				q.push(t);
			}
		}
	}
	if (sum * 2 != tot)
	{
		puts("Not unique");
	}
	else
	{
		for (int i = 0; i < n; i++) puts(board[i]);
	}
	return 0;
}