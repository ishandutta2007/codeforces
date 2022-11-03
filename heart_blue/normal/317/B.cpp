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
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int cnt[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	queue<pair<int, int>> q;
	q.push({ 0,0 });
	int t;
	cin >> cnt[0][0] >> t;
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop();
		int &d = cnt[x][y];
		if (d < 4) continue;
		int r = d / 4;
		d %= 4;
		for (int o = 0;o < 4; o++)
		{
			int tx = x + dx[o];
			int ty = y + dy[o];
			if (tx < 0 || ty < 0) continue;
			int delta = r;
			if (x == 1 && tx == 0) delta *= 2;
			if (y == 1 && ty == 0) delta *= 2;
			cnt[tx][ty] += delta;
			if (cnt[tx][ty] >= 4)
				q.push({ tx,ty });
		}
	}
	while (t--)
	{
		int x, y;
		cin >> x >> y;
		x = abs(x);
		y = abs(y);
		if (x < N && y < N) printf("%d\n", cnt[x][y]);
		else puts("0");
	}
	return 0;
}