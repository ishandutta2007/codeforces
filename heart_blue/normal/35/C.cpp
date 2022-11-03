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
const int N = 2e3 + 10;
int dis[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	MEM(dis, 0x3f);
	int n, m, k;
	cin >> n >> m >> k;
	queue<pair<int, int>> q;
	while (k--)
	{
		int x, y;
		cin >> x >> y;
		q.push({ x,y });
		dis[x][y] = 0;
	}
	pair<int, pair<int, int>> ans = { 0,{1,1} };
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		ans = max(ans, { dis[x][y],{x,y} });
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (tx < 1 || tx > n) continue;
			if (ty < 1 || ty > m) continue;
			if (dis[tx][ty] > dis[x][y] + 1)
			{
				dis[tx][ty] = dis[x][y] + 1;
				q.push({ tx,ty });
			}
		}
	}
	int x, y;
	tie(x, y) = ans.second;
	cout << x << ' ' << y << endl;
	return 0;
}