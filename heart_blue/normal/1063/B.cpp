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
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char str[N][N];
int dis[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	int r, c;
	scanf("%d%d", &n, &m);
	scanf("%d%d", &r, &c);
	int cntleft, cntright;
	scanf("%d%d", &cntleft, &cntright);
	for (int i = 1; i <= n; i++) scanf("%s", str[i] + 1);
	deque<pair<int, int>> q;
	q.emplace_back(r, c);
	MEM(dis, 0x3f);
	dis[r][c] = 0;
	int ans = 0;
	while (!q.empty())
	{
		int x, y;
		tie(x, y) = q.front();
		q.pop_front();
		if (dis[x][y] > cntright) continue;
		if (c + dis[x][y] - y > cntleft) continue;
		ans++;
		for (int o = 0; o < 4; o++)
		{
			int tx = x + dx[o];
			int ty = y + dy[o];
			if (tx < 1 || tx > n) continue;
			if (ty < 1 || ty > m) continue;
			if (str[tx][ty] == '*') continue;
			if (dis[tx][ty] > dis[x][y] + (o == 0))
			{
				dis[tx][ty] = dis[x][y] + (o == 0);
				if (o < 2) q.emplace_back(tx, ty);
				else q.emplace_front(tx, ty);
			}
		}
	}
	cout << ans << endl;
	return 0;
}