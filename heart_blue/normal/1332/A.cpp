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
const int N = 2e5 + 10;
bool check(int x, int y, int x1, int y1, int x2, int y2)
{
	return x >= x1 && x <= x2 && y >= y1 && y <= y2;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int a, b, c, d;
		int x, y, x1, y1, x2, y2;
		cin >> a >> b >> c >> d;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		if (x1 == x2 && (a + b) > 0)
		{
			puts("NO");
			continue;
		}
		if (y1 == y2 && (c + d) > 0)
		{
			puts("NO");
			continue;
		}
		if (check(x - a + b, y - c + d, x1, y1, x2, y2))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}