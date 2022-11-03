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
const int N = 2e5 + 10;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	map<pair<int, int>, int> mc;
	auto check = [&mc](int x1, int y1, int x, int y)
	{
		while (x1 < x) mc[{x1++, y1}] = 1;
		while (x1 > x) mc[{x1--, y1}] = 1;
		while (y1 < y) mc[{x1, y1++}] = 1;
		while (y1 > y) mc[{x1, y1--}] = 1;
		mc[{x, y}] = 1;
	};
	auto sum = [](int x1, int y1, int x2, int y2) -> int
	{
		return abs(x1 - x2) + abs(y1 - y2);
	};
	int minv = INF;
	int kx = -1, ky = -1;
	for (int i = 0; i <= 1000; i++)
	{
		for (int j = 0; j <= 1000; j++)
		{
			int tot = sum(x1, y1, i, j) + sum(x2, y2, i, j) + sum(x3, y3, i, j);
			if (tot < minv)
				minv = tot, kx = i, ky = j;
		}
	}
	check(x1, y1, kx, ky);
	check(x2, y2, kx, ky);
	check(x3, y3, kx, ky);
	printf("%d\n", mc.size());
	for (auto& p : mc)
	{
		printf("%d %d\n", p.first.first, p.first.second);
	}
	return 0;
}