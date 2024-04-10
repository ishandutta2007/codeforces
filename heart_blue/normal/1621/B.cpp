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
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int ncase;
	scanf("%d", &ncase);
	while (ncase--)
	{
		int n;
		scanf("%d", &n);
		int l = INF, r = -INF;
		int flag = 1;
		int cost = 2 * INF;
		int costl = INF, costr = INF;
		while (n--)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			if (a == l && b == r)
			{
				if (c <= cost)
				{
					costl = min(costl, c);
					costr = min(costr, c);
					cost = min(cost, c);
				}
				printf("%d\n", cost);
				continue;
			}
			if (a <= l && b >= r)
			{
				cost = c;
				if (a == l) costl = min(costl, c);
				else costl = c;
				if (b == r) costr = min(costr, c);
				else costr = c;
				printf("%d\n", cost);
				l = min(l, a);
				r = max(r, b);
				continue;
			}
			if (a <= l)
			{
				if (a == l) costl = min(costl, c), cost = min(cost, costl + costr);
				else costl = c, cost = costl + costr;
			}
			if (b >= r)
			{
				if (b == r) costr = min(costr, c), cost = min(cost, costl + costr);
				else costr = c, cost = costl + costr;
			}
			l = min(l, a);
			r = max(r, b);
			printf("%d\n", cost);
		}
	}
	return 0;
}