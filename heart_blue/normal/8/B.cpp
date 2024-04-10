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
const int N = 1e3 + 10;
int flag[N][N];
int dis[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int a[N];
void init()
{
	a['L'] = 1;
	a['R'] = 0;
	a['U'] = 2;
	a['D'] = 3;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x = 100, y = 100;
	init();
	MEM(flag, 0);
	string str;
	cin >> str;
	flag[x][y] = 1;
	for (auto &c : str)
	{
		int o = a[c];
		x += dx[o];
		y += dy[o];
		flag[x][y] = 1;
	}
	queue<pair<int, int>> q;
	q.push({ 100,100 });
	MEM(dis, 0x1f);
	dis[100][100] = 0;
	while (!q.empty())
	{
		int a, b;
		tie(a, b) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int tx = a + dx[i];
			int ty = b + dy[i];
			if (flag[tx][ty] == 0) continue;
			if (dis[tx][ty] > dis[a][b] + 1)
			{
				dis[tx][ty] = dis[a][b] + 1;
				q.push({ tx,ty });
			}
		}
	}
	if (dis[x][y] < str.length()) puts("BUG");
	else puts("OK");
	return 0;
}