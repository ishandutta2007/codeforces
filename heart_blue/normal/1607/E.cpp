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
const int N = 1e6 + 10;
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int minx = 0;
		int maxx = 0;
		int miny = 0;
		int maxy = 0;
		int x = 0, y = 0;
		int n, m;
		scanf("%d%d", &n, &m);
		scanf("%s", str);
		int ansx = 1, ansy = 1;
		for (int i = 0; str[i]; i++)
		{
			if (str[i] == 'L') y--;
			if (str[i] == 'R') y++;
			if (str[i] == 'U') x--;
			if (str[i] == 'D') x++;
			minx = min(minx, x);
			maxx = max(maxx, x);
			miny = min(miny, y);
			maxy = max(maxy, y);
			if (maxx - minx + 1 > n) break;
			if (maxy - miny + 1 > m) break;
			ansx = -minx + 1;
			ansy = -miny + 1;
		}
		printf("%d %d\n", ansx, ansy);
	}
	return 0;
}