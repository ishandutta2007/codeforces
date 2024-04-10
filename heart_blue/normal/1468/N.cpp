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
char str[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int c1, c2, c3;
		scanf("%d%d%d", &c1, &c2, &c3);
		int a1, a2, a3, a4, a5;
		scanf("%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5);
		if (a1 > c1 || a2 > c2 || a3 > c3)
		{
			puts("NO");
			continue;
		}
		c1 -= a1, c2 -= a2, c3 -= a3;
		a4 -= min(a4, c1);
		a5 -= min(a5, c2);
		if (a4 + a5 <= c3) puts("YES");
		else puts("NO");
	}
	return 0;
}