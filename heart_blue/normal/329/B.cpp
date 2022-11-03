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
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
char c[N][N];
int flag[N][N];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	MEM(c, 'T');
	int n, m;
	cin >> n >> m;
	int ex, ey;
	ex = ey = 0;
	int sx, sy;
	sx = sy = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> c[i][j];
			if (c[i][j] == 'E') ex = i, ey = j;
			if (c[i][j] == 'S') sx = i, sy = j;
		}
	}
	MEM(flag, 0);
	list<pair<int, int>> lp;
	lp.push_back({ ex,ey });
	flag[ex][ey] = 1;
	while (!lp.empty())
	{
		int x, y;
		tie(x, y) = lp.front();
		lp.pop_front();
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if (flag[tx][ty]) continue;
			if (c[tx][ty] == 'T') continue;
			flag[tx][ty] = flag[x][y] + 1;
			lp.push_back({ tx,ty });
		}
	}
	int tot = 0;
	int maxv = flag[sx][sy];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (isdigit(c[i][j]) && flag[i][j] <= maxv && flag[i][j]) tot += c[i][j] - '0';
		}
	}
	cout << tot << endl;
	return 0;
}