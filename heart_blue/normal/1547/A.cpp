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
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int ax, ay, bx, by, fx, fy;
		scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &fx, &fy);
		if (ax > bx) swap(ax, bx);
		if (ay > by) swap(ay, by);
		if (fx < ax || fx > bx || fy < ay || fy >by || (bx - ax) * (by - ay) > 0)
		{
			printf("%d\n", abs(ax - bx) + abs(ay - by));
			continue;
		}
		else
		{
			printf("%d\n", abs(ax - bx) + abs(ay - by) + 2);
		}

	}
	return 0;
}