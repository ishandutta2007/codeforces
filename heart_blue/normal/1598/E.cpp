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
#include <random>
#include <chrono>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int flag[N][N];
int n, m;
int getlen(int x, int y, int o)
{
	int cnt = 0;
	while (flag[x][y] == 0 && x >= 1 && x <= n && y >= 1 && y <= m)
	{
		cnt++;
		x += dx[o];
		y += dy[o];
		o ^= 2;
	}
	return cnt;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q;
	scanf("%d%d%d", &n, &m, &q);
	LL ans = n * m;
	for (int j = 2; j <= m; j++)
	{
		int x = 1, y = j;
		int cnt = 1;
		int o = 2;
		while (x <= n && y <= m)
		{
			ans += cnt;
			cnt++;
			x += dx[o];
			y += dy[o];
			o ^= 2;
		}
	}
	for (int j = 2; j <= n; j++)
	{
		int x = j, y = 1;
		int cnt = 1;
		int o = 0;
		while (x <= n && y <= m)
		{
			ans += cnt;
			cnt++;
			x += dx[o];
			y += dy[o];
			o ^= 2;
		}
	}
	while (q--)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		int pre = flag[x][y];
		flag[x][y] = 0;
		int cnt[4];
		for (int i = 0; i < 4; i++)
			cnt[i] = getlen(x, y, i);
		flag[x][y] = pre ^ 1;
		LL tot = 1;
		for (int i = 0; i < 2; i++)
		{
			if (cnt[i] == 0 || cnt[i ^ 3] == 0) continue;
			tot += cnt[i] * cnt[i ^ 3] - 1;
		}
		if (pre == 1)
			ans += tot;
		else
			ans -= tot;
		printf("%lld\n", ans);
	}

	return 0;
}