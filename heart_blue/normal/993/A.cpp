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
const int N = 2e2 + 10;
int main()
{
	map<pair<int, int>, int> mc;
	int minx = INF, miny = INF, maxx = -INF, maxy = -INF;
	for (int i = 0; i < 4; i++)
	{
		int x, y;
		cin >> x >> y;
		x *= 2, y *= 2;
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
	}
	for (int i = minx; i <= maxx; i++)
	{
		for (int j = miny; j <= maxy; j++)
		{
			mc[{i, j}] = 1;
		}
	}
	minx = INF, miny = INF, maxx = -INF, maxy = -INF;
	for (int i = 0; i < 4; i++)
	{
		int x, y;
		cin >> x >> y;
		x *= 2, y *= 2;
		minx = min(minx, x);
		miny = min(miny, y);
		maxx = max(maxx, x);
		maxy = max(maxy, y);
	}
	int ox = (maxx + minx) / 2, oy = (maxy + miny) / 2;
	for (int i = 0; i <= (maxy - miny) / 2; i++)
	{
		for (int j = -i; j <= i; j++)
		{
			int x = ox + j;
			if (mc.count({ x,miny + i }))
			{
				puts("YES");
				return 0;
			}
			if (mc.count({ x,maxy - i }))
			{
				puts("YES");
				return 0;
			}
		}
	}
	puts("NO");
	return 0;
}